/*
 * mysql_DAO_calsses.hpp
 *
 *  Created on: Feb 24, 2012
 *      Author: Administrator
 */

#ifndef __MYSQL_DAO_CALSSES_HPP__
#define __MYSQL_DAO_CALSSES_HPP__

#include <sstream>
#include <typeinfo>
#include <cstdio>
#include "dao_interfaces.hpp"
#include "transfer_classes.hpp"
#include "dao_exception.hpp"

using namespace std;

static const char* conditions_map[] = {"=", "<", "<=", ">", ">="};

template <typename ValueType, typename RecordType>
class MysqlRationalDAO: public RationalDAO<ValueType, RecordType> {
public:
	MysqlRationalDAO(DBConnection& conn): RationalDAO<ValueType, RecordType>(conn) {}

	void insertRec(ValueType &rec);

	void deleteRec(ValueType &rec);

	void updateRec(ValueType &rec);

	list<RecordType>* selectRecs(const string &select_stmt);

	void destroyResultList(list<RecordType> *result_list);

private:
//	void genStmtBody(ValueType &rec, ostringstream &oss_field_names, ostringstream &oss_field_values);
	void genStmtCondition(ValueType &rec, ostringstream &oss_conditions);
	void genBinaryValue(const Array &a, string &output);
};

template <typename ValueType, typename RecordType>
void MysqlRationalDAO<ValueType, RecordType>::genBinaryValue(const Array &a, string &output)
{
	output = "0x";
	char *temp = (char *)malloc(a.size()*2+1);
	temp[a.size()*2] = '\0';

	for (size_t i = 0; i < a.size(); ++i) {
		sprintf(temp+i*2, "%02X", a[i].get_int() );
	}

	output += temp;

	free(temp);
}

template <typename ValueType, typename RecordType>
void MysqlRationalDAO<ValueType, RecordType>::genStmtCondition(ValueType &rec, \
		ostringstream &oss_conditions)
{
	vector<pair<string, pair<pair<Value, int>, int> > >::iterator vec_it;
	vector<pair<string, pair<pair<Value, int>, int> > >::iterator end = rec.conditions.end();

	oss_conditions << "WHERE ";
	for (vec_it = rec.conditions.begin(); vec_it != end; ++vec_it) {
		string hex_str;

		switch (vec_it->second.first.second) {
		case string_field_type:
			oss_conditions << vec_it->first << conditions_map[vec_it->second.second] \
						   << "'" << vec_it->second.first.first.get_str() << "'";
			break;

		case char_field_type:
		case ushort_field_type:
		case int_field_type:
			oss_conditions << vec_it->first << conditions_map[vec_it->second.second] \
						   << vec_it->second.first.first.get_int();
			break;

		case uint_field_type:
			oss_conditions << vec_it->first << conditions_map[vec_it->second.second] \
						   << vec_it->second.first.first.get_int64();
			break;

		case ubigint_field_type:
			oss_conditions << vec_it->first << conditions_map[vec_it->second.second] \
						   << vec_it->second.first.first.get_uint64();
			break;

		case bool_field_type:
			oss_conditions << vec_it->first << conditions_map[vec_it->second.second] \
						   << vec_it->second.first.first.get_bool();
			break;

		case real_field_type:
			oss_conditions << vec_it->first << conditions_map[vec_it->second.second] \
						   << vec_it->second.first.first.get_real();
			break;

		case binary_field_type:
			genBinaryValue(vec_it->second.first.first.get_array(), hex_str);
			oss_conditions << vec_it->first << conditions_map[vec_it->second.second] \
						   << hex_str;
			break;

		default:
			GEN_EXCEPTION(DaoError::VALUE_BOUND_ERROR, "");
			break;
		}

		oss_conditions << ( (++vec_it == end) ? "" : " and ");
		--vec_it;
	}
}

template <typename ValueType, typename RecordType>
void MysqlRationalDAO<ValueType, RecordType>::insertRec(ValueType &rec)
{
	map<string, pair<Value, int> >::iterator map_it;
	map<string, pair<Value, int> >::iterator end = rec.changed_fields.end();
	ostringstream oss_field_names, oss_field_values, oss_stmt;

	oss_field_names << "(";
	oss_field_values << "(";
	for (map_it = rec.changed_fields.begin(); map_it != end; ++map_it) {
		string hex_str;

		oss_field_names << map_it->first;
		oss_field_names << ( (++map_it == end) ? "" : ", ");
		--map_it;

		switch (map_it->second.second) {
		case string_field_type:
			oss_field_values << "'" << map_it->second.first.get_str();
			oss_field_values << ( (++map_it == end) ? "'" : "', ");
			--map_it;
			continue;

		case char_field_type:
		case ushort_field_type:
		case int_field_type:
			oss_field_values << map_it->second.first.get_int();
			break;

		case uint_field_type:
			oss_field_values << map_it->second.first.get_int64();
			break;

		case ubigint_field_type:
			oss_field_values << map_it->second.first.get_uint64();
			break;

		case bool_field_type:
			oss_field_values << map_it->second.first.get_bool();
			break;

		case real_field_type:
			oss_field_values << map_it->second.first.get_real();
			break;

		case binary_field_type:
			genBinaryValue(map_it->second.first.get_array(), hex_str);
			oss_field_values << hex_str;
			break;

		default: // error, throw exception
			//++map_it;
			GEN_EXCEPTION(DaoError::VALUE_BOUND_ERROR, "");
			break;
		}

		oss_field_values << ( (++map_it == end) ? "" : ", ");
		--map_it;
	}
	oss_field_names << ")";
	oss_field_values << ")";

	oss_stmt << "INSERT INTO " << rec.table_name << " " << oss_field_names.str() \
			 << " VALUES" << oss_field_values.str() << ";";

	cout << "insert statement is: " << oss_stmt.str() << endl;

	try {
		RationalDAO<ValueType, RecordType>::stmt.execute(oss_stmt.str() );
	} catch (odbcpp::odbcpp_error &err) {
		GEN_ODBC_EXCEPTION(err, DaoError::ODBC_ERROR);
	}

	return ;
}

template <typename ValueType, typename RecordType>
void MysqlRationalDAO<ValueType, RecordType>::deleteRec(ValueType &rec)
{
	ostringstream oss_conditions, oss_stmt;
	genStmtCondition(rec, oss_conditions);

	oss_stmt << "DELETE FROM " << rec.table_name << " " << oss_conditions.str() << ";";

	cout << "Delete statement: " << oss_stmt.str() << endl;

	try {
		RationalDAO<ValueType, RecordType>::stmt.execute(oss_stmt.str() );
	} catch (odbcpp::odbcpp_error &err) {
		GEN_ODBC_EXCEPTION(err, DaoError::ODBC_ERROR);
	}

	return ;
}

template <typename ValueType, typename RecordType>
void MysqlRationalDAO<ValueType, RecordType>::updateRec(ValueType &rec)
{
	ostringstream oss_body, oss_conditions, oss_stmt;
	map<string, pair<Value, int> >::iterator map_it;
	map<string, pair<Value, int> >::iterator end = rec.changed_fields.end();

	oss_body << "UPDATE " << rec.table_name << " SET ";

	for (map_it = rec.changed_fields.begin(); map_it != end; ++map_it) {
		string hex_str;

		switch (map_it->second.second) {
		case string_field_type:
			oss_body << map_it->first << "=" << "'" << map_it->second.first.get_str();
			oss_body << ( (++map_it == end) ? "'" : "', ");
			--map_it;
			continue;

		case char_field_type:
		case ushort_field_type:
		case int_field_type:
			oss_body << map_it->first << "=" << map_it->second.first.get_int();
			break;

		case uint_field_type:
			oss_body << map_it->first << "=" << map_it->second.first.get_int64();
			break;

		case ubigint_field_type:
			oss_body << map_it->first << "=" << map_it->second.first.get_uint64();
			break;

		case bool_field_type:
			oss_body << map_it->first << "=" << map_it->second.first.get_bool();
			break;

		case real_field_type:
			oss_body << map_it->first << "=" << map_it->second.first.get_real();
			break;

		case binary_field_type:
			genBinaryValue(map_it->second.first.get_array(), hex_str);
			oss_body << map_it->first << "=" << hex_str;
			break;

		default:
			//++map_it;
			GEN_EXCEPTION(DaoError::VALUE_BOUND_ERROR, "");
			break;
		}

		oss_body << ( (++map_it == end) ? "" : ", ");
		--map_it;
	}

	genStmtCondition(rec, oss_conditions);
	oss_stmt << oss_body.str() << " " << oss_conditions.str() << ";";

	cout << "update statement is: " << oss_stmt.str() << endl;

	try {
		RationalDAO<ValueType, RecordType>::stmt.execute(oss_stmt.str() );
	} catch (odbcpp::odbcpp_error &err) {
		GEN_ODBC_EXCEPTION(err, DaoError::ODBC_ERROR);
	}

	return ;
}

template <typename ValueType, typename RecordType>
list<RecordType>* MysqlRationalDAO<ValueType, RecordType>::selectRecs(const string &select_stmt)
{
	list<RecordType>* plist = new list<RecordType>;

	try {
		RationalDAO<ValueType, RecordType>::stmt.execute(select_stmt);

		while (RationalDAO<ValueType, RecordType>::stmt.fetch(*RationalDAO<ValueType, RecordType>::value) ) {
			try {
				RecordType& rec = dynamic_cast<RecordType&>(RationalDAO<ValueType, RecordType>::value->getRec() );
				plist->push_back(rec);
			} catch (std::bad_cast err) {
				GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
			}
		}

		RationalDAO<ValueType, RecordType>::stmt.close_cursor();
	} catch(odbcpp::odbcpp_error &err) {
		GEN_ODBC_EXCEPTION(err, DaoError::ODBC_ERROR);
	}

	return plist;
}

template <typename ValueType, typename RecordType>
void MysqlRationalDAO<ValueType, RecordType>::destroyResultList(list<RecordType> *result_list)
{
	delete result_list;
}

#endif /* __MYSQL_DAO_CALSSES_HPP__ */

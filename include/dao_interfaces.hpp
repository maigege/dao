/*
 * DAO_interfaces.hpp
 *
 *  Created on: Feb 24, 2012
 *      Author: Administrator
 */

#ifndef __DAO_INTERFACES_HPP__
#define __DAO_INTERFACES_HPP__

#include <list>
#include "dao_types.hpp"

template <typename ValueType, typename RecordType>
class RationalDAO {
public:
	RationalDAO(DBConnection& conn): stmt(conn)
	{
		value = new ValueType;
		value->initRecord();
		value->bindRecord();
	}

	virtual ~RationalDAO(void) { delete value; }

	virtual void insertRec(ValueType &rec) = 0;

	virtual void deleteRec(ValueType &rec) = 0;

	virtual void updateRec(ValueType &rec) = 0;

	virtual list<RecordType>* selectRecs(const string &select_stmt) = 0;

	virtual void destroyResultList(list<RecordType> *result_list) = 0;

protected:
	DBStatement stmt;
	ValueType *value;
};

#endif /* __DAO_INTERFACES_HPP__ */

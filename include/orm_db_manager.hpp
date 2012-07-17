/*
 * orm_db_manager.hpp
 *
 *  Created on: Mar 12, 2012
 *      Author: Administrator
 */

#ifndef __ORM_DB_MANAGER_HPP__
#define __ORM_DB_MANAGER_HPP__

#include "dao_types.hpp"
#include "dao_factory.hpp"

class BaseOrmDbManager {
public:
	static const int MYSQL = 1;

public:
	static DBConnection* getConnection(const char *datasource, const char *user, const char *passwd)
	{
		DBConnection *conn_obj = NULL;
		try {
			conn_obj = new DBConnection(odbc_env);
			conn_obj->connect(datasource, user, passwd);
		} catch (odbcpp::odbcpp_error &err) {
			GEN_ODBC_EXCEPTION(err, DaoError::ODBC_ERROR);
		}

		return conn_obj;
	}

	static void destroyConnection(DBConnection *connection)
	{
		delete connection;
	}

private:
	static odbcpp::environment odbc_env;
};

template <typename ValueType, typename RecordType>
class OrmDbManager: public BaseOrmDbManager {
public:
	static DAOFactory<ValueType, RecordType>* getDAOFactory(int which_factory)
	{
		switch (which_factory)
		{
		case MYSQL:
			return new MysqlDAOFactory<ValueType, RecordType>();
			break;

		default:
			return new MysqlDAOFactory<ValueType, RecordType>();
		}
	}

	static RationalDAO<ValueType, RecordType>* getDAOInstance(DAOFactory<ValueType, RecordType>* factory, DBConnection& connection)
	{
		return factory->getDAOInstance(connection);
	}

	static void destroyDAOInstance(RationalDAO<ValueType, RecordType> *instance)
	{
		delete instance;
	}

	static void destroyDAOFactory(DAOFactory<ValueType, RecordType> *factory)
	{
		delete factory;
	}
};

#endif /* __ORM_DB_MANAGER_HPP__ */

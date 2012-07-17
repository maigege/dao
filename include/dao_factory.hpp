/*
 * DAO_factory.hpp
 *
 *  Created on: Feb 24, 2012
 *      Author: Administrator
 */

#ifndef __DAO_FACTORY_HPP__
#define __DAO_FACTORY_HPP__

#include "dao_interfaces.hpp"
#include "mysql_dao_classes.hpp"

template <typename ValueType, typename RecordType>
class DAOFactory {
public:
	virtual ~DAOFactory(void) {}

	virtual RationalDAO<ValueType, RecordType>* getDAOInstance(DBConnection& connection) = 0;
};

template <typename ValueType, typename RecordType>
class MysqlDAOFactory: public DAOFactory<ValueType, RecordType> {
public:
	RationalDAO<ValueType, RecordType>* getDAOInstance(DBConnection& connection)
	{
		return new MysqlRationalDAO<ValueType, RecordType>(connection);
	}
};

#endif /* __DAO_FACTORY_HPP__ */

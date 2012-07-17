/*
 * main.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: Administrator
 */

#include "../include/dao_factory.hpp"
#include "../include/transfer_classes.hpp"
#include "../include/mysql_dao_classes.hpp"
#include "../include/orm_db_manager.hpp"
#include "../include/dao_exception.hpp"

#if defined(EXECUTABLE)
int main(int argc, char **argv)
{
//	int exit_code = 0;

	if (argc < 4) {
		cerr << "usage: " << argv[0] << ": [dsn] [user] [password]" << endl;
		return (-1);
	}

	DBConnection *connection = NULL;
	try {
		connection = BaseOrmDbManager::getConnection(argv[1], argv[2], argv[3]);
	} catch(DaoError& err) {
		cerr << err.what() << endl;
		return (-1);
	}
	if (connection == NULL) {
		cerr << "Error occured!!!" << endl;
		return (-1);
	}

	DAOFactory<HostOnlineHistoryValue, HostOnlineHistoryRecord> *factory = OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::getDAOFactory(BaseOrmDbManager::MYSQL);
	RationalDAO<HostOnlineHistoryValue, HostOnlineHistoryRecord> *host_dao = OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::getDAOInstance(factory, *connection);

	// insert record into database
	HostOnlineHistoryValue val;
	val.setHostName("localhost");
	uint8_t mac[] = {0xDE, 0x7E, 0x67, 0xB4, 0x3D, 0x56};
	val.setMac(mac);
	val.setOnlineTime(1324881154u);
	val.setOfflineTime(1324882170u);
	val.setIpType(1);
	uint8_t ip[] = {0x7B, 0x6E, 0xD4, 0x43, 0x7F, 0x9D, 0x3A, 0x5B, 0x7B, 0x6E, 0xD4, 0x43, 0x7F, 0x9D, 0x3A, 0x5B};
	val.setIp(ip);
	val.setVlanId("12101");
	val.setPlaceId("44030521388919");

	try {
		host_dao->insertRec(val);
	} catch (DaoError& err) {
		cerr << err.what() << endl;
		OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOInstance(host_dao);
		OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOFactory(factory);
		BaseOrmDbManager::destroyConnection(connection);

		return (-1);
	}

	// retrieve data from database
	list<HostOnlineHistoryRecord> *result_list = NULL;
	try {
		result_list = host_dao->selectRecs("select * from HOST_ONLINE_HISTORY_RECORD;");
	} catch (DaoError& err) {
		cerr << err.what() << endl;
		OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOInstance(host_dao);
		OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOFactory(factory);
		BaseOrmDbManager::destroyConnection(connection);

		return (-1);
	}
	if (result_list == NULL) {
		cerr << "Retrieve error!!" << endl;
		OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOInstance(host_dao);
		OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOFactory(factory);
		BaseOrmDbManager::destroyConnection(connection);

		return (-1);
	}
	list<HostOnlineHistoryRecord>::iterator it;
	list<HostOnlineHistoryRecord>::iterator end = result_list->end();
	for (it = result_list->begin(); it != end; ++it) {
		cout << it->id << ": " << it->host_name << ": " << it->vlan_id << endl;
	}

	// update record
	HostOnlineHistoryValue update_val;
	update_val.setConditionId(result_list->begin()->id, euqal);
	uint8_t update_mac[] = {0xE4, 0x6E, 0x57, 0xB3, 0x4A, 0x5E};
	update_val.setMac(update_mac);
	update_val.setVlanId("suntang01");

	try {
		host_dao->updateRec(update_val);
	} catch (DaoError& err) {
		cerr << err.what() << endl;
		OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOInstance(host_dao);
		OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOFactory(factory);
		BaseOrmDbManager::destroyConnection(connection);

		return (-1);
	}

	// delete record
	HostOnlineHistoryValue delete_val;
	delete_val.setConditionId(result_list->begin()->id, euqal);
	try {
		host_dao->deleteRec(delete_val);
	} catch (DaoError& err) {
		cerr << err.what() << endl;
		OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOInstance(host_dao);
		OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOFactory(factory);
		BaseOrmDbManager::destroyConnection(connection);

		return (-1);
	}

	// destroy allocated objects
	host_dao->destroyResultList(result_list);
	OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOInstance(host_dao);
	OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOFactory(factory);
	BaseOrmDbManager::destroyConnection(connection);

	return 0;
}
#endif

#ifndef TEST_transfer_classesTest
#define TEST_transfer_classesTest

#ifdef ECUT_MAIN

#include "../include/dao.hpp"
#include "cppunit/extensions/HelperMacros.h"

class transfer_classesTest : public CPPUNIT_NS::TestFixture {
public:
	void setUp(void);
	void tearDown(void);
	void testHostOnlineHistoryDao(void);
	void testMasterNetworkAccountDao(void);
	void testServerInfoDao(void);
	void testAppLayerSessionDao(void);
	void testLoginOrLogoffDao(void);
	void testSubscribingDao(void);
	void testBrowsingDao(void);
	void testStreamMediaDao(void);
	void testSearchingDao(void);
	void testPostDao(void);
	void testDataTransmissionDao(void);
	void testTransmissedFileDao(void);
	void testGameDao(void);
	void testUtilityAppDao(void);
	void testBusinessAppDao(void);
	void testImChatDao(void);
	void testEmailDao(void);
	void testChatRoomDao(void);
	void testSlaveNetworkAccountDao(void);
	void testAttachedFileDao(void);
	CPPUNIT_TEST_SUITE(transfer_classesTest);
	CPPUNIT_TEST(testHostOnlineHistoryDao);
	CPPUNIT_TEST(testMasterNetworkAccountDao);
	CPPUNIT_TEST(testServerInfoDao);
	CPPUNIT_TEST(testAppLayerSessionDao);
	CPPUNIT_TEST(testLoginOrLogoffDao);
	CPPUNIT_TEST(testSubscribingDao);
	CPPUNIT_TEST(testBrowsingDao);
	CPPUNIT_TEST(testStreamMediaDao);
	CPPUNIT_TEST(testSearchingDao);
	CPPUNIT_TEST(testPostDao);
	CPPUNIT_TEST(testDataTransmissionDao);
	CPPUNIT_TEST(testTransmissedFileDao);
	CPPUNIT_TEST(testGameDao);
	CPPUNIT_TEST(testUtilityAppDao);
	CPPUNIT_TEST(testBusinessAppDao);
	CPPUNIT_TEST(testImChatDao);
	CPPUNIT_TEST(testEmailDao);
	CPPUNIT_TEST(testChatRoomDao);
	CPPUNIT_TEST(testSlaveNetworkAccountDao);
	CPPUNIT_TEST(testAttachedFileDao);
	CPPUNIT_TEST_SUITE_END();

private:
	HostOnlineHistoryValue host_online_val;
	MasterNetworkAccountValue master_account_val;
	ServerInfoValue server_info_val;
	AppLayerSessionValue app_session_val;
	LoginOrLogoffActionValue log_val;
	SubscribingActionValue subscribe_val;
	BrowsingActionValue browse_val;
	StreamMediaActionValue stream_media_val;
	SearchingActionValue search_val;
	PostActionValue post_val;
	DataTransmissionActionValue data_trans_val;
	TransmissedFileValue tans_file_val;
	GameActionValue game_val;
	UtilityAppActionValue utility_val;
	BusinessAppActionValue business_val;
	ImChatActionValue im_val;
	EmailActionValue email_val;
	ChatRoomActionValue chat_room_val;
	SlaveNetworkAccountValue slave_account_val;
	AttachedFileValue attached_file_value;

	DBConnection *connection;

	DAOFactory<HostOnlineHistoryValue, HostOnlineHistoryRecord> *host_online_factory;
	DAOFactory<MasterNetworkAccountValue, MasterNetworkAccount> *master_network_factory;
	DAOFactory<ServerInfoValue, ServerInfo> *server_info_factory;
	DAOFactory<AppLayerSessionValue, AppLayerSession> *app_session_factory;
	DAOFactory<LoginOrLogoffActionValue, LoginOrLogoffAction> *log_factory;
	DAOFactory<SubscribingActionValue, SubscribingAction> *subscribe_factory;
	DAOFactory<BrowsingActionValue, BrowsingAction> *browse_factory;
	DAOFactory<StreamMediaActionValue, StreamMediaAction> *stream_media_factory;
	DAOFactory<SearchingActionValue, SearchingAction> *search_factory;
	DAOFactory<PostActionValue, PostAction> *post_factory;
	DAOFactory<DataTransmissionActionValue, DataTransmissionAction> *data_trans_factory;
	DAOFactory<TransmissedFileValue, TransmissedFile> *transmiss_factory;
	DAOFactory<GameActionValue, GameAction> *game_factory;
	DAOFactory<UtilityAppActionValue, UtilityAppAction> *utility_factory;
	DAOFactory<BusinessAppActionValue, BusinessAppAction> *business_factory;
	DAOFactory<ImChatActionValue, ImChatAction> *im_factory;
	DAOFactory<EmailActionValue, EmailAction> *email_factory;
	DAOFactory<ChatRoomActionValue, ChatRoomAction> *chat_room_factory;
	DAOFactory<SlaveNetworkAccountValue, SlaveNetworkAccount> *slave_account_factory;
	DAOFactory<AttachedFileValue, AttachedFile> *attached_file_factory;

	RationalDAO<HostOnlineHistoryValue, HostOnlineHistoryRecord> *host_online_dao;
	RationalDAO<MasterNetworkAccountValue, MasterNetworkAccount> *master_network_dao;
	RationalDAO<ServerInfoValue, ServerInfo> *server_info_dao;
	RationalDAO<AppLayerSessionValue, AppLayerSession> *app_session_dao;
	RationalDAO<LoginOrLogoffActionValue, LoginOrLogoffAction> *log_dao;
	RationalDAO<SubscribingActionValue, SubscribingAction> *subscribe_dao;
	RationalDAO<BrowsingActionValue, BrowsingAction> *browse_dao;
	RationalDAO<StreamMediaActionValue, StreamMediaAction> *stream_media_dao;
	RationalDAO<SearchingActionValue, SearchingAction> *search_dao;
	RationalDAO<PostActionValue, PostAction> *post_dao;
	RationalDAO<DataTransmissionActionValue, DataTransmissionAction> *data_trans_dao;
	RationalDAO<TransmissedFileValue, TransmissedFile> *transmiss_dao;
	RationalDAO<GameActionValue, GameAction> *game_dao;
	RationalDAO<UtilityAppActionValue, UtilityAppAction> *utility_dao;
	RationalDAO<BusinessAppActionValue, BusinessAppAction> *business_dao;
	RationalDAO<ImChatActionValue, ImChatAction> *im_dao;
	RationalDAO<EmailActionValue, EmailAction> *email_dao;
	RationalDAO<ChatRoomActionValue, ChatRoomAction> *chat_room_dao;
	RationalDAO<SlaveNetworkAccountValue, SlaveNetworkAccount> *slave_account_dao;
	RationalDAO<AttachedFileValue, AttachedFile> *attached_file_dao;
};

#endif /* ECUT_MAIN */

#endif /*TRANSFER_CLASSESTEST*/

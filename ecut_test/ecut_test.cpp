
#ifdef ECUT_MAIN
#include <cstring>
#include "ecut_test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(transfer_classesTest);


void transfer_classesTest::setUp(void)
{
	host_online_val.setHostName("localhost");
	uint8_t mac[6] = {0xDE, 0x7E, 0x67, 0xB4, 0x3D, 0x56};
	host_online_val.setMac(mac);
	host_online_val.setOnlineTime(1324881154u);
	host_online_val.setOfflineTime(1324882170u);
	host_online_val.setIpType(1);
	uint8_t ip[] = {0x7B, 0x6E, 0xD4, 0x43, 0x7F, 0x9D, 0x3A, 0x5B, 0x7B, 0x6E, 0xD4, 0x43, 0x7F, 0x9D, 0x3A, 0x5B};
	host_online_val.setIp(ip);
	host_online_val.setVlanId("suntang02");
	host_online_val.setPlaceId("44030521388919");

	master_account_val.setAccountType(NetworkAccount::ACCOUNT_MAIL);
	master_account_val.setIsAnonymous(false);
	master_account_val.setAccountId("GoLakers!");
	master_account_val.setPassword("root123");
	master_account_val.setNickName("kb24");
	master_account_val.setFristIdentify(1324881160u);
	master_account_val.setServiceProvider(3u);

	server_info_val.setServiceUrl("\\\\index.html");
	server_info_val.setDomainName("gmail.com");
	server_info_val.setServiceIpType(1);
	uint8_t server_ip[] = {0xE5, 0x5A, 0x35, 0x43, 0x7F, 0x9D, 0x3A, 0x5B, 0x7B, 0x6E, 0xD4, 0x43, 0x7F, 0x9D, 0x3A, 0x5B};
	server_info_val.setServerIp(server_ip);
	server_info_val.setServicePort(80);
	uint8_t server_mac[6] = {0x4D, 0x7E, 0x67, 0xB4, 0x9A, 0xD7};
	server_info_val.setServerMac(server_mac);

	app_session_val.setProtocolType(0x03);
	app_session_val.setStartTime(1324881160u);
	app_session_val.setEndTime(1324881225u);
	app_session_val.setHostId(1ull);
	app_session_val.setServerInfoId(1ull);
	app_session_val.setAccountId(1ull);

	log_val.setActionType(AppLayerAction::ACTION_LOGIN_OR_LOGOFF);
	log_val.setOccurTime(1324881160u);
	log_val.setProtocolType(0x03);
	log_val.setClientPort(4567);
	log_val.setDirection(0);
	log_val.setLoginTime(1324881161u);
	log_val.setLogoutTime(1324881261u);
	log_val.setAppSessionId(1ull);

	subscribe_val.setActionType(AppLayerAction::ACTION_SUBSCRIBING);
	subscribe_val.setOccurTime(1324881162u);
	subscribe_val.setProtocolType(0x03);
	subscribe_val.setClientPort(5677);
	subscribe_val.setCachePath("D:\\\\Program Files\\\\cache\\\\");
	subscribe_val.setRequestUrl("\\\\subscribe.html");
	subscribe_val.setSubscribeType(SubscribingAction::SUBSCRIBE_WEIBO);
	subscribe_val.setSubject("Thunder over Heat in Finals game 1");
	subscribe_val.setAppSessionId(1ull);

	browse_val.setActionType(AppLayerAction::ACTION_SUBSCRIBING);
	browse_val.setOccurTime(1324881168u);
	browse_val.setProtocolType(0x03);
	browse_val.setClientPort(5000);
	browse_val.setCachePath("D:\\\\Program Files\\\\cache\\\\");
	browse_val.setRequestUrl("\\\\browse.html");
	browse_val.setRequestMethod("GET");
	browse_val.setRequestPort(80);
	browse_val.setResponseType(0x06);
	browse_val.setSubject("Go, Lakers!");
	browse_val.setBrowserVersion("FireFox 12.0");
	browse_val.setAppSessionId(1ull);

	stream_media_val.setActionType(AppLayerAction::ACTION_STREAM_MEDIA);
	stream_media_val.setOccurTime(1324881171u);
	stream_media_val.setProtocolType(0x03);
	stream_media_val.setClientPort(5012);
	stream_media_val.setCachePath("D:\\\\Program Files\\\\cache\\\\");
	stream_media_val.setRequestUrl("\\\\media.html");
	stream_media_val.setStreamMediaType(StreamMediaAction::STREAM_MEDIA_RTSP);
	stream_media_val.setLoginStatus(1);
	stream_media_val.setAppSessionId(1ull);

	search_val.setActionType(AppLayerAction::ACTION_SEARCHING);
	search_val.setOccurTime(1324881173u);
	search_val.setProtocolType(0x03);
	search_val.setClientPort(6034);
	search_val.setCachePath("D:\\\\Program Files\\\\cache\\\\");
	search_val.setRequestUrl("\\\\search.html");
	search_val.setKeyword("Kobe");
	search_val.setSearchType(SearchingAction::SEARCH_BAIKE);
	search_val.setServiceProvider(2u);
	search_val.setAppSessionId(1ull);

	post_val.setActionType(AppLayerAction::ACTION_POST);
	post_val.setOccurTime(1324881183u);
	post_val.setProtocolType(0x03);
	post_val.setClientPort(6234);
	post_val.setCachePath("D:\\\\Program Files\\\\cache\\\\");
	post_val.setRequestUrl("\\\\post.html");
	post_val.setRequestMethod("GET");
	post_val.setRequestPort(80);
	post_val.setSessionId("SESSION_1234");
	post_val.setPostType(PostAction::POST_BLOG_POST);
	post_val.setSubject("yes!!!");
	post_val.setContent("What a play by no.24!!!");
	post_val.setAuthor("Justin");
	post_val.setServiceProvider(1u);
	post_val.setReferenceContent("Thunder lost game4!!!");
	post_val.setAppSessionId(1ull);

	data_trans_val.setActionType(AppLayerAction::ACTION_DATA_TRANSMISSION);
	data_trans_val.setOccurTime(1324881183u);
	data_trans_val.setProtocolType(0x03);
	data_trans_val.setClientPort(6255);
	data_trans_val.setCachePath("D:\\\\Program Files\\\\cache\\\\");
	data_trans_val.setTransmissionType(DataTransmissionAction::TRANSMISSION_P2P);
	data_trans_val.setCommand("");
	data_trans_val.setAppSessionId(1ull);
	data_trans_val.setUtilitySessionId(1ull);

	tans_file_val.setFileName("champ.doc");
	tans_file_val.setFileSize(3455u);
	tans_file_val.setFilePath("D:\\\\Program Files\\\\download\\\\");
	tans_file_val.setTransActionId(1ull);

	game_val.setActionType(AppLayerAction::ACTION_GAME);
	game_val.setOccurTime(1324881183u);
	game_val.setProtocolType(0x03);
	game_val.setClientPort(7000);
	game_val.setCachePath("D:\\\\Program Files\\\\cache\\\\");
	game_val.setGameType(GameAction::GAME_DNF);
	game_val.setOnlineStatus(1);
	game_val.setSendAcct("yoyo12");
	game_val.setAcceptAcct("just1");
	game_val.setChatContent("attack it!!!");
	game_val.setAppSessionId(1ull);

	utility_val.setActionType(AppLayerAction::ACTION_UTILITY);
	utility_val.setOccurTime(1324881183u);
	utility_val.setProtocolType(0x03);
	utility_val.setClientPort(3004);
	utility_val.setCachePath("D:\\\\Program Files\\\\cache\\\\");
	utility_val.setAppType(0x00);
	utility_val.setCommandHeader("get");
	utility_val.setCommand("get champ.doc");
	utility_val.setAppSessionId(1ull);

	business_val.setActionType(AppLayerAction::ACTION_BROWSING);
	business_val.setOccurTime(1324881183u);
	business_val.setProtocolType(0x03);
	business_val.setClientPort(3241);
	business_val.setCachePath("D:\\\\Program Files\\\\cache\\\\");
	business_val.setAppType(BusinessAppAction::APP_BS_COMMON);
	business_val.setLoginStatus(1);
	business_val.setAppSessionId(1ull);

	im_val.setActionType(AppLayerAction::ACTION_IMCHAT);
	im_val.setOccurTime(1324881183u);
	im_val.setProtocolType(0x03);
	im_val.setClientPort(3650);
	im_val.setDirection(1);
	im_val.setContent("hey, what\\'s wrong with you?");
	im_val.setCachePath("D:\\\\Program Files\\\\cache\\\\");
	im_val.setSubProtocol('\0');
	im_val.setSendAccount("2374056");
	im_val.setAcceptAccount("49056732345");
	im_val.setSessionId("QQ_23456");
	im_val.setGroupChatFlag(false);
	im_val.setAppSessionId(1ull);

	email_val.setActionType(AppLayerAction::ACTION_EMAIL);
	email_val.setOccurTime(1324881183u);
	email_val.setProtocolType(0x03);
	email_val.setClientPort(4067);
	email_val.setDirection(0);
	email_val.setContent("just another day, coming soon...");
	email_val.setCachePath("D:\\\\Program Files\\\\cache\\\\");
	email_val.setSessionId("session_1234");
	email_val.setSubProtocol('\0');
	email_val.setSendAccount("admin@qq.com");
	email_val.setAcceptAccount("all@qq.com");
	email_val.setCopyTo("mht@qq.com");
	email_val.setSecretCopyTo("");
	email_val.setSubject("just another day");
	email_val.setAppSessionId(1ull);

	chat_room_val.setActionType(AppLayerAction::ACTION_CHATROOM);
	chat_room_val.setOccurTime(1324881183u);
	chat_room_val.setProtocolType(0x03);
	chat_room_val.setClientPort(4667);
	chat_room_val.setDirection(0);
	chat_room_val.setContent("Thunder will win!!!");
	chat_room_val.setCachePath("D:\\\\Program Files\\\\cache\\\\");
	chat_room_val.setLoginUrl("");
	chat_room_val.setSendAccount("kobe24@sina.com");
	chat_room_val.setAcceptAccount("zhibo@sina.com");
	chat_room_val.setNickName("Iverson");
	chat_room_val.setRoomId("101");
	chat_room_val.setAppSessionId(1ull);

	slave_account_val.setAccountType(NetworkAccount::ACCOUNT_MAIL);
	slave_account_val.setIsAnonymous(false);
	slave_account_val.setAccountId("kobe24@sina.com");
	slave_account_val.setPassword("123456");
	slave_account_val.setNickName("kb24");
	slave_account_val.setFristIdentify(1324881183u);
	slave_account_val.setServiceProvider(4u);
	slave_account_val.setImSessionId(1ull);
	slave_account_val.setMailSessionId(1ull);
	slave_account_val.setChatRoomSessionId(1ull);

	attached_file_value.setFileName("champ.doc");
	attached_file_value.setFileSize(3455u);
	attached_file_value.setFilePath("D:\\\\Program Files\\\\download\\\\");
	attached_file_value.setImSessionId(1ull);
	attached_file_value.setMailSessionId(1ull);
	attached_file_value.setChatRoomSessionId(1ull);

	connection = BaseOrmDbManager::getConnection("mysql-sitedb", "root", "kobe24");

	host_online_factory = OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::getDAOFactory(BaseOrmDbManager::MYSQL);
	master_network_factory = OrmDbManager<MasterNetworkAccountValue, MasterNetworkAccount>::getDAOFactory(BaseOrmDbManager::MYSQL);
	server_info_factory = OrmDbManager<ServerInfoValue, ServerInfo>::getDAOFactory(BaseOrmDbManager::MYSQL);
	app_session_factory = OrmDbManager<AppLayerSessionValue, AppLayerSession>::getDAOFactory(BaseOrmDbManager::MYSQL);
	log_factory = OrmDbManager<LoginOrLogoffActionValue, LoginOrLogoffAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	subscribe_factory = OrmDbManager<SubscribingActionValue, SubscribingAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	browse_factory = OrmDbManager<BrowsingActionValue, BrowsingAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	stream_media_factory = OrmDbManager<StreamMediaActionValue, StreamMediaAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	search_factory = OrmDbManager<SearchingActionValue, SearchingAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	post_factory = OrmDbManager<PostActionValue, PostAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	data_trans_factory = OrmDbManager<DataTransmissionActionValue, DataTransmissionAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	transmiss_factory = OrmDbManager<TransmissedFileValue, TransmissedFile>::getDAOFactory(BaseOrmDbManager::MYSQL);
	game_factory = OrmDbManager<GameActionValue, GameAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	utility_factory = OrmDbManager<UtilityAppActionValue, UtilityAppAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	business_factory = OrmDbManager<BusinessAppActionValue, BusinessAppAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	im_factory = OrmDbManager<ImChatActionValue, ImChatAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	email_factory = OrmDbManager<EmailActionValue, EmailAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	chat_room_factory = OrmDbManager<ChatRoomActionValue, ChatRoomAction>::getDAOFactory(BaseOrmDbManager::MYSQL);
	slave_account_factory = OrmDbManager<SlaveNetworkAccountValue, SlaveNetworkAccount>::getDAOFactory(BaseOrmDbManager::MYSQL);
	attached_file_factory = OrmDbManager<AttachedFileValue, AttachedFile>::getDAOFactory(BaseOrmDbManager::MYSQL);

	host_online_dao = OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::getDAOInstance(host_online_factory, *connection);
	master_network_dao = OrmDbManager<MasterNetworkAccountValue, MasterNetworkAccount>::getDAOInstance(master_network_factory, *connection);
	server_info_dao = OrmDbManager<ServerInfoValue, ServerInfo>::getDAOInstance(server_info_factory, *connection);
	app_session_dao = OrmDbManager<AppLayerSessionValue, AppLayerSession>::getDAOInstance(app_session_factory, *connection);
	log_dao = OrmDbManager<LoginOrLogoffActionValue, LoginOrLogoffAction>::getDAOInstance(log_factory, *connection);
	subscribe_dao = OrmDbManager<SubscribingActionValue, SubscribingAction>::getDAOInstance(subscribe_factory, *connection);
	browse_dao = OrmDbManager<BrowsingActionValue, BrowsingAction>::getDAOInstance(browse_factory, *connection);
	stream_media_dao = OrmDbManager<StreamMediaActionValue, StreamMediaAction>::getDAOInstance(stream_media_factory, *connection);
	search_dao = OrmDbManager<SearchingActionValue, SearchingAction>::getDAOInstance(search_factory, *connection);
	post_dao = OrmDbManager<PostActionValue, PostAction>::getDAOInstance(post_factory, *connection);
	data_trans_dao = OrmDbManager<DataTransmissionActionValue, DataTransmissionAction>::getDAOInstance(data_trans_factory, *connection);
	transmiss_dao = OrmDbManager<TransmissedFileValue, TransmissedFile>::getDAOInstance(transmiss_factory, *connection);
	game_dao = OrmDbManager<GameActionValue, GameAction>::getDAOInstance(game_factory, *connection);
	utility_dao = OrmDbManager<UtilityAppActionValue, UtilityAppAction>::getDAOInstance(utility_factory, *connection);
	business_dao = OrmDbManager<BusinessAppActionValue, BusinessAppAction>::getDAOInstance(business_factory, *connection);
	im_dao = OrmDbManager<ImChatActionValue, ImChatAction>::getDAOInstance(im_factory, *connection);
	email_dao = OrmDbManager<EmailActionValue, EmailAction>::getDAOInstance(email_factory, *connection);
	chat_room_dao = OrmDbManager<ChatRoomActionValue, ChatRoomAction>::getDAOInstance(chat_room_factory, *connection);
	slave_account_dao = OrmDbManager<SlaveNetworkAccountValue, SlaveNetworkAccount>::getDAOInstance(slave_account_factory, *connection);
	attached_file_dao = OrmDbManager<AttachedFileValue, AttachedFile>::getDAOInstance(attached_file_factory, *connection);
}

void transfer_classesTest::tearDown(void)
{
	OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOInstance(host_online_dao);
	OrmDbManager<MasterNetworkAccountValue, MasterNetworkAccount>::destroyDAOInstance(master_network_dao);
	OrmDbManager<ServerInfoValue, ServerInfo>::destroyDAOInstance(server_info_dao);
	OrmDbManager<AppLayerSessionValue, AppLayerSession>::destroyDAOInstance(app_session_dao);
	OrmDbManager<LoginOrLogoffActionValue, LoginOrLogoffAction>::destroyDAOInstance(log_dao);
	OrmDbManager<SubscribingActionValue, SubscribingAction>::destroyDAOInstance(subscribe_dao);
	OrmDbManager<BrowsingActionValue, BrowsingAction>::destroyDAOInstance(browse_dao);
	OrmDbManager<StreamMediaActionValue, StreamMediaAction>::destroyDAOInstance(stream_media_dao);
	OrmDbManager<SearchingActionValue, SearchingAction>::destroyDAOInstance(search_dao);
	OrmDbManager<PostActionValue, PostAction>::destroyDAOInstance(post_dao);
	OrmDbManager<DataTransmissionActionValue, DataTransmissionAction>::destroyDAOInstance(data_trans_dao);
	OrmDbManager<TransmissedFileValue, TransmissedFile>::destroyDAOInstance(transmiss_dao);
	OrmDbManager<GameActionValue, GameAction>::destroyDAOInstance(game_dao);
	OrmDbManager<UtilityAppActionValue, UtilityAppAction>::destroyDAOInstance(utility_dao);
	OrmDbManager<BusinessAppActionValue, BusinessAppAction>::destroyDAOInstance(business_dao);
	OrmDbManager<ImChatActionValue, ImChatAction>::destroyDAOInstance(im_dao);
	OrmDbManager<EmailActionValue, EmailAction>::destroyDAOInstance(email_dao);
	OrmDbManager<ChatRoomActionValue, ChatRoomAction>::destroyDAOInstance(chat_room_dao);
	OrmDbManager<SlaveNetworkAccountValue, SlaveNetworkAccount>::destroyDAOInstance(slave_account_dao);
	OrmDbManager<AttachedFileValue, AttachedFile>::destroyDAOInstance(attached_file_dao);

	OrmDbManager<HostOnlineHistoryValue, HostOnlineHistoryRecord>::destroyDAOFactory(host_online_factory);
	OrmDbManager<MasterNetworkAccountValue, MasterNetworkAccount>::destroyDAOFactory(master_network_factory);
	OrmDbManager<ServerInfoValue, ServerInfo>::destroyDAOFactory(server_info_factory);
	OrmDbManager<AppLayerSessionValue, AppLayerSession>::destroyDAOFactory(app_session_factory);
	OrmDbManager<LoginOrLogoffActionValue, LoginOrLogoffAction>::destroyDAOFactory(log_factory);
	OrmDbManager<SubscribingActionValue, SubscribingAction>::destroyDAOFactory(subscribe_factory);
	OrmDbManager<BrowsingActionValue, BrowsingAction>::destroyDAOFactory(browse_factory);
	OrmDbManager<StreamMediaActionValue, StreamMediaAction>::destroyDAOFactory(stream_media_factory);
	OrmDbManager<SearchingActionValue, SearchingAction>::destroyDAOFactory(search_factory);
	OrmDbManager<PostActionValue, PostAction>::destroyDAOFactory(post_factory);
	OrmDbManager<DataTransmissionActionValue, DataTransmissionAction>::destroyDAOFactory(data_trans_factory);
	OrmDbManager<TransmissedFileValue, TransmissedFile>::destroyDAOFactory(transmiss_factory);
	OrmDbManager<GameActionValue, GameAction>::destroyDAOFactory(game_factory);
	OrmDbManager<UtilityAppActionValue, UtilityAppAction>::destroyDAOFactory(utility_factory);
	OrmDbManager<BusinessAppActionValue, BusinessAppAction>::destroyDAOFactory(business_factory);
	OrmDbManager<ImChatActionValue, ImChatAction>::destroyDAOFactory(im_factory);
	OrmDbManager<EmailActionValue, EmailAction>::destroyDAOFactory(email_factory);
	OrmDbManager<ChatRoomActionValue, ChatRoomAction>::destroyDAOFactory(chat_room_factory);
	OrmDbManager<SlaveNetworkAccountValue, SlaveNetworkAccount>::destroyDAOFactory(slave_account_factory);
	OrmDbManager<AttachedFileValue, AttachedFile>::destroyDAOFactory(attached_file_factory);

	BaseOrmDbManager::destroyConnection(connection);
}

bool operator==(const HostOnlineHistoryRecord& left, const HostOnlineHistoryRecord& right)
{
	if (memcmp(left.mac, right.mac, sizeof(right.mac) ) || \
		memcmp(left.ip, right.ip, sizeof(right.ip) ) ) {

		return false;
	}
	return ( (left.host_name == right.host_name) && \
		     (left.online_time == right.online_time) && \
		     (left.offline_time == right.offline_time) && \
		     (left.ip_type == right.ip_type) && \
		     (left.vlan_id == right.vlan_id) && \
		     (left.place_id == right.place_id) );
}

bool operator==(const NetworkAccount& left, const NetworkAccount& right)
{
	return ( (left.account_type == right.account_type) && \
			 (left.is_anonymous == right.is_anonymous) && \
			 (left.account_id == right.account_id) && \
			 (left.password == right.password) && \
			 (left.nick_name == right.nick_name) && \
			 (left.first_identify_time == right.first_identify_time) && \
			 (left.service_provider == right.service_provider) );
}

bool operator==(const MasterNetworkAccount& left, const MasterNetworkAccount& right)
{
	return (operator==(static_cast<const NetworkAccount &>(left), static_cast<const NetworkAccount &>(right) ) );
}

bool operator==(const ServerInfo& left, const ServerInfo& right)
{
	if (memcmp(left.server_mac, right.server_mac, sizeof(right.server_mac) ) || \
		memcmp(left.server_ip, right.server_ip, sizeof(right.server_ip) ) ) {

		return false;
	}

	return ( (left.service_url == right.service_url) && \
			 (left.domain_name == right.domain_name) && \
			 (left.service_ip_type == right.service_ip_type) && \
			 (left.service_port == right.service_port) );
}

bool operator==(const AppLayerSession& left, const AppLayerSession& right)
{
	return ( (left.al_protocol_type == right.al_protocol_type) && \
			 (left.start_time == right.start_time) && \
			 (left.end_time == right.end_time) && \
			 (left.online_host_id == right.online_host_id) && \
			 (left.server_info_id == right.server_info_id) && \
			 (left.main_account_id == right.main_account_id) );
}

bool operator==(const AppLayerAction& left, const AppLayerAction& right)
{
	return ( (left.action_type == right.action_type) && \
			 (left.occur_time == right.occur_time) && \
			 (left.protocol_type == right.protocol_type) && \
			 (left.client_port == right.client_port) );
}

bool operator==(const LoginOrLogoffAction& left, const LoginOrLogoffAction& right)
{
	return ( (operator==(static_cast<const AppLayerAction &>(left), static_cast<const AppLayerAction &>(right) ) ) && \
			 (left.is_login == right.is_login) && \
			 (left.login_time == right.login_time) && \
			 (left.logout_time == right.logout_time) );
}

bool operator==(const GeneralAction& left, const GeneralAction& right)
{
	return ( (operator==(static_cast<const AppLayerAction &>(left), static_cast<const AppLayerAction &>(right) ) ) && \
			 (left.content_cache_path == right.content_cache_path) );
}

bool operator==(const InteractiveAction& left, const InteractiveAction& right)
{
	return ( (operator==(static_cast<const AppLayerAction &>(left), static_cast<const AppLayerAction &>(right) ) ) && \
			 (left.direction == right.direction) && \
			 (left.content == right.content) && \
			 (left.content_cache_path == right.content_cache_path) );
}

bool operator==(const FileDesc& left, const FileDesc& right)
{
	return ( (left.file_name == right.file_name) && \
			 (left.file_size == right.file_size) && \
			 (left.save_file_path == right.save_file_path) );
}

bool operator==(const SubscribingAction& left, const SubscribingAction& right)
{
	return ( (operator==(static_cast<const GeneralAction &>(left), static_cast<const GeneralAction &>(right) ) ) && \
			 (left.request_url == right.request_url) && \
			 (left.subscribe_type == right.subscribe_type) && \
			 (left.subject == right.subject) );
}

bool operator==(const BrowsingAction& left, const BrowsingAction& right)
{
	return ( (operator==(static_cast<const GeneralAction &>(left), static_cast<const GeneralAction &>(right) ) ) && \
			 (left.request_url == right.request_url) && \
			 (left.http_request_method == right.http_request_method) && \
			 (left.http_request_port == right.http_request_port) && \
			 (left.http_response_type == right.http_response_type) && \
			 (left.subject == right.subject) && \
			 (left.browser_version == right.browser_version) );
}

bool operator==(const StreamMediaAction& left, const StreamMediaAction& right)
{
	return ( (operator==(static_cast<const GeneralAction &>(left), static_cast<const GeneralAction &>(right) ) ) && \
			 (left.request_url == right.request_url) && \
			 (left.stream_media_type == right.stream_media_type) && \
			 (left.login_status == right.login_status) );
}

bool operator==(const SearchingAction& left, const SearchingAction& right)
{
	return ( (operator==(static_cast<const GeneralAction &>(left), static_cast<const GeneralAction &>(right) ) ) && \
			 (left.request_url == right.request_url) && \
			 (left.keyword == right.keyword) && \
			 (left.search_type == right.search_type) && \
			 (left.service_provider == right.service_provider) );
}

bool operator==(const PostAction& left, const PostAction& right)
{
	return ( (operator==(static_cast<const GeneralAction &>(left), static_cast<const GeneralAction &>(right) ) ) && \
			 (left.request_url == right.request_url) && \
			 (left.http_request_method == right.http_request_method) && \
			 (left.http_request_port == right.http_request_port) && \
			 (left.session_id == right.session_id) && \
			 (left.post_type == right.post_type) && \
			 (left.subject == right.subject) && \
			 (left.content == right.content) && \
			 (left.author == right.author) && \
			 (left.service_provider == right.service_provider) && \
			 (left.reference_content == right.reference_content) );
}

bool operator==(const DataTransmissionAction& left, const DataTransmissionAction& right)
{
	return ( (operator==(static_cast<const GeneralAction &>(left), static_cast<const GeneralAction &>(right) ) ) && \
			 (left.transmission_type == right.transmission_type) && \
			 (left.command == right.command) && \
			 (left.utility_action_id == right.utility_action_id) );
}

bool operator==(const TransmissedFile& left, const TransmissedFile& right)
{
	return ( (operator==(static_cast<const FileDesc &>(left), static_cast<const FileDesc &>(right) ) ) && \
			 (left.trans_action_id == right.trans_action_id) );
}

bool operator==(const GameAction& left, const GameAction& right)
{
	return ( (operator==(static_cast<const GeneralAction &>(left), static_cast<const GeneralAction &>(right) ) ) && \
			 (left.game_type == right.game_type) && \
			 (left.online_status == right.online_status) && \
			 (left.send_acct == right.send_acct) && \
			 (left.accept_acct == right.accept_acct) && \
			 (left.chat_content == right.chat_content) );
}

bool operator==(const UtilityAppAction& left, const UtilityAppAction& right)
{
	return ( (operator==(static_cast<const GeneralAction &>(left), static_cast<const GeneralAction &>(right) ) ) && \
			 (left.app_type == right.app_type) && \
			 (left.command_header == right.command_header) && \
			 (left.command == right.command) && \
			 (left.tans_action_id == right.tans_action_id) );
}

bool operator==(const BusinessAppAction& left, const BusinessAppAction& right)
{
	return ( (operator==(static_cast<const GeneralAction &>(left), static_cast<const GeneralAction &>(right) ) ) && \
			 (left.app_type == right.app_type) && \
			 (left.login_status == right.login_status) );
}

bool operator==(const ImChatAction& left, const ImChatAction& right)
{
	return ( (operator==(static_cast<const InteractiveAction &>(left), static_cast<const InteractiveAction &>(right) ) ) && \
			 (left.im_sub_protocol == right.im_sub_protocol) && \
			 (left.send_account == right.send_account) && \
			 (left.accept_account == right.accept_account) && \
			 (left.session_id == right.session_id) && \
			 (left.group_chat_flag == right.group_chat_flag) );

}

bool operator==(const EmailAction& left, const EmailAction& right)
{
	return ( (operator==(static_cast<const InteractiveAction &>(left), static_cast<const InteractiveAction &>(right) ) ) && \
			 (left.session_id == right.session_id) && \
			 (left.email_sub_protocol == right.email_sub_protocol) && \
			 (left.send_account == right.send_account) && \
			 (left.accept_account == right.accept_account) && \
			 (left.copy_to_account == right.copy_to_account) && \
			 (left.secret_copy_to_account == right.secret_copy_to_account) && \
			 (left.subject == right.subject) );
}

bool operator==(const ChatRoomAction& left, const ChatRoomAction& right)
{
	return ( (operator==(static_cast<const InteractiveAction &>(left), static_cast<const InteractiveAction &>(right) ) ) && \
			 (left.login_url == right.login_url) && \
			 (left.send_account == right.send_account) && \
			 (left.accept_account == right.accept_account) && \
			 (left.room_id == right.room_id) );
}

bool operator==(const SlaveNetworkAccount& left, const SlaveNetworkAccount& right)
{
	return ( (operator==(static_cast<const NetworkAccount &>(left), static_cast<const NetworkAccount &>(right) ) ) && \
			 (left.im_chat_action_id == right.im_chat_action_id) && \
			 (left.mail_action_id == right.mail_action_id) && \
			 (left.chat_room_action_id == right.chat_room_action_id) );
}

bool operator==(const AttachedFile& left, const AttachedFile& right)
{
	return ( (operator==(static_cast<const FileDesc &>(left), static_cast<const FileDesc &>(right) ) ) && \
			 (left.im_chat_action_id == right.im_chat_action_id) && \
			 (left.mail_action_id == right.mail_action_id) && \
			 (left.chat_room_action_id == right.chat_room_action_id) );
}

void replaceStr(const string& orig_str, const string& old_str, const string& new_str)
{
	size_t pos = 0;
	string &temp_str = const_cast<string&>(orig_str);

	string::size_type new_str_len = new_str.length();
	string::size_type old_str_len = old_str.length();

	while(true)
	{
		pos = temp_str.find(old_str, pos);
		if (pos == string::npos) {
			break;
		}
		temp_str.replace(pos, old_str_len, new_str);
		pos += new_str_len;
	}

	return ;
}

void transfer_classesTest::testHostOnlineHistoryDao(void)
{
	// insert
	host_online_dao->insertRec(host_online_val);

	// retrieve
	list<HostOnlineHistoryRecord> *list1 = host_online_dao->selectRecs("SELECT * FROM HOST_ONLINE_HISTORY_RECORD;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<HostOnlineHistoryRecord>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	HostOnlineHistoryValue val;
	uint8_t ip[16] = {0x57, 0xF3, 0x35, 0x43, 0x7F, 0x9D, 0x78, 0x5B, 0x7B, 0x6E, 0xD4, 0x43, 0x7F, 0x9D, 0x78, 0x5B};
	val.setIp(ip);
	val.setVlanId("suntang01");
	val.setConditionId(saved_id, euqal);
	host_online_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setIp(it1->ip);
	val.setVlanId(it1->vlan_id);
	val.setConditionId(saved_id, euqal);
	host_online_dao->updateRec(val);

	// retrieve again
	list<HostOnlineHistoryRecord> *list2 = host_online_dao->selectRecs("SELECT * FROM HOST_ONLINE_HISTORY_RECORD;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<HostOnlineHistoryRecord>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	host_online_dao->destroyResultList(list1);
	host_online_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	host_online_dao->deleteRec(val);
}

void transfer_classesTest::testMasterNetworkAccountDao(void)
{
	// insert
	master_network_dao->insertRec(master_account_val);

	// retrieve
	list<MasterNetworkAccount> *list1 = master_network_dao->selectRecs("SELECT * FROM MASTER_NETWORK_ACCOUNT;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<MasterNetworkAccount>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	MasterNetworkAccountValue val;
	val.setAccountId("onward");
	val.setPassword("654321");
	val.setConditionId(saved_id, euqal);
	master_network_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setAccountId(it1->account_id);
	val.setPassword(it1->password);
	val.setConditionId(saved_id, euqal);
	master_network_dao->updateRec(val);

	// retrieve again
	list<MasterNetworkAccount> *list2 = master_network_dao->selectRecs("SELECT * FROM MASTER_NETWORK_ACCOUNT;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<MasterNetworkAccount>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	master_network_dao->destroyResultList(list1);
	master_network_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	master_network_dao->deleteRec(val);
}

void transfer_classesTest::testServerInfoDao(void)
{
	// insert
	server_info_dao->insertRec(server_info_val);

	// retrieve
	list<ServerInfo> *list1 = server_info_dao->selectRecs("SELECT * FROM SERVER_INFO;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<ServerInfo>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	ServerInfoValue val;
	uint8_t ip[16] = {0x57, 0xF3, 0x35, 0x43, 0x7F, 0x9D, 0x78, 0x5B, 0x7B, 0x6E, 0xD4, 0x43, 0x7F, 0x9D, 0x78, 0x5B};
	val.setServerIp(ip);
	val.setServicePort(3450);
	val.setConditionId(saved_id, euqal);
	server_info_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setServerIp(it1->server_ip);
	val.setServicePort(it1->service_port);
	val.setConditionId(saved_id, euqal);
	server_info_dao->updateRec(val);

	// retrieve again
	list<ServerInfo> *list2 = server_info_dao->selectRecs("SELECT * FROM SERVER_INFO;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<ServerInfo>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	server_info_dao->destroyResultList(list1);
	server_info_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	server_info_dao->deleteRec(val);
}

void transfer_classesTest::testAppLayerSessionDao(void)
{
	// insert
	app_session_dao->insertRec(app_session_val);

	// retrieve
	list<AppLayerSession> *list1 = app_session_dao->selectRecs("SELECT * FROM APP_LAYER_SESSION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<AppLayerSession>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	AppLayerSessionValue val;
	val.setStartTime(1344546567u);
	val.setProtocolType(0x06);
	val.setConditionId(saved_id, euqal);
	app_session_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setStartTime(it1->start_time);
	val.setProtocolType(it1->al_protocol_type);
	val.setConditionId(saved_id, euqal);
	app_session_dao->updateRec(val);

	// retrieve again
	list<AppLayerSession> *list2 = app_session_dao->selectRecs("SELECT * FROM APP_LAYER_SESSION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<AppLayerSession>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	app_session_dao->destroyResultList(list1);
	app_session_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	app_session_dao->deleteRec(val);
}

void transfer_classesTest::testLoginOrLogoffDao(void)
{
	// insert
	log_dao->insertRec(log_val);

	// retrieve
	list<LoginOrLogoffAction> *list1 = log_dao->selectRecs("SELECT * FROM LOGIN_OR_LOGOFF_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<LoginOrLogoffAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	LoginOrLogoffActionValue val;
	val.setLoginTime(134545667u);
	val.setLogoutTime(134545967u);
	val.setConditionId(saved_id, euqal);
	log_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setLoginTime(it1->login_time);
	val.setLogoutTime(it1->logout_time);
	val.setConditionId(saved_id, euqal);
	log_dao->updateRec(val);

	// retrieve again
	list<LoginOrLogoffAction> *list2 = log_dao->selectRecs("SELECT * FROM LOGIN_OR_LOGOFF_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<LoginOrLogoffAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	log_dao->destroyResultList(list1);
	log_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	log_dao->deleteRec(val);
}

void transfer_classesTest::testSubscribingDao(void)
{
	// insert
	subscribe_dao->insertRec(subscribe_val);

	// retrieve
	list<SubscribingAction> *list1 = subscribe_dao->selectRecs("SELECT * FROM SUBSCRIBING_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<SubscribingAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	SubscribingActionValue val;
	val.setSubscribeType(0x07);
	val.setSubject("Thunder up!");
	val.setConditionId(saved_id, euqal);
	subscribe_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setSubscribeType(it1->subscribe_type);
	val.setSubject(it1->subject);
	val.setConditionId(saved_id, euqal);
	subscribe_dao->updateRec(val);

	// retrieve again
	list<SubscribingAction> *list2 = subscribe_dao->selectRecs("SELECT * FROM SUBSCRIBING_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<SubscribingAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	subscribe_dao->destroyResultList(list1);
	subscribe_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	subscribe_dao->deleteRec(val);
}

void transfer_classesTest::testBrowsingDao(void)
{
	// insert
	browse_dao->insertRec(browse_val);

	// retrieve
	list<BrowsingAction> *list1 = browse_dao->selectRecs("SELECT * FROM BROWSING_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<BrowsingAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	BrowsingActionValue val;
	val.setClientPort(3098);
	val.setBrowserVersion("IE 9.0");
	val.setConditionId(saved_id, euqal);
	browse_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setClientPort(it1->client_port);
	val.setBrowserVersion(it1->browser_version);
	val.setConditionId(saved_id, euqal);
	browse_dao->updateRec(val);

	// retrieve again
	list<BrowsingAction> *list2 = browse_dao->selectRecs("SELECT * FROM BROWSING_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<BrowsingAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	browse_dao->destroyResultList(list1);
	browse_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	browse_dao->deleteRec(val);
}

void transfer_classesTest::testStreamMediaDao(void)
{
	// insert
	stream_media_dao->insertRec(stream_media_val);

	// retrieve
	list<StreamMediaAction> *list1 = stream_media_dao->selectRecs("SELECT * FROM STREAM_MEDIA_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<StreamMediaAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	StreamMediaActionValue val;
	val.setRequestUrl("\\\\check.html");
	val.setStreamMediaType(0x07);
	val.setConditionId(saved_id, euqal);
	stream_media_dao->updateRec(val);

	// update
	val.clearMembers();
	string url = it1->request_url;
	replaceStr(url, "\\", "\\\\");
	val.setRequestUrl(url);
	val.setStreamMediaType(it1->stream_media_type);
	val.setConditionId(saved_id, euqal);
	stream_media_dao->updateRec(val);

	// retrieve again
	list<StreamMediaAction> *list2 = stream_media_dao->selectRecs("SELECT * FROM STREAM_MEDIA_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<StreamMediaAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	stream_media_dao->destroyResultList(list1);
	stream_media_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	stream_media_dao->deleteRec(val);
}

void transfer_classesTest::testSearchingDao(void)
{
	// insert
	search_dao->insertRec(search_val);

	// retrieve
	list<SearchingAction> *list1 = search_dao->selectRecs("SELECT * FROM SEARCHING_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<SearchingAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	SearchingActionValue val;
	val.setSearchType(0x0A);
	val.setServiceProvider(2u);
	val.setConditionId(saved_id, euqal);
	search_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setSearchType(it1->search_type);
	val.setServiceProvider(it1->service_provider);
	val.setConditionId(saved_id, euqal);
	search_dao->updateRec(val);

	// retrieve again
	list<SearchingAction> *list2 = search_dao->selectRecs("SELECT * FROM SEARCHING_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<SearchingAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	search_dao->destroyResultList(list1);
	search_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	search_dao->deleteRec(val);
}

void transfer_classesTest::testPostDao(void)
{
	// insert
	post_dao->insertRec(post_val);

	// retrieve
	list<PostAction> *list1 = post_dao->selectRecs("SELECT * FROM POST_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<PostAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	PostActionValue val;
	val.setPostType(0x06);
	val.setAuthor("justyle");
	val.setConditionId(saved_id, euqal);
	post_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setPostType(it1->post_type);
	val.setAuthor(it1->author);
	val.setConditionId(saved_id, euqal);
	post_dao->updateRec(val);

	// retrieve again
	list<PostAction> *list2 = post_dao->selectRecs("SELECT * FROM POST_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<PostAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	post_dao->destroyResultList(list1);
	post_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	post_dao->deleteRec(val);
}

void transfer_classesTest::testDataTransmissionDao(void)
{
	// insert
	data_trans_dao->insertRec(data_trans_val);

	// retrieve
	list<DataTransmissionAction> *list1 = data_trans_dao->selectRecs("SELECT * FROM DATA_TRANSMISSION_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<DataTransmissionAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	DataTransmissionActionValue val;
	val.setTransmissionType(0x03);
	val.setCommand("mget");
	val.setConditionId(saved_id, euqal);
	data_trans_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setTransmissionType(it1->transmission_type);
	val.setCommand(it1->command);
	val.setConditionId(saved_id, euqal);
	data_trans_dao->updateRec(val);

	// retrieve again
	list<DataTransmissionAction> *list2 = data_trans_dao->selectRecs("SELECT * FROM DATA_TRANSMISSION_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<DataTransmissionAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	data_trans_dao->destroyResultList(list1);
	data_trans_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	data_trans_dao->deleteRec(val);
}

void transfer_classesTest::testTransmissedFileDao(void)
{
	// insert
	transmiss_dao->insertRec(tans_file_val);

	// retrieve
	list<TransmissedFile> *list1 = transmiss_dao->selectRecs("SELECT * FROM TRANSMISSED_FILE;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<TransmissedFile>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	TransmissedFileValue val;
	val.setFileName("nba.doc");
	val.setFilePath("D:\\\\entertainment\\\\");
	val.setConditionId(saved_id, euqal);
	transmiss_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setFileName(it1->file_name);
	string path = it1->save_file_path;
	replaceStr(path, "\\", "\\\\");
	val.setFilePath(path);
	val.setConditionId(saved_id, euqal);
	transmiss_dao->updateRec(val);

	// retrieve again
	list<TransmissedFile> *list2 = transmiss_dao->selectRecs("SELECT * FROM TRANSMISSED_FILE;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<TransmissedFile>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	transmiss_dao->destroyResultList(list1);
	transmiss_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	transmiss_dao->deleteRec(val);
}

void transfer_classesTest::testGameDao(void)
{
	// insert
	game_dao->insertRec(game_val);

	// retrieve
	list<GameAction> *list1 = game_dao->selectRecs("SELECT * FROM GAME_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<GameAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	GameActionValue val;
	val.setSendAcct("just4lal");
	val.setChatContent("no excuse, just accomplish it!!");
	val.setConditionId(saved_id, euqal);
	game_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setSendAcct(it1->send_acct);
	val.setChatContent(it1->chat_content);
	val.setConditionId(saved_id, euqal);
	game_dao->updateRec(val);

	// retrieve again
	list<GameAction> *list2 = game_dao->selectRecs("SELECT * FROM GAME_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<GameAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	game_dao->destroyResultList(list1);
	game_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	game_dao->deleteRec(val);
}

void transfer_classesTest::testUtilityAppDao(void)
{
	// insert
	utility_dao->insertRec(utility_val);

	// retrieve
	list<UtilityAppAction> *list1 = utility_dao->selectRecs("SELECT * FROM UTILITY_APP_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<UtilityAppAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	UtilityAppActionValue val;
	val.setCommandHeader("ls");
	val.setCommand("ls -l");
	val.setConditionId(saved_id, euqal);
	utility_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setCommandHeader(it1->command_header);
	val.setCommand(it1->command);
	val.setConditionId(saved_id, euqal);
	utility_dao->updateRec(val);

	// retrieve again
	list<UtilityAppAction> *list2 = utility_dao->selectRecs("SELECT * FROM UTILITY_APP_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<UtilityAppAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	utility_dao->destroyResultList(list1);
	utility_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	utility_dao->deleteRec(val);
}

void transfer_classesTest::testBusinessAppDao(void)
{
	// insert
	business_dao->insertRec(business_val);

	// retrieve
	list<BusinessAppAction> *list1 = business_dao->selectRecs("SELECT * FROM BUSINESS_APP_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<BusinessAppAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	BusinessAppActionValue val;
	val.setAppType(0x05);
	val.setLoginStatus(true);
	val.setConditionId(saved_id, euqal);
	business_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setAppType(it1->app_type);
	val.setLoginStatus(it1->login_status);
	val.setConditionId(saved_id, euqal);
	business_dao->updateRec(val);

	// retrieve again
	list<BusinessAppAction> *list2 = business_dao->selectRecs("SELECT * FROM BUSINESS_APP_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<BusinessAppAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	business_dao->destroyResultList(list1);
	business_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	business_dao->deleteRec(val);
}

void transfer_classesTest::testImChatDao(void)
{
	// insert
	im_dao->insertRec(im_val);

	// retrieve
	list<ImChatAction> *list1 = im_dao->selectRecs("SELECT * FROM IM_CHAT_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<ImChatAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	ImChatActionValue val;
	val.setSubProtocol(0x08);
	val.setGroupChatFlag(true);
	val.setConditionId(saved_id, euqal);
	im_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setSubProtocol(it1->im_sub_protocol);
	val.setGroupChatFlag(it1->group_chat_flag);
	val.setConditionId(saved_id, euqal);
	im_dao->updateRec(val);

	// retrieve again
	list<ImChatAction> *list2 = im_dao->selectRecs("SELECT * FROM IM_CHAT_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<ImChatAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	im_dao->destroyResultList(list1);
	im_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	im_dao->deleteRec(val);
}

void transfer_classesTest::testEmailDao(void)
{
	// insert
	email_dao->insertRec(email_val);

	// retrieve
	list<EmailAction> *list1 = email_dao->selectRecs("SELECT * FROM EMAIL_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<EmailAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	EmailActionValue val;
	val.setSendAccount("kb24@lakers.com");
	val.setSecretCopyTo("admin@lakers.com");
	val.setConditionId(saved_id, euqal);
	email_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setSendAccount(it1->send_account);
	val.setSecretCopyTo(it1->secret_copy_to_account);
	val.setConditionId(saved_id, euqal);
	email_dao->updateRec(val);

	// retrieve again
	list<EmailAction> *list2 = email_dao->selectRecs("SELECT * FROM EMAIL_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<EmailAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	email_dao->destroyResultList(list1);
	email_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	email_dao->deleteRec(val);
}

void transfer_classesTest::testChatRoomDao(void)
{
	// insert
	chat_room_dao->insertRec(chat_room_val);

	// retrieve
	list<ChatRoomAction> *list1 = chat_room_dao->selectRecs("SELECT * FROM CHAT_ROOM_ACTION;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<ChatRoomAction>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	ChatRoomActionValue val;
	val.setLoginUrl("\\\\chat1.html");
	val.setRoomId("sina-live-01");
	val.setConditionId(saved_id, euqal);
	chat_room_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setLoginUrl(it1->login_url);
	val.setRoomId(it1->room_id);
	val.setConditionId(saved_id, euqal);
	chat_room_dao->updateRec(val);

	// retrieve again
	list<ChatRoomAction> *list2 = chat_room_dao->selectRecs("SELECT * FROM CHAT_ROOM_ACTION;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<ChatRoomAction>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	chat_room_dao->destroyResultList(list1);
	chat_room_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	chat_room_dao->deleteRec(val);
}

void transfer_classesTest::testSlaveNetworkAccountDao(void)
{
	// insert
	slave_account_dao->insertRec(slave_account_val);

	// retrieve
	list<SlaveNetworkAccount> *list1 = slave_account_dao->selectRecs("SELECT * FROM SLAVE_NETWORK_ACCOUNT;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<SlaveNetworkAccount>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	SlaveNetworkAccountValue val;
	val.setNickName("allen");
	val.setServiceProvider(5u);
	val.setConditionId(saved_id, euqal);
	slave_account_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setNickName(it1->nick_name);
	val.setServiceProvider(it1->service_provider);
	val.setConditionId(saved_id, euqal);
	slave_account_dao->updateRec(val);

	// retrieve again
	list<SlaveNetworkAccount> *list2 = slave_account_dao->selectRecs("SELECT * FROM SLAVE_NETWORK_ACCOUNT;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<SlaveNetworkAccount>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	slave_account_dao->destroyResultList(list1);
	slave_account_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	slave_account_dao->deleteRec(val);
}

void transfer_classesTest::testAttachedFileDao(void)
{
	// insert
	attached_file_dao->insertRec(attached_file_value);

	// retrieve
	list<AttachedFile> *list1 = attached_file_dao->selectRecs("SELECT * FROM ATTACHED_FILE;");
	CPPUNIT_ASSERT(list1 != NULL);
	list<AttachedFile>::iterator it1 = list1->begin();

	SQLUBIGINT saved_id = it1->id;

	// update
	AttachedFileValue val;
	val.setFileName("eclipse.doc");
	val.setFileSize(2340u);
	val.setConditionId(saved_id, euqal);
	attached_file_dao->updateRec(val);

	// update
	val.clearMembers();
	val.setFileName(it1->file_name);
	val.setFileSize(it1->file_size);
	val.setConditionId(saved_id, euqal);
	attached_file_dao->updateRec(val);

	// retrieve again
	list<AttachedFile> *list2 = attached_file_dao->selectRecs("SELECT * FROM ATTACHED_FILE;");
	CPPUNIT_ASSERT(list2 != NULL);
	list<AttachedFile>::iterator it2 = list2->begin();

	CPPUNIT_ASSERT(*it2 == *it1);

	attached_file_dao->destroyResultList(list1);
	attached_file_dao->destroyResultList(list2);

	// delete
	val.clearMembers();
	val.setConditionId(saved_id, euqal);
	attached_file_dao->deleteRec(val);
}

#endif /* ECUT_MAIN */

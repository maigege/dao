/*
 * transfer_classes.hpp
 *
 *  Created on: Jun 6, 2012
 *      Author: Administrator
 */

#ifndef __TRANSFER_CLASSES_HPP__
#define __TRANSFER_CLASSES_HPP__

#include <vector>
#include <string>
#include <map>
#include <json_spirit.h>
#include <odbcpp/odbcpp.h>
#include "nsmplatform/entity/auditlog/general_action.hpp"
#include "nsmplatform/entity/auditlog/abstract_log.hpp"
#include "nsmplatform/entity/auditlog/interactive_action.hpp"
#include "nsmplatform/entity/auditlog/session.hpp"
#include "dao_exception.hpp"

using namespace std;
using namespace json_spirit;
using namespace odbcpp;
using namespace NSM;	// network security platform

enum field_type {string_field_type, char_field_type, ushort_field_type, int_field_type, \
	uint_field_type, ubigint_field_type, bool_field_type, real_field_type, binary_field_type, \
	null_type};
enum condition_type {euqal, less, less_qual, bigger, bigger_equal};

class ControlValue: public odbcpp::record {
public:
	ControlValue(void): is_bound(false) {}

	virtual ~ControlValue(void) {}

	virtual void bindRecord(void) = 0;

	virtual void initRecord(void) = 0;

	template <typename FieldType>
	void setField(const char *field_name, FieldType field_val, int field_type)
	{
		Value val(field_val);
		changed_fields[field_name] = make_pair(field_val, field_type);
	}
	template <size_t Len>
	void setField(const char *field_name, const uint8_t (&filed)[Len], int field_type=binary_field_type)
	{
		Array array;
		for (size_t i = 0; i < Len; ++i) {
			array.push_back(filed[i]);
		}

		changed_fields[field_name] = make_pair(array, field_type);
	}

	template <typename FieldType>
	void setCondition(const string &field_name, const FieldType &field_val, int field_type, int condition)
	{
		Value val(field_val);
		conditions.push_back(make_pair(field_name, make_pair(make_pair(field_val, field_type), condition) ) );
	}

	void setConditionId(SQLUBIGINT condition_id, int condition)
	{
	//	equal_conditions["id"] = equal_id;
		setCondition("id", condition_id, ubigint_field_type, condition);
	}

	void clearMembers(void)
	{
		changed_fields.clear();
		conditions.clear();
	}

	bool isBound(void) { return is_bound; }

public:
	map<string, pair<Value, int> > changed_fields;
	vector<pair<string, pair<pair<Value, int>, int> > > conditions;

protected:
	bool is_bound;
};

class HostOnlineHistoryValue: public ControlValue {
public:
	HostOnlineHistoryValue(void): table_name("HOST_ONLINE_HISTORY_RECORD"), online_host(NULL) {}

	~HostOnlineHistoryValue(void) { delete online_host; }

	void bindRecord(void);

	void initRecord(void) { online_host = new HostOnlineHistoryRecord; }

	HostOnlineHistoryRecord& getRec(void)
	{
		if (online_host == NULL) {
			GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
		}

		return *online_host;
	}

	void setId(uint64_t _id) { setField("id", _id, ubigint_field_type); }
	void setHostName(const string &_host_name) { setField("host_name", _host_name, string_field_type); }
	void setMac(const uint8_t (&_mac)[6]) { setField("mac", _mac, binary_field_type); }
	void setOnlineTime(uint32_t _online_time) { setField("online_time", static_cast<boost::int64_t>(_online_time), uint_field_type); }
	void setOfflineTime(uint32_t _offline_time) { setField("offline_time", static_cast<boost::int64_t>(_offline_time), uint_field_type); }
	void setIpType(uint8_t _ip_type) { setField("ip_type", _ip_type, char_field_type); }
	void setIp(const uint8_t (&_ip)[16]) { setField("ip", _ip, binary_field_type); }
	void setVlanId(const string &_vlan_id) { setField("vlan_id", _vlan_id, string_field_type); }
	void setPlaceId(const string &_place_id) { setField("place_id", _place_id, string_field_type); }

public:
	string table_name;

private:
	HostOnlineHistoryRecord *online_host;
};

class NetworkAccountValue: public ControlValue {
public:
	NetworkAccountValue(void): account(NULL) {}

	~NetworkAccountValue(void) { delete account; }

	void bindRecord(void);

	void initRecord(void) { account = new NetworkAccount; }

	NetworkAccount& getRec(void)
	{
		if (account == NULL) {
			GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
		}

		return *account;
	}

	void setId(uint64_t _id) { setField("id", _id, ubigint_field_type); }
	void setAccountType(uint8_t _account_type) { setField("account_type", _account_type, char_field_type); }
	void setSubAccountType(uint8_t _sub_account_type) { setField("sub_account_type", _sub_account_type, char_field_type); }
	void setIsAnonymous(bool _is_anonymous) { setField("is_anonymous", _is_anonymous, bool_field_type); }
	void setAccountId(const string &_account_id) { setField("account_id", _account_id, string_field_type); }
	void setUserId(const string &_user_id) { setField("user_id", _user_id, string_field_type); }
	void setPassword(const string &_password) { setField("password", _password, string_field_type); }
	void setNickName(const string &_nick_name) { setField("nick_name", _nick_name, string_field_type); }
	void setFristIdentify(uint32_t _first_identify_time) { setField("first_identify", static_cast<boost::int64_t>(_first_identify_time), uint_field_type); }
	void setServiceProvider(uint32_t _service_provider) { setField("service_provider", static_cast<boost::int64_t>(_service_provider), uint_field_type); }

protected:
	NetworkAccount *account;
};

class MasterNetworkAccountValue: public NetworkAccountValue {
public:
	MasterNetworkAccountValue(void): table_name("MASTER_NETWORK_ACCOUNT") {}

	void bindRecord(void);

	void initRecord(void) { account = new MasterNetworkAccount; }

public:
	string table_name;
};

class ServerInfoValue: public ControlValue {
public:
	ServerInfoValue(void): table_name("SERVER_INFO"), server_info(NULL) {}
	~ServerInfoValue(void) { delete server_info; }

	void bindRecord(void);

	void initRecord(void) { server_info = new ServerInfo; }

	ServerInfo& getRec(void)
	{
		if (server_info == NULL) {
			GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
		}

		return *server_info;
	}

	void setId(uint64_t _id) { setField("id", _id, ubigint_field_type); }
	void setServiceUrl(const string &_service_url) { setField("service_url", _service_url, string_field_type); }
	void setDomainName(const string &_domain_name) { setField("domain_name", _domain_name, string_field_type); }
	void setServiceIpType(uint8_t _service_ip_type) { setField("service_ip_type", _service_ip_type, char_field_type); }
	void setServerIp(const uint8_t (&_server_ip)[16]) { setField("server_ip", _server_ip, binary_field_type); }
	void setServicePort(uint16_t _service_port) { setField("service_port", _service_port, ushort_field_type); }
	void setServerMac(const uint8_t (&_server_mac)[6]) { setField("server_mac", _server_mac, binary_field_type); }

public:
	string table_name;

private:
	ServerInfo *server_info;
};

class AppLayerSessionValue: public ControlValue {
public:
	AppLayerSessionValue(void): table_name("APP_LAYER_SESSION"), app_session(NULL) {}
	~AppLayerSessionValue(void) { delete app_session; }

	void bindRecord(void);

	void initRecord(void) { app_session = new AppLayerSession; }

	AppLayerSession& getRec(void)
	{
		if (app_session == NULL) {
			GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
		}

		return *app_session;
	}

	void setId(uint64_t _id) { setField("id", _id, ubigint_field_type); }
	void setProtocolType(uint8_t _al_protocol_type) { setField("al_protocol_type", _al_protocol_type, char_field_type); }
	void setStartTime(uint32_t _start_time) { setField("start_time", static_cast<boost::int64_t>(_start_time), uint_field_type); }
	void setEndTime(uint32_t _end_time) { setField("end_time", static_cast<boost::int64_t>(_end_time), uint_field_type); }
	void setAccountId(uint64_t _account_id) { setField("account_id", _account_id, ubigint_field_type); }
	void setHostId(uint64_t _host_id) { setField("host_id", _host_id, ubigint_field_type); }
	void setServerInfoId(uint64_t _server_info_id) { setField("server_info_id", _server_info_id, ubigint_field_type); }

public:
	string table_name;

private:
	AppLayerSession *app_session;
};

class AppLayerActionValue: public ControlValue {
public:
	AppLayerActionValue(void): app_action(NULL) {}
	~AppLayerActionValue(void) { delete app_action; }

	void bindRecord(void);

	void initRecord(void) { app_action = new AppLayerAction; }

	AppLayerAction& getRec(void)
	{
		if (app_action == NULL) {
			GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
		}

		return *app_action;
	}

	void setId(uint64_t _id) { setField("id", _id, ubigint_field_type); }
	void setActionType(uint8_t _action_type) { setField("action_type", _action_type, char_field_type); }
	void setOccurTime(uint32_t _occur_time) { setField("occur_time", static_cast<boost::int64_t>(_occur_time), uint_field_type); }
	void setProtocolType(uint8_t _protocol_type) { setField("protocol_type", _protocol_type, char_field_type); }
	void setClientPort(uint16_t _client_port) { setField("client_port", _client_port, ushort_field_type); }

protected:
	AppLayerAction *app_action;
};

class LoginOrLogoffActionValue: public AppLayerActionValue {
public:
	LoginOrLogoffActionValue(void): table_name("LOGIN_OR_LOGOFF_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new LoginOrLogoffAction; }

	void setDirection(bool _is_login) { setField("is_login", _is_login, bool_field_type); }
	void setLoginTime(uint32_t _login_time) { setField("login_time", static_cast<boost::int64_t>(_login_time), uint_field_type); }
	void setLogoutTime(uint32_t _logout_time) { setField("logout_time", static_cast<boost::int64_t>(_logout_time), uint_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }

public:
	string table_name;
};

class GeneralActionValue: public AppLayerActionValue {
public:
	void bindRecord(void);

	void initRecord(void) { app_action = new GeneralAction; }

	void setCachePath(const string &_cache_path) { setField("cache_path", _cache_path, string_field_type); }
};

class InteractiveActionValue: public AppLayerActionValue {
public:
	void bindRecord(void);

	void initRecord(void) { app_action = new InteractiveAction; }

	void setDirection(bool _direction) { setField("direction", _direction, bool_field_type); }
	void setContent(const string &_content)  { setField("content", _content, string_field_type); }
	void setCachePath(const string &_cache_path) { setField("cache_path", _cache_path, string_field_type); }
};

class FileDescValue: public ControlValue {
public:
	FileDescValue(void): file_desc(NULL) {}
	~FileDescValue(void) { delete file_desc; }

	void bindRecord(void);

	void initRecord(void) { file_desc = new FileDesc; }

	FileDesc& getRec(void)
	{
		if (file_desc == NULL) {
			GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
		}

		return *file_desc;
	}

	void setId(uint64_t _id) { setField("id", _id, ubigint_field_type); }
	void setFileName(const string &_file_name)  { setField("file_name", _file_name, string_field_type); }
	void setFileSize(uint32_t _file_size) { setField("file_size", static_cast<boost::int64_t>(_file_size), uint_field_type); }
	void setFilePath(const string &_save_file_path)  { setField("file_path", _save_file_path, string_field_type); }

protected:
	FileDesc *file_desc;
};

class SubscribingActionValue: public GeneralActionValue {
public:
	SubscribingActionValue(void): table_name("SUBSCRIBING_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new SubscribingAction; }

	void setRequestUrl(const string &_request_url)  { setField("request_url", _request_url, string_field_type); }
	void setSubscribeType(uint8_t _subscribe_type) { setField("subscribe_type", _subscribe_type, char_field_type); }
	void setSubject(const string &_subject)  { setField("subject", _subject, string_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }

public:
	string table_name;
};

class BrowsingActionValue: public GeneralActionValue {
public:
	BrowsingActionValue(void): table_name("BROWSING_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new BrowsingAction; }

	void setRequestUrl(const string &_request_url)  { setField("request_url", _request_url, string_field_type); }
	void setRequestMethod(const string &_http_request_method)  { setField("request_method", _http_request_method, string_field_type); }
	void setRequestPort(uint16_t _http_request_port)  { setField("request_port", _http_request_port, ushort_field_type); }
	void setResponseType(uint8_t _http_response_type) { setField("response_type", _http_response_type, char_field_type); }
	void setSubject(const string &_subject)  { setField("subject", _subject, string_field_type); }
	void setBrowserVersion(const string &_browser_version)  { setField("browser_version", _browser_version, string_field_type); }
	void setSessionId(const string &_session_id) { setField("session_id", _session_id, string_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }

public:
	string table_name;
};

class StreamMediaActionValue: public GeneralActionValue {
public:
	StreamMediaActionValue(void): table_name("STREAM_MEDIA_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new StreamMediaAction; }

	void setRequestUrl(const string &_request_url)  { setField("request_url", _request_url, string_field_type); }
	void setStreamMediaType(uint8_t _stream_media_type) { setField("stream_media_type", _stream_media_type, char_field_type); }
	void setLoginStatus(uint32_t _login_status) { setField("login_status", static_cast<boost::int64_t>(_login_status), uint_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }

public:
	string table_name;
};

class SearchingActionValue: public GeneralActionValue {
public:
	SearchingActionValue(void): table_name("SEARCHING_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new SearchingAction; }

	void setRequestUrl(const string &_request_url)  { setField("request_url", _request_url, string_field_type); }
	void setKeyword(const string &_keyword)  { setField("keyword", _keyword, string_field_type); }
	void setSearchType(uint8_t _search_type) { setField("search_type", _search_type, char_field_type); }
	void setServiceProvider(uint32_t _service_provider)  { setField("service_provider", static_cast<boost::int64_t>(_service_provider), uint_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }

public:
	string table_name;
};

class PostActionValue: public GeneralActionValue {
public:
	PostActionValue(void): table_name("POST_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new PostAction; }

	void setRequestUrl(const string &_request_url)  { setField("request_url", _request_url, string_field_type); }
	void setRequestMethod(const string &_http_request_method)  { setField("request_method", _http_request_method, string_field_type); }
	void setRequestPort(uint16_t _http_request_port)  { setField("request_port", _http_request_port, ushort_field_type); }
	void setSessionId(const string &_session_id)  { setField("session_id", _session_id, string_field_type); }
	void setPostType(uint8_t _post_type) { setField("post_type", _post_type, char_field_type); }
	void setSubject(const string &_subject)  { setField("subject", _subject, string_field_type); }
	void setContent(const string &_content)  { setField("content", _content, string_field_type); }
	void setAuthor(const string &_author)  { setField("author", _author, string_field_type); }
	void setServiceProvider(uint32_t _service_provider)  { setField("service_provider", static_cast<boost::int64_t>(_service_provider), uint_field_type); }
	void setReferenceContent(const string &_reference_content)  { setField("reference_content", _reference_content, string_field_type); }
	void setReferenceAuthor(const string &_reference_author)  { setField("reference_author", _reference_author, string_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }

public:
	string table_name;
};

class DataTransmissionActionValue: public GeneralActionValue {
public:
	DataTransmissionActionValue(void): table_name("DATA_TRANSMISSION_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new DataTransmissionAction; }

	void setTransmissionType(uint8_t _transmission_type) { setField("transmission_type", _transmission_type, char_field_type); }
	void setCommand(const string &_command)  { setField("command", _command, string_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }
	void setUtilitySessionId(uint64_t _utility_session_id) { setField("utility_session_id", _utility_session_id, ubigint_field_type); }

public:
	string table_name;
};

class TransmissedFileValue: public FileDescValue {
public:
	TransmissedFileValue(void): table_name("TRANSMISSED_FILE") {}

	void bindRecord(void);

	void initRecord(void) { file_desc = new TransmissedFile; }

	void setTransActionId(uint64_t _transmission_id) { setField("transmission_id", _transmission_id, ubigint_field_type); }

public:
	string table_name;
};

class GameActionValue: public GeneralActionValue {
public:
	GameActionValue(void): table_name("GAME_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new GameAction; }

	void setGameType(uint8_t _game_type) { setField("game_type", _game_type, char_field_type); }
	void setOnlineStatus(uint32_t _online_status) { setField("online_status", static_cast<boost::int64_t>(_online_status), uint_field_type); }
	void setSendAcct(const string &_send_acct)  { setField("send_account", _send_acct, string_field_type); }
	void setAcceptAcct(const string &_accept_acct)  { setField("accept_account", _accept_acct, string_field_type); }
	void setChatContent(const string &_chat_content)  { setField("chat_content", _chat_content, string_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }

public:
	string table_name;
};

class UtilityAppActionValue: public GeneralActionValue {
public:
	UtilityAppActionValue(void): table_name("UTILITY_APP_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new UtilityAppAction; }

	void setAppType(uint8_t _app_type) { setField("app_type", _app_type, char_field_type); }
	void setCommandHeader(const string &_command_header)  { setField("command_header", _command_header, string_field_type); }
	void setCommand(const string &_command)  { setField("command", _command, string_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }
	void setTransSessionId(uint64_t _trans_session_id) { setField("transmission_session_id", _trans_session_id, ubigint_field_type); }

public:
	string table_name;
};

class BusinessAppActionValue: public GeneralActionValue {
public:
	BusinessAppActionValue(void): table_name("BUSINESS_APP_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new BusinessAppAction; }

	void setAppType(uint8_t _app_type) { setField("app_type", _app_type, char_field_type); }
	void setLoginStatus(uint32_t _login_status) { setField("login_status", static_cast<boost::int64_t>(_login_status), uint_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }

public:
	string table_name;
};

class ImChatActionValue: public InteractiveActionValue {
public:
	ImChatActionValue(void): table_name("IM_CHAT_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new ImChatAction; }

	void setSubProtocol(uint8_t _im_sub_protocol) { setField("im_sub_protocol", _im_sub_protocol, char_field_type); }
	void setSessionId(const string &_session_id)  { setField("session_id", _session_id, string_field_type); }
	void setSendAccount(const string &_send_account)  { setField("send_account", _send_account, string_field_type); }
	void setAcceptAccount(const string &_accept_account)  { setField("accept_account", _accept_account, string_field_type); }
	void setGroupChatFlag(bool _group_chat_flag)  { setField("group_chat_flag", _group_chat_flag, bool_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }

public:
	string table_name;
};

class EmailActionValue: public InteractiveActionValue {
public:
	EmailActionValue(void): table_name("EMAIL_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new EmailAction; }

	void setSessionId(const string &_session_id)  { setField("session_id", _session_id, string_field_type); }
	void setSubProtocol(uint8_t _email_sub_protocol) { setField("sub_protocol", _email_sub_protocol, char_field_type); }
	void setSendAccount(const string &_send_account)  { setField("send_account", _send_account, string_field_type); }
	void setSendAccountType(const uint8_t &_send_account_type)  { setField("send_account_type", _send_account_type, char_field_type); }
	void setAcceptAccount(const string &_accept_account)  { setField("accept_account", _accept_account, string_field_type); }
	void setCopyTo(const string &_copy_to_account)  { setField("copy_to_account", _copy_to_account, string_field_type); }
	void setSecretCopyTo(const string &_secret_copy_to_account)  { setField("secret_copy_to", _secret_copy_to_account, string_field_type); }
	void setSubject(const string &_subject)  { setField("subject", _subject, string_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }

public:
	string table_name;
};

class ChatRoomActionValue: public InteractiveActionValue {
public:
	ChatRoomActionValue(void): table_name("CHAT_ROOM_ACTION") {}

	void bindRecord(void);

	void initRecord(void) { app_action = new ChatRoomAction; }

	void setLoginUrl(const string &_login_url)  { setField("login_url", _login_url, string_field_type); }
	void setSendAccount(const string &_send_account)  { setField("send_account", _send_account, string_field_type); }
	void setAcceptAccount(const string &_accept_account)  { setField("accept_account", _accept_account, string_field_type); }
	void setNickName(const string &_nick_name)  { setField("nick_name", _nick_name, string_field_type); }
	void setRoomId(const string &_room_id)  { setField("room_id", _room_id, string_field_type); }
	void setAppSessionId(uint64_t _app_session_id) { setField("app_session_id", _app_session_id, ubigint_field_type); }

public:
	string table_name;
};

class SlaveNetworkAccountValue: public NetworkAccountValue {
public:
	SlaveNetworkAccountValue(void): table_name("SLAVE_NETWORK_ACCOUNT") {}

	void bindRecord(void);

	void initRecord(void) { account = new SlaveNetworkAccount; }

	void setImSessionId(uint64_t _im_session_id) { setField("im_session_id", _im_session_id, ubigint_field_type); }
	void setMailSessionId(uint64_t _mail_session_id) { setField("mail_session_id", _mail_session_id, ubigint_field_type); }
	void setChatRoomSessionId(uint64_t _chat_room_session_id) { setField("chat_room_session_id", _chat_room_session_id, ubigint_field_type); }

public:
	string table_name;
};

class AttachedFileValue: public FileDescValue {
public:
	AttachedFileValue(void): table_name("ATTACHED_FILE") {}

	void bindRecord(void);

	void initRecord(void) { file_desc = new AttachedFile; }

	void setAttachedId(uint64_t _attached_id) { setField("attached_id", _attached_id, string_field_type); }
	void setImSessionId(uint64_t _im_session_id) { setField("im_session_id", _im_session_id, ubigint_field_type); }
	void setMailSessionId(uint64_t _mail_session_id) { setField("mail_session_id", _mail_session_id, ubigint_field_type); }
	void setChatRoomSessionId(uint64_t _chat_room_session_id) { setField("chat_room_session_id", _chat_room_session_id, ubigint_field_type); }

public:
	string table_name;
};

#endif /* __TRANSFER_CLASSES_HPP__ */

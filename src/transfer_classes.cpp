/*
 * transfer_classes.cpp
 *
 *  Created on: Jun 8, 2012
 *      Author: Administrator
 */
#include "../include/transfer_classes.hpp"

void HostOnlineHistoryValue::bindRecord(void)
{
	bind(1, online_host->id);
	bind(2, online_host->host_name);
	bind(3, online_host->mac, 6);
	bind(4, reinterpret_cast<SQLUINTEGER &>(online_host->online_time) );
	bind(5, reinterpret_cast<SQLUINTEGER &>(online_host->offline_time) );
	bind(6, online_host->ip_type);
	bind(7, online_host->ip, 16);
	bind(8, online_host->vlan_id);
	bind(9, online_host->place_id);
}

void NetworkAccountValue::bindRecord(void)
{
	bind(1, account->id);
	bind(2, account->account_type);
	bind(3, account->sub_account_type);
	bind(4, reinterpret_cast<SQLCHAR &>(account->is_anonymous) );
	bind(5, account->account_id);
	bind(6, account->user_id);
	bind(7, account->password);
	bind(8, account->nick_name);
	bind(9, reinterpret_cast<SQLUINTEGER &>(account->first_identify_time) );
	bind(10, reinterpret_cast<SQLUINTEGER &>(account->service_provider) );
}

void MasterNetworkAccountValue::bindRecord(void)
{
	NetworkAccountValue::bindRecord();
}

void ServerInfoValue::bindRecord(void)
{
	bind(1, server_info->id);
	bind(2, server_info->service_url);
	bind(3, server_info->domain_name);
	bind(4, server_info->service_ip_type);
	bind(5, server_info->server_ip, 16);
	bind(6, server_info->service_port);
	bind(7, server_info->server_mac, 6);
}

void AppLayerSessionValue::bindRecord(void)
{
	bind(1, app_session->id);
	bind(2, app_session->al_protocol_type);
	bind(3, reinterpret_cast<SQLUINTEGER &>(app_session->start_time) );
	bind(4, reinterpret_cast<SQLUINTEGER &>(app_session->end_time) );
	bind(5, app_session->online_host_id);
	bind(6, app_session->server_info_id);
	bind(7, app_session->main_account_id);
}

void AppLayerActionValue::bindRecord(void)
{
	bind(1, app_action->id);
	bind(2, app_action->action_type);
	bind(3, reinterpret_cast<SQLUINTEGER &>(app_action->occur_time) );
	bind(4, app_action->protocol_type);
	bind(5, app_action->client_port);
}

void LoginOrLogoffActionValue::bindRecord(void)
{
	AppLayerActionValue::bindRecord();

	LoginOrLogoffAction *log_action = NULL;
	if (!(log_action = dynamic_cast<LoginOrLogoffAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(6, reinterpret_cast<SQLCHAR &>(log_action->is_login) );
	bind(7, reinterpret_cast<SQLUINTEGER &>(log_action->login_time) );
	bind(8, reinterpret_cast<SQLUINTEGER &>(log_action->logout_time) );
	bind(9, log_action->app_session_id);
}

void GeneralActionValue::bindRecord(void)
{
	AppLayerActionValue::bindRecord();

	GeneralAction *general_action = NULL;
	if (!(general_action = dynamic_cast<GeneralAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(6, general_action->content_cache_path);
}

void InteractiveActionValue::bindRecord(void)
{
	AppLayerActionValue::bindRecord();

	InteractiveAction *inter_action = NULL;
	if (!(inter_action = dynamic_cast<InteractiveAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(6, reinterpret_cast<SQLCHAR &>(inter_action->direction) );
	bind(7, inter_action->content);
	bind(8, inter_action->content_cache_path);
}


void FileDescValue::bindRecord(void)
{
	bind(1, file_desc->id);
	bind(2, file_desc->file_name);
	bind(3, reinterpret_cast<SQLUINTEGER &>(file_desc->file_size) );
	bind(4, file_desc->save_file_path);
}

void SubscribingActionValue::bindRecord(void)
{
	GeneralActionValue::bindRecord();

	SubscribingAction *sub_action = NULL;
	if (!(sub_action = dynamic_cast<SubscribingAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(7, sub_action->request_url);
	bind(8, sub_action->subscribe_type);
	bind(9, sub_action->subject);
	bind(10, sub_action->app_session_id);
}

void BrowsingActionValue::bindRecord(void)
{
	GeneralActionValue::bindRecord();

	BrowsingAction *browse_action = NULL;
	if (!(browse_action = dynamic_cast<BrowsingAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(7, browse_action->request_url);
	bind(8, browse_action->http_request_method);
	bind(9, browse_action->http_request_port);
	bind(10, browse_action->http_response_type);
	bind(11, browse_action->subject);
	bind(12, browse_action->browser_version);
	bind(13, browse_action->session_id);
	bind(14, browse_action->app_session_id);
}

void StreamMediaActionValue::bindRecord(void)
{
	GeneralActionValue::bindRecord();

	StreamMediaAction *stream_media_action = NULL;
	if (!(stream_media_action = dynamic_cast<StreamMediaAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(7, stream_media_action->request_url);
	bind(8, stream_media_action->stream_media_type);
	bind(9, reinterpret_cast<SQLUINTEGER &>(stream_media_action->login_status) );
	bind(10, stream_media_action->app_session_id);
}

void SearchingActionValue::bindRecord(void)
{
	GeneralActionValue::bindRecord();

	SearchingAction *search_action = NULL;
	if (!(search_action = dynamic_cast<SearchingAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(7, search_action->request_url);
	bind(8, search_action->keyword);
	bind(9, search_action->search_type);
	bind(10, reinterpret_cast<SQLUINTEGER &>(search_action->service_provider) );
	bind(11, search_action->app_session_id);
}

void PostActionValue::bindRecord(void)
{
	GeneralActionValue::bindRecord();

	PostAction *post_action = NULL;
	if (!(post_action = dynamic_cast<PostAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(7, post_action->request_url);
	bind(8, post_action->http_request_method);
	bind(9, post_action->http_request_port);
	bind(10, post_action->session_id);
	bind(11, post_action->post_type);
	bind(12, post_action->subject);
	bind(13, post_action->content);
	bind(14, post_action->author);
	bind(15, reinterpret_cast<SQLUINTEGER &>(post_action->service_provider) );
	bind(16, post_action->reference_content);
	bind(17, post_action->reference_author);
	bind(18, post_action->app_session_id);
}

void DataTransmissionActionValue::bindRecord(void)
{
	GeneralActionValue::bindRecord();

	DataTransmissionAction *trans_action = NULL;
	if (!(trans_action = dynamic_cast<DataTransmissionAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(7, trans_action->transmission_type);
	bind(8, trans_action->command);
	bind(9, trans_action->app_session_id);
	bind(10, trans_action->utility_action_id);
}

void TransmissedFileValue::bindRecord(void)
{
	FileDescValue::bindRecord();

	TransmissedFile *trans_file = NULL;
	if (!(trans_file = dynamic_cast<TransmissedFile *>(file_desc) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(5, trans_file->trans_action_id);
}

void GameActionValue::bindRecord(void)
{
	GeneralActionValue::bindRecord();

	GameAction *game_action = NULL;
	if (!(game_action = dynamic_cast<GameAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(7, game_action->game_type);
	bind(8, reinterpret_cast<SQLUINTEGER &>(game_action->online_status) );
	bind(9, game_action->send_acct);
	bind(10, game_action->accept_acct);
	bind(11, game_action->chat_content);
	bind(12, game_action->app_session_id);
}

void UtilityAppActionValue::bindRecord(void)
{
	GeneralActionValue::bindRecord();

	UtilityAppAction *utility_action = NULL;
	if (!(utility_action = dynamic_cast<UtilityAppAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(7, utility_action->app_type);
	bind(8, utility_action->command_header);
	bind(9, utility_action->command);
	bind(10, utility_action->app_session_id);
	bind(11, utility_action->tans_action_id);
}

void BusinessAppActionValue::bindRecord(void)
{
	GeneralActionValue::bindRecord();

	BusinessAppAction *business_action = NULL;
	if (!(business_action = dynamic_cast<BusinessAppAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(7, business_action->app_type);
	bind(8, reinterpret_cast<SQLUINTEGER &>(business_action->login_status) );
	bind(9, business_action->app_session_id);
}

void ImChatActionValue::bindRecord(void)
{
	InteractiveActionValue::bindRecord();

	ImChatAction *im_action = NULL;
	if (!(im_action = dynamic_cast<ImChatAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(9, im_action->im_sub_protocol);
	bind(10, im_action->session_id);
	bind(11, im_action->send_account);
	bind(12, im_action->accept_account);
	bind(13, reinterpret_cast<SQLCHAR &>(im_action->group_chat_flag) );
	bind(14, im_action->app_session_id);
}

void EmailActionValue::bindRecord(void)
{
	InteractiveActionValue::bindRecord();

	EmailAction *mail_action = NULL;
	if (!(mail_action = dynamic_cast<EmailAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(9, mail_action->session_id);
	bind(10, mail_action->email_sub_protocol);
	bind(11, mail_action->send_account);
	bind(12, mail_action->send_account_type);
	bind(13, mail_action->accept_account);
	bind(14, mail_action->copy_to_account);
	bind(15, mail_action->secret_copy_to_account);
	bind(16, mail_action->subject);
	bind(17, mail_action->app_session_id);
}

void ChatRoomActionValue::bindRecord(void)
{
	InteractiveActionValue::bindRecord();

	ChatRoomAction *chat_room_action = NULL;
	if (!(chat_room_action = dynamic_cast<ChatRoomAction *>(app_action) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

	bind(9, chat_room_action->login_url);
	bind(10, chat_room_action->send_account);
	bind(11, chat_room_action->accept_account);
	bind(12, chat_room_action->nick_name);
	bind(13, chat_room_action->room_id);
	bind(14, chat_room_action->app_session_id);
}

void SlaveNetworkAccountValue::bindRecord(void)
{
	NetworkAccountValue::bindRecord();

	SlaveNetworkAccount *slave_acct = NULL;
	if (!(slave_acct = dynamic_cast<SlaveNetworkAccount *>(account) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

#if 0
	if (typeid(*(slave_acct->interaction) ) == typeid(ImChatAction) ) {
		if (slave_acct->interaction != NULL) {
			bind(9, slave_acct->interaction->id);
		}
	} else if (typeid(*(slave_acct->interaction) ) == typeid(EmailAction) ) {
		if (slave_acct->interaction != NULL) {
			bind(10, slave_acct->interaction->id);
		}
	} else if (typeid(*(slave_acct->interaction) ) == typeid(ChatRoomAction) ) {
		if (slave_acct->interaction != NULL) {
			bind(11, slave_acct->interaction->id);
		}
	}
#else
	bind(9, slave_acct->im_chat_action_id);
	bind(10, slave_acct->mail_action_id);
	bind(11, slave_acct->chat_room_action_id);
#endif
}

void AttachedFileValue::bindRecord(void)
{
	FileDescValue::bindRecord();

	AttachedFile *attached_file = NULL;
	if (!(attached_file = dynamic_cast<AttachedFile *>(file_desc) ) ) {
		GEN_EXCEPTION(DaoError::VALUE_NOT_INITIALISED, "");
	}

#if 0
	if (typeid(*(attached_file->interaction) ) == typeid(ImChatAction) ) {
		if (attached_file->interaction != NULL) {
			bind(5, attached_file->interaction->id);
		}
	} else if (typeid(*(attached_file->interaction) ) == typeid(EmailAction) ) {
		if (attached_file->interaction != NULL) {
			bind(6, attached_file->interaction->id);
		}
	} else if (typeid(*(attached_file->interaction) ) == typeid(ChatRoomAction) ) {
		if (attached_file->interaction != NULL) {
			bind(7, attached_file->interaction->id);
		}
	}
#else
	bind(5, attached_file->attached_id);
	bind(6, attached_file->im_chat_action_id);
	bind(7, attached_file->mail_action_id);
	bind(8, attached_file->chat_room_action_id);
#endif
}

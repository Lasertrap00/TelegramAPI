/*
 * Copyright (c) 2015 Oleg Morozenkov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "../include/tgbot/Api.h"

#include "../include/tgbot/TgTypeParser.h"
#include "../include/tgbot/TgException.h"
#include "../include/tgbot/net/HttpClient.h"

using namespace std;
using namespace boost::property_tree;

namespace TgBot {

Api::Api(const string& token) : _token(token) {
}

User::Ptr Api::getMe() const {
	return TgTypeParser::getInstance().parseJsonAndGetUser(sendRequest("getMe"));
}

Message::Ptr Api::sendMessage(int64_t chatId, const string& text, bool disableWebPagePreview, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, const string& parseMode, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("text", text));
	if (disableWebPagePreview) {
		args.push_back(HttpReqArg("disable_web_page_preview", disableWebPagePreview));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (!parseMode.empty()) {
		args.push_back(HttpReqArg("parse_mode", parseMode));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendMessage", args));
}

Message::Ptr Api::forwardMessage(int64_t chatId, int64_t fromChatId, int32_t messageId, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("from_chat_id", fromChatId));
	args.push_back(HttpReqArg("message_id", messageId));
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("forwardMessage", args));
}

Message::Ptr Api::sendPhoto(int64_t chatId, const InputFile::Ptr& photo, const string& caption, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("photo", photo->data, true, photo->mimeType, photo->fileName));
	if (!caption.empty()) {
		args.push_back(HttpReqArg("caption", caption));
	}
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendPhoto", args));
}

Message::Ptr Api::sendPhoto(int64_t chatId, const string& photoId, const string& caption, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("photo", photoId));
	if (!caption.empty()) {
		args.push_back(HttpReqArg("caption", caption));
	}
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendPhoto", args));
}

Message::Ptr Api::sendAudio(int64_t chatId, const InputFile::Ptr& audio, int32_t duration, const string& performer, const string& title, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("audio", audio->data, true, audio->mimeType, audio->fileName));
	if (duration) {
		args.push_back(HttpReqArg("duration", duration));
	}
	if (!performer.empty()){
		args.push_back(HttpReqArg("performer", performer));
	}
	if (!title.empty()){
		args.push_back(HttpReqArg("title", title));
	}
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendAudio", args));
}

Message::Ptr Api::sendAudio(int64_t chatId, const string& audioId, int32_t duration, const string& performer, const string& title, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("audio", audioId));
	if (duration) {
		args.push_back(HttpReqArg("duration", duration));
	}
	if (!performer.empty()){
		args.push_back(HttpReqArg("performer", performer));
	}
	if (!title.empty()){
		args.push_back(HttpReqArg("title", title));
	}
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendAudio", args));
}

Message::Ptr Api::sendDocument(int64_t chatId, const InputFile::Ptr& document, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("document", document->data, true, document->mimeType, document->fileName));
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendDocument", args));
}

Message::Ptr Api::sendDocument(int64_t chatId, const string& document, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("document", document));
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendDocument", args));
}

Message::Ptr Api::sendSticker(int64_t chatId, const InputFile::Ptr& sticker, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("sticker", sticker->data, true, sticker->mimeType, sticker->fileName));
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendSticker", args));
}

Message::Ptr Api::sendSticker(int64_t chatId, const string& stickerId, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("sticker", stickerId));
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendSticker", args));
}

Message::Ptr Api::sendVideo(int64_t chatId, const InputFile::Ptr& video, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("video", video->data, true, video->mimeType, video->fileName));
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendVideo", args));
}

Message::Ptr Api::sendVideo(int64_t chatId, const string& videoId, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("video", videoId));
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendVideo", args));
}

Message::Ptr Api::sendVoice(int64_t chatId, const InputFile::Ptr& voice, int duration, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("voice", voice->data, true, voice->mimeType, voice->fileName));
	if (duration){
		args.push_back(HttpReqArg("duration", duration));
	}
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendVideo", args));
}

Message::Ptr Api::sendVoice(int64_t chatId, const std::string& voiceId, int duration, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("voice", voiceId));
	if (duration){
		args.push_back(HttpReqArg("duration", duration));
	}
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendVideo", args));
}

Message::Ptr Api::sendLocation(int64_t chatId, float latitude, float longitude, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup, bool disableNotification) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("latitude", latitude));
	args.push_back(HttpReqArg("longitude", longitude));
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendLocation", args));
}

Message::Ptr Api::sendVenue(int64_t chatId, float latitude, float longitude, std::string title, std::string address, std::string foursquareId, bool disableNotification, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("latitude", latitude));
	args.push_back(HttpReqArg("longitude", longitude));
	args.push_back(HttpReqArg("title", title));
	args.push_back(HttpReqArg("address", address));
	if (!foursquareId.empty()) {
		args.push_back(HttpReqArg("foursquare_id", foursquareId));
	}
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendVenue", args));
}

Message::Ptr Api::sendContact(int64_t chatId, std::string phoneNumber, std::string firstName, std::string lastName, bool disableNotification, int32_t replyToMessageId, const GenericReply::Ptr& replyMarkup) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("phone_number", phoneNumber));
	args.push_back(HttpReqArg("first_name", firstName));
	args.push_back(HttpReqArg("last_name", lastName));
	if (replyToMessageId) {
		args.push_back(HttpReqArg("reply_to_message_id", replyToMessageId));
	}
	if (replyMarkup) {
		args.push_back(HttpReqArg("reply_markup", TgTypeParser::getInstance().parseGenericReply(replyMarkup)));
	}
	if (disableNotification){
		args.push_back(HttpReqArg("disable_notification", disableNotification));
	}
	return TgTypeParser::getInstance().parseJsonAndGetMessage(sendRequest("sendContact", args));
}

void Api::sendChatAction(int64_t chatId, const string& action) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("action", action));
	sendRequest("sendChatAction", args);
}

UserProfilePhotos::Ptr Api::getUserProfilePhotos(int32_t userId, int32_t offset, int32_t limit) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("user_id", userId));
	if (offset) {
		args.push_back(HttpReqArg("offset", offset));
	}
	limit = max(1, min(100, limit));
	args.push_back(HttpReqArg("limit", limit));
	return TgTypeParser::getInstance().parseJsonAndGetUserProfilePhotos(sendRequest("getUserProfilePhotos", args));
}

vector<Update::Ptr> Api::getUpdates(int32_t offset, int32_t limit, int32_t timeout) const {
	vector<HttpReqArg> args;
	if (offset) {
		args.push_back(HttpReqArg("offset", offset));
	}
	limit = max(1, min(100, limit));
	args.push_back(HttpReqArg("limit", limit));
	if (timeout) {
		args.push_back(HttpReqArg("timeout", timeout));
	}
	return TgTypeParser::getInstance().parseJsonAndGetArray<Update>(&TgTypeParser::parseJsonAndGetUpdate, sendRequest("getUpdates", args));
}

void Api::setWebhook(const string& url, const InputFile::Ptr& certificate) const {
	vector<HttpReqArg> args;
	if (!url.empty())
		args.push_back(HttpReqArg("url", url));
	if (certificate != nullptr)
		args.push_back(HttpReqArg("certificate", certificate->data, true, certificate->mimeType, certificate->fileName));

	sendRequest("setWebhook", args);
}

void Api::answerInlineQuery(const std::string& inlineQueryId, const std::vector<InlineQueryResult::Ptr>& results,
                            int32_t cacheTime, bool isPersonal, const std::string& nextOffset) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("inline_query_id", inlineQueryId));
	string resultsJson = TgTypeParser::getInstance().parseArray<InlineQueryResult>(&TgTypeParser::parseInlineQueryResult, results);
	args.push_back(HttpReqArg("results", resultsJson));
	args.push_back(HttpReqArg("cache_time", cacheTime));
	args.push_back(HttpReqArg("is_personal", isPersonal));
	args.push_back(HttpReqArg("next_offset", nextOffset));
	sendRequest("answerInlineQuery", args);
}

void Api::kickChatMember(int64_t chatId, int32_t userId) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("user_id", userId));
	sendRequest("kickChatMember", args);
}

void Api::unbanChatMember(int64_t chatId, int32_t userId) const {
	vector<HttpReqArg> args;
	args.push_back(HttpReqArg("chat_id", chatId));
	args.push_back(HttpReqArg("user_id", userId));
	sendRequest("unbanChatMember", args);
}

ptree Api::sendRequest(const string& method, const vector<HttpReqArg>& args) const {

	string url = "https://api.telegram.org/bot";
	url += _token;
	url += "/";
	url += method;

	string serverResponse = HttpClient::getInstance().makeRequest(url, args);
	if (serverResponse.find("<html>") != serverResponse.npos) {
		throw TgException("tgbot-cpp library have got html page instead of json response. Maybe you entered wrong bot token.");
	}

	ptree result = TgTypeParser::getInstance().parseJson(serverResponse);
	try {
		if (result.get<bool>("ok", false)) {
			return result.get_child("result");
		} else {
			throw TgException(result.get("description", ""));
		}
	} catch (boost::property_tree::ptree_error& e) {
		throw TgException("tgbot-cpp library can't parse json response. " + string(e.what()));
	}
}

}

//
// Created by Andrea Giove on 17/04/16.
//

#ifndef TGBOT_CALLBACKQUERY_H
#define TGBOT_CALLBACKQUERY_H

#include <memory>
#include <string>

#include "User.h"
#include "Message.h"

namespace TgBot {

/**
 * This object represents an incoming callback query from a callback button in an inline keyboard.
 * @ingroup types
 */
class CallbackQuery {
public:
	typedef std::shared_ptr<CallbackQuery> Ptr;

	/**
	 * Unique identifier for this query.
	 */
	std::string id;

	/**
	 * Sender.
	 */
	User::Ptr from;

	/**
	 * Optional. Message with the callback button that originated the query. Note that message content and message date will not be available if the message is too old.
	 */
	Message::Ptr message;

	/**
	 * Optional. Identifier of the message sent via the bot in inline mode, that originated the query.
	 */
	std::string inlineMessageId;

	/**
	 * Data associated with the callback button. Be aware that a bad client can send arbitrary data in this field.
	 */
	std::string data;

};
}

#endif //TGBOT_CALLBACKQUERY_H

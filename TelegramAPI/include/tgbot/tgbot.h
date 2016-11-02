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

#ifndef TGBOT_TGBOT_H
#define TGBOT_TGBOT_H

#include "Bot.h"
#include "Api.h"
#include "TgException.h"
#include "TgTypeParser.h"
#include "EventBroadcaster.h"
#include "EventHandler.h"
#include "types/Audio.h"
#include "types/Contact.h"
#include "types/Document.h"
#include "types/ForceReply.h"
#include "types/GenericReply.h"
#include "types/InputFile.h"
#include "types/Location.h"
#include "types/Message.h"
#include "types/PhotoSize.h"
#include "types/ReplyKeyboardHide.h"
#include "types/ReplyKeyboardMarkup.h"
#include "types/Sticker.h"
#include "types/Update.h"
#include "types/User.h"
#include "types/UserProfilePhotos.h"
#include "types/Video.h"
#include "types/InlineQuery.h"
#include "types/InlineQueryResult.h"
#include "types/InlineQueryResultArticle.h"
#include "types/InlineQueryResultGif.h"
#include "types/InlineQueryResultMpeg4Gif.h"
#include "types/InlineQueryResultPhoto.h"
#include "types/InlineQueryResultVideo.h"
#include "types/ChosenInlineResult.h"
#include "tools/StringTools.h"
#include "net/HttpClient.h"
#include "net/HttpParser.h"
#include "net/HttpReqArg.h"
#include "net/HttpServer.h"
#include "net/TgLongPoll.h"
#include "net/TgWebhookLocalServer.h"
#include "net/TgWebhookServer.h"
#include "net/TgWebhookTcpServer.h"
#include "net/Url.h"

/**
 * @defgroup general
 * @defgroup types
 * @defgroup net
 * @defgroup tools
 *
 * @mainpage
 *
 * @section Compilation
 *
 * Firstly you need to install some dependencies. You have to have boost library at the runtime and cmake at the compilation step to be able to use this library.
 * On Debian-based distibutives you can do it with these commands:
 * @code{.sh}
 * sudo apt-get install g++ make binutils cmake libssl-dev libboost-system-dev libboost-iostreams-dev libboost-test-dev
 * @endcode
 *
 * To compile the library execute this commands:
 * @code{.sh}
 * cd /path/where/you/have/cloned/the/library/repository
 * cmake .
 * make -j4
 * sudo make install
 * @endcode
 *
 * That's all. All you have to do now is just link compiled library to your project.
 *
 * If you want, you can also use Docker to build and run your bot. Just set the base image of your's Dockerfile to reo7sp/tgbot-cpp.
 *
 * @section Samples
 * All samples are located [here](https://github.com/reo7sp/tgbot-cpp/tree/master/samples)
 *
 * @section Feedback
 * Feel free to [create new issues on GitHub](https://github.com/reo7sp/tgbot-cpp/issues) or [contact me on Telegram](https://telegram.me/Reo_SP)
 *
 * @section Licence
 * [The MIT License](http://opensource.org/licenses/MIT)
 */

#endif //TGBOT_TGBOT_H

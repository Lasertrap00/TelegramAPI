//
// Created by Andrea Giove on 27/03/16.
//
#include "../../include/tgbot/types/InlineQueryResultArticle.h"
#include "../../include/tgbot/types/InlineQueryResultGif.h"
#include "../../include/tgbot/types/InlineQueryResultMpeg4Gif.h"
#include "../../include/tgbot/types/InlineQueryResultPhoto.h"
#include "../../include/tgbot/types/InlineQueryResultVideo.h"

using namespace TgBot;

const std::string InlineQueryResultArticle::TYPE = "article";
const std::string InlineQueryResultGif::TYPE = "gif";
const std::string InlineQueryResultMpeg4Gif::TYPE = "mpeg4_gif";
const std::string InlineQueryResultPhoto::TYPE = "photo";
const std::string InlineQueryResultVideo::TYPE = "video";

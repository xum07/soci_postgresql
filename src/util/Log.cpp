/*
 * @Description: A simple thread-safty log print
 * @Author: xum07
 * @Date: 2022-10-29
 */
#include "util/Log.h"

static std::mutex g_mutex;

Log::Log() : lock_(std::lock_guard<std::mutex>(g_mutex)) {}
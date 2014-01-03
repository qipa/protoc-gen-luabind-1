// Copyright (C) 2012 by wubenqi
// Distributable under the terms of either the Apache License (Version 2.0) or 
// the GNU Lesser General Public License, as specified in the COPYING file.
//
// By: wubenqi<wubenqi@gmail.com>
//
// Lua�ű�����
//

#ifndef SCRIPTENGINE_LUA_UTIL_H_
#define SCRIPTENGINE_LUA_UTIL_H_

//get rid of the annoying but unavoidable forcing int to bool warning
#pragma warning (disable:4800)

#include "luabind/lua_include.hpp"
//#include "base/logging.h"

//������һ�����õİ�����������dump������ջ�����ݣ�
void LuaDumpStackHelper (lua_State* L);

#endif
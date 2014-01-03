// Copyright (C) 2012 by wubenqi
// Distributable under the terms of either the Apache License (Version 2.0) or 
// the GNU Lesser General Public License, as specified in the COPYING file.
//
// By: wubenqi<wubenqi@gmail.com>
//
// Lua�ű�����
//

#include "scriptengine/lua_util.h"

#include <iostream>

void LuaDumpStackHelper (lua_State* L) {
	int top = lua_gettop(L);
	std::cout << ">>>> [LuaDumpStackHelper]: Return " << top << " Value" << std::endl;
	for (int i = 1; i <= top; i++) {
		/* repeat for each level */
		int t = lua_type(L, i);
		// const char* type_name = lua_typename(L, t);
		switch (t) {
		case LUA_TSTRING:  /* strings */
			std::cout << "\t[" << lua_typename(L, t) << "], " << lua_tostring(L, i) << std::endl;
			break;
		case LUA_TBOOLEAN:  /* booleans */
			std::cout << "\t[" << lua_typename(L, t) << "], " << (lua_toboolean(L, i) ? "true" : "false") << std::endl;
			break;
		case LUA_TNUMBER:  /* numbers */
			std::cout << "\t[" << lua_typename(L, t) << "], " << lua_tonumber(L, i) << std::endl;
			break;
		case LUA_TTABLE:  /* table */
			{
				// �򵥵ı�����Ĺ���   
				// ***����lua��������Ԫ�ص����˳��***   
				std::cout << "\t["<< lua_typename(L, t) << "] "<< std::endl;

				// ѹ���һ����   
				lua_pushnil(L);  /* ��һ�� key */  
				int t = -2;   
				while (lua_next(L, t) != 0) {   
					/* 'key' (����-2) �� 'value' (����-1) */  
					const char* key = "unknown";   
					const char* value;   
					if(lua_type(L, -2) == LUA_TSTRING) {   
						key = lua_tostring(L, -2);   
						value = lua_tostring(L, -1);   
					} else if(lua_type(L, -2) == LUA_TNUMBER) {   
						// ��Ϊlua_tostring�����ջ�ϵ�Ԫ�أ�   
						// ���Բ���ֱ����key�Ͻ���lua_tostring   
						// ��ˣ�����һ��key��ѹ��ջ��������lua_tostring   
						lua_pushvalue(L, -2);   
						key = lua_tostring(L, -1);   
						lua_pop(L, 1);   
						value = lua_tostring(L, -1);   
					} else  { 
						value = lua_tostring(L, -1);   
					}   

					if (!value) {
						value = "nil";
					}
					std::cout <<"\t\tkey="<< key   
						<< ", value=" << value << std::endl;   
					/* �Ƴ� 'value' ������ 'key' ����һ�ε��� */  
					lua_pop(L, 1);   
				}   

			}
			break;
		default:  /* other values */
			std::cout << "\t["<< lua_typename(L, t) << "], can't get val" << std::endl;
			break;

		}
	}
	std::cout << "[LuaDumpStackHelper] <<<<" << std::endl;

}
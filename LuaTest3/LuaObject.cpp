//
//  LuaObject.cpp
//  LuaTest3
//
//  Created by Didrik Munther on 15/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include "LuaObject.h"


LuaObject::LuaObject(LuaScript* script)
    : _script(script)
    , _L(script->getState())
    , _path(script->getPath().c_str())
{
    if(script->doFile() == -1)
        error = true;
    else {
        error = false;
        _objectReference = luaL_ref(_L, LUA_REGISTRYINDEX);
    }
}

LuaObject::~LuaObject() {
    lua_unref(_L, _objectReference);
}

void LuaObject::selectScript() {
    lua_rawgeti(_L, LUA_REGISTRYINDEX, _objectReference);
}

void LuaObject::selectReference(std::string reference) {
    selectScript();
    lua_getfield(_L, -1, reference.c_str());
}

void LuaObject::beginFunctionCall(std::string function) {
    selectReference(function);
    lua_pushvalue(_L, -2);
}

void LuaObject::endFunctionCall(int argc, int results) {
    lua_call(_L, argc + 1, results);
}

void LuaObject::endFunctionCall() {
    endFunctionCall(0, 0);
}

void LuaObject::pushObject() {
    selectScript();
    lua_pushvalue(_L, -1);
    lua_pop(_L, 1);
}
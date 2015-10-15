//
//  LuaScript.cpp
//  LuaTest3
//
//  Created by Didrik Munther on 15/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include <iostream>

#include "LuaScript.h"


LuaScript::LuaScript(lua_State* L, std::string name)
    : _L(L)
    , _name(name)
{
    
}

int LuaScript::doFile() {
    if(luaL_dofile(_L, _name.c_str())) {
        std::cout << "No such script: " << _name << ".\n";
        return -1;
    }
    
    return 0;
}

lua_State* LuaScript::getState() {
    return _L;
}

std::string LuaScript::getName() {
    return _name;
}
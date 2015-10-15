//
//  LuaScript.cpp
//  LuaTest3
//
//  Created by Didrik Munther on 15/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include <iostream>

#include "LuaScript.h"


LuaScript::LuaScript(lua_State* L, std::string path)
    : _L(L)
    , _path(path)
{
    
}

int LuaScript::doFile() {
    if(luaL_dofile(_L, _path.c_str())) {
        std::cout << "Error in script: " << _path << ". (either the file doesn't exist or there was an error before loading it)\n";
        return -1;
    }
    
    return 0;
}

lua_State* LuaScript::getState() {
    return _L;
}

std::string LuaScript::getPath() {
    return _path;
}
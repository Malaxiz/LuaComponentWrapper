//
//  main.cpp
//  LuaTest3
//
//  Created by Didrik Munther on 15/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include <iostream>

extern "C" {
# include "lua/lua.h"
# include "lua/lauxlib.h"
# include "lua/lualib.h"
}

#include "LuaBridge/LuaBridge.h"

#include "Component.h"


int main(int argc, const char * argv[]) {

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "class.lua");
    
    LuaScript script(L, "Animal.lua");
    Component component(&script);
    Component component2(&script);
    
    component.onLoop();
    component.onLoop();
    component2.onLoop();
    
}

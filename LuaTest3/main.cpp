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
    
    {
        
        luaL_openlibs(L);
        LuaScript(L, "resources/class.lua").doFile();
        
        LuaScript animalScript(L, "resources/Animal.lua");
        Component animalComponent(&animalScript);
        Component animalComponent2(&animalScript);
        
        LuaScript humanScript(L, "resources/Human.lua");
        Component humanComponent(&humanScript);
        
        animalComponent.onLoop(); // aC1 = 1
        animalComponent.onLoop(); // aC1 = 2
        animalComponent2.onLoop(); // aC2 = 1
        
        humanComponent.getObject()->beginFunctionCall("humanStuff");
        animalComponent.getObject()->pushObject();
        humanComponent.getObject()->endFunctionCall(1, 0); // aC1 = 0
        
        animalComponent.onLoop(); // aC1 = 1
    
    }
    
    lua_close(L);
    
}

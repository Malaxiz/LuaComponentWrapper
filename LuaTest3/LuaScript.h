//
//  LuaScript.h
//  LuaTest3
//
//  Created by Didrik Munther on 15/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __LuaTest3__LuaScript__
#define __LuaTest3__LuaScript__

#include <stdio.h>
#include <string>

extern "C" {
# include "lua/lua.h"
# include "lua/lauxlib.h"
# include "lua/lualib.h"
}


class LuaScript {
    
public:
    LuaScript(lua_State* L, std::string path);
    
    int doFile();
    
    lua_State* getState();
    std::string getPath();
    
private:
    lua_State* _L;
    std::string _path;
    
};

#endif /* defined(__LuaTest3__LuaScript__) */

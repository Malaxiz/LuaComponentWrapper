//
//  LuaObject.h
//  LuaTest3
//
//  Created by Didrik Munther on 15/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __LuaTest3__LuaObject__
#define __LuaTest3__LuaObject__

#include <stdio.h>
#include <string>

#include "LuaScript.h"


class LuaObject {
    
public:
    LuaObject(LuaScript* script);
    ~LuaObject();
    
    void selectScript();
    void selectReference(std::string reference);
    
    void beginFunctionCall(std::string function);
    void endFunctionCall(int argc, int results);
    void endFunctionCall();
    
    void pushObject();
    
private:
    LuaScript* _script;
    lua_State* _L;
    const char* _path;
    int _objectReference;
    
    bool error;
    
};

#endif /* defined(__LuaTest3__LuaObject__) */

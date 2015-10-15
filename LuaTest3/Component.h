//
//  Component.h
//  LuaTest3
//
//  Created by Didrik Munther on 15/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __LuaTest3__Component__
#define __LuaTest3__Component__

#include <stdio.h>

#include "LuaObject.h"


class Component {
    
public:
    Component(LuaScript* script);
    
    void onLoop();
    
    LuaObject* getObject();
    
private:
    LuaObject _object;
    
};

#endif /* defined(__LuaTest3__Component__) */

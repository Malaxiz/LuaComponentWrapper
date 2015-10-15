//
//  Component.cpp
//  LuaTest3
//
//  Created by Didrik Munther on 15/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include "Component.h"


Component::Component(LuaScript* script)
    : _object(script)
{
    
}

void Component::onLoop() {
    _object.beginFunctionCall("onLoop");
    _object.endFunctionCall();
}

LuaObject* Component::getObject() {
    return &_object;
}
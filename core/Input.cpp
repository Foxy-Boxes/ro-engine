#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <bitset>
#include <iostream>
#include "Input.h"


    /*Keyboard and Mouse is nearly done mouse position will be added after vector2d is ready
    i guess*/
    Input::Input(SDL_Event* e) {
        m_event_pointer = e;
        KeyboardState = SDL_GetKeyboardState(&numkeys);
    }
    void Input::update(){
        KeyboardState = SDL_GetKeyboardState(&numkeys);
        for (int i = 0; i < numkeys; i++){
            keyboardbits[i] = KeyboardState[i];
        }
        MouseState = SDL_GetMouseState(&x,&y);
        for(int i = 0; i < 5; i++){
            mousebits[i] = MouseState&SDL_BUTTON(i);
        }

        pressedkeyboardbits = keyboardbits&(~lastkeyboardbits);
        releasedkeyboardbits = (~keyboardbits)&lastkeyboardbits;
        pressedmousebits = mousebits&(~lastmousebits);
        releasedmousebits = (~mousebits)&lastmousebits;

        lastkeyboardbits = keyboardbits;
        lastmousebits = mousebits;
    }
    bool Input::getKey(SDL_Scancode scancode){
        return keyboardbits[scancode];
    }
    bool Input::getKeyPressed(SDL_Scancode scancode){
        return pressedkeyboardbits[scancode];
    }
    bool Input::getKeyReleased(SDL_Scancode scancode){
        return releasedkeyboardbits[scancode];
    }
    bool Input::getMouse(Uint8 mb){
        return mousebits[mb];
    }
    bool Input::getMousePressed(Uint8 mb){
        return pressedmousebits[mb];
    }
    bool Input::getMouseReleased(Uint8 mb){
        return releasedmousebits[mb];
    }
    int Input::getMouseX(){
        return x;
    }
    int Input::getMouseY(){
        return y;
    }
    SingleUseString* Input::getPosStr(){
        SingleUseString openp("(");
        SingleUseString seperator(", ");
        SingleUseString closep(")");
        SingleUseString* retstr = new SingleUseString(&openp,x,&seperator,y,&closep);
        return retstr;
    }
    SingleUseString* Input::getPosStr(char sep){
        SingleUseString openp("(");
        char seps[] ={sep};
        SingleUseString seperator(seps);
        SingleUseString closep(")");
        SingleUseString* retstr = new SingleUseString(&openp,x,&seperator,y,&closep);
        return retstr;
    }
    SingleUseString* Input::getPosStr(const char* seps){
        SingleUseString openp("(");
        SingleUseString seperator(seps);
        SingleUseString closep(")");
        SingleUseString* retstr = new SingleUseString(&openp,x,&seperator,y,&closep);
        return retstr;
    }
    SingleUseString* Input::getPosStr(const char* op,const char* seps,const char* cl){
        SingleUseString openp(op);
        SingleUseString seperator(seps);
        SingleUseString closep(cl);
        SingleUseString* retstr = new SingleUseString(&openp,x,&seperator,y,&closep);
        return retstr;
    }
    Vector2d* Input::getPosVec(){
        Vector2d* mouseVec = new Vector2d(x,y);
        return mouseVec;
    }
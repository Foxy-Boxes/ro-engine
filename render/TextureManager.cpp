#include "TextureManager.h"

    TextureObj::TextureObj(const char* str,SDL_Renderer** r){
        SDL_Surface* surf = IMG_Load(str);
        texture = SDL_CreateTextureFromSurface(*r,surf);
        SDL_FreeSurface(surf);
        p_destR = new SDL_Rect();
        p_srcR = new SDL_Rect();
        p_destR -> x = 0;
        p_destR -> y = 0;

    }
    SDL_Texture* TextureObj::getTexture(){
        return texture;
    }
    TextureObj* TextureObj::setDest(int w,int h){
        p_destR -> w = w;
        p_destR -> h = h;
        return this;
    }
    TextureObj* TextureObj::setSrc(int w,int h){
        p_srcR -> w = w;
        p_srcR -> h = h;
        return this;
    }
    SDL_Rect* TextureObj::getSrc(){
        return p_srcR;
    }
    SDL_Rect* TextureObj::getDest(){
        return p_destR;
    }
    void TextureObj::updatePos(int X, int Y){
        p_destR -> x += X;
        p_destR -> y += Y;
    }
    void TextureObj::updatePosX(int X){
        p_destR -> x += X;
    }
    void TextureObj::updatePosY(int Y){
        p_destR -> y += Y;
    }
    void TextureObj::changePos(int X, int Y){
        p_destR -> x = X;
        p_destR -> y = Y;
    }
    void TextureObj::changePosX(int X){
        p_destR -> x = X;
    }
    void TextureObj::changePosY(int Y){
        p_destR -> y = Y;
    }



    TextureManager::TextureManager(Window* w){
        renderer = w ->getRendererPointer();
    }
    TextureManager::TextureManager(){
        renderer = NULL;
    }
    void TextureManager::render(){
        //SDL_RenderClear(*renderer);
        for (TextureObjArray::iterator it=textobjects.begin(); it<textobjects.end(); it++){
            SDL_RenderCopy(*renderer,(*it)->getTexture(),NULL,(*it) -> getDest());
        }
        //SDL_RenderPresent(*renderer);
    }
    void TextureManager::addTop(TextureObj* to){
        TextureObjArray::iterator it;
        it = textobjects.begin();
        textobjects.insert(it, to);
    }
    void TextureManager::addBottom(TextureObj* to){
        textobjects.push_back(to);
    }
    void TextureManager::addPos(TextureObj* to,int pos){
        TextureObjArray::iterator it;
        it = textobjects.begin();
        textobjects.insert(it + pos, to);
    }
    void TextureManager::popTop(){
        TextureObjArray::iterator it;
        it = textobjects.begin();
        textobjects.erase(it);
    }
    void TextureManager::popBottom(){
        textobjects.pop_back();
    }
    void TextureManager::popPos(int pos){
        TextureObjArray::iterator it;
        it = textobjects.begin();
        textobjects.erase(it + pos);
    }
    void TextureManager::popRange(int i,int j){
        TextureObjArray::iterator it;
        it = textobjects.begin();
        textobjects.erase(it + i,it + j);
    }
    TextureObj* TextureManager::getTexturefromPos(int i){
        TextureObjArray::iterator it;
        it = textobjects.begin();
        return *(it + i);
    }
    TextureObj* TextureManager::createTexture(const char* str){
        TextureObj* retObj = new TextureObj(str, renderer);
        return retObj;
    }
    void TextureManager::setRenderer(Window* w){
        renderer = w -> getRendererPointer();
    }
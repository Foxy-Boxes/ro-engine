#include <vector>
#include "Window.h"
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>

class TextureObj
{
private:
    /* data */
    
    SDL_Texture* texture; 
    SDL_Rect *p_destR, *p_srcR; 

public:
    TextureObj(const char*, SDL_Renderer**);
    TextureObj* setDest(int, int);
    TextureObj* setSrc(int, int);
    void updatePos(int, int);
    void updatePosX(int);
    void updatePosY(int);
    void changePos(int, int);
    void changePosX(int);
    void changePosY(int);
    SDL_Rect* getSrc();
    SDL_Rect* getDest();
    SDL_Texture* getTexture();
};
using TextureObjArray = std::vector<TextureObj*>;
class TextureManager
{
private:
    /* data */
    TextureObjArray textobjects;
    SDL_Renderer** renderer;

public:
    TextureManager(Window*);
    TextureManager();
    void render();
    void addTop(TextureObj*);
    void addBottom(TextureObj*);
    void addPos(TextureObj*,int);
    void popTop();
    void popBottom();
    void popPos(int);
    void popRange(int,int);
    TextureObj* getTexturefromPos(int);
    TextureObj* createTexture(const char*);
    void setRenderer(Window*);
    /*TODO convert this to linked list, no one will be sorting them, easy shuffle
    is better.*/
};






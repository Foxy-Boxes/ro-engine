# sigma-engine
WIP
## INSTALL Dependencieeeeees
Arch based os
```shell
pacman -S sdl2 sdl2_image
```
Debian based os
```shell
apt-get install libsdl2-dev libsdl2-image-dev
```
Based os
```shell
yum install SDL2-devel SDL2_image-devel
```
================================================
```shell
cd core
g++ main.cpp -lSDL2 Input.cpp Time.cpp Vector2d.cpp Vector3d.cpp ../tools/Log.cpp ../tools/SingleUseString.cpp ../render/Window.cpp ../render/TextureManager.cpp -lSDL2_image
./a.out
```
Try it handsome!

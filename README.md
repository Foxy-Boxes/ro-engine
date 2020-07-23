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
------------------------------------------------
# To try the plain implementation of meshes
```shell
cd core
g++ main.cpp -lSDL2 Input.cpp Time.cpp math/Vector2d.cpp math/Vector3d.cpp ../tools/Log.cpp ../tools/SingleUseString.cpp ../render/Window.cpp ../render/TextureManager.cpp math/Mesh.cpp math/Matrix44.cpp math/Vertex.cpp math/Triangle.cpp -lSDL2_image -std=c++17
./a.out
```
------------------------------------------------
# To try the new implementation of meshes
```shell
cd core
g++ main_new.cpp -lSDL2 Input.cpp Time.cpp math/Vector2d.cpp math/Vector3d.cpp ../tools/Log.cpp ../tools/SingleUseString.cpp ../render/Window.cpp ../render/TextureManager.cpp math/Mesh_new.cpp math/Matrix44.cpp math/Vertex.cpp -lSDL2_image -std=c++17
./a.out
```
Remember that this will replace any old a.out
------------------------------------------------
# To benchmark and compare meshes
```shell
cd core
g++ benchmark_old.cpp -lSDL2 Input.cpp Time.cpp math/Vector2d.cpp math/Vector3d.cpp ../tools/Log.cpp ../tools/SingleUseString.cpp ../render/Window.cpp ../render/TextureManager.cpp math/Mesh.cpp math/Matrix44.cpp math/Vertex.cpp math/Triangle.cpp -lSDL2_image -std=c++17 -o bench_old.out
g++ benchmark_new.cpp -lSDL2 Input.cpp Time.cpp math/Vector2d.cpp math/Vector3d.cpp ../tools/Log.cpp ../tools/SingleUseString.cpp ../render/Window.cpp ../render/TextureManager.cpp math/Mesh_new.cpp math/Matrix44.cpp math/Vertex.cpp -lSDL2_image -std=c++17 -o bench_new.out
./bench_old.out
./bench_new.out
```
Try it handsome!

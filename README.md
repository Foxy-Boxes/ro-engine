# ro-engine
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
The new implementation is basically a very basic allocator that takes the stack's end position as a hint and allocates the whole block for meshes. This gives a 10% increase on my computer with the spaceship and nearly no increase with the cube. A better version would be to allocate once and have an allocator to distribute the handles, currently I'm hinting the previous handle for a new allocation.

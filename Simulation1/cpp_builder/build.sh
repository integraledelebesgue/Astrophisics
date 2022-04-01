#!bin/bash
echo "Constructing C++ shared library.."
cd ../Elements
g++ -shared -fPIC Vector.h Body.h Node.h Quadtree.h Physics.h barnes-hut.h memory.h Vector.cpp Body.cpp Node.cpp Quadtree.cpp Physics.cpp barnes-hut.cpp memory.cpp -o barneshut.so

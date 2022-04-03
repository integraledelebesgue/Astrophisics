#!bin/bash
echo "Constructing C++ shared library.."
cd ../Elements

g++ -O3 -Wall -shared -fPIC $(python3 -m pybind11 --includes) Vector.h Body.h Node.h Quadtree.h Physics.h barnes-hut.h memory.h Vector.cpp Body.cpp Node.cpp Quadtree.cpp Physics.cpp barnes-hut.cpp memory.cpp python_interface.cpp -o barneshut.so

cp -v ./barneshut.so ../

echo "Finished!"

#!bin/bash
echo "Constructing C++ shared library.."
cd ../Elements

g++ -O3 -Wall -shared -fPIC -I /home/jsmolka/anaconda3/lib/python3.9/site-packages/pybind11/include/pybind11 -I /home/jsmolka/anaconda3/include/python3.9 Vector.h Body.h Node.h Quadtree.h Physics.h barnes-hut.h memory.h Vector.cpp Body.cpp Node.cpp Quadtree.cpp Physics.cpp barnes-hut.cpp memory.cpp python_interface.cpp -o barneshut.so

cp -v ./barneshut.so ../

echo "Finished!"

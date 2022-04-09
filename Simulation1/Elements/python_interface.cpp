#include</home/jsmolka/virtual_env/lib/python3.8/site-packages/pybind11/include/pybind11/pybind11.h>
#include</home/jsmolka/virtual_env/lib/python3.8/site-packages/pybind11/include/pybind11/stl.h>
#include<python3.8/Python.h>
#include "barnes-hut.h"

using namespace pybind11;

PYBIND11_MODULE(barneshut, m){
    //m.doc() = "Barnes-Hut algorithm for force computation.";
    m.def("getForces", &getForces, "Computes global resultant forces for each body given.", arg("state_array"), arg("count"), arg("radius"), arg("accuracy"));
}

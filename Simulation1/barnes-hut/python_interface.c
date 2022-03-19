#include<Python.h>
#include<stddef.h>
#include<malloc.h>
#include "headers.h"

static PyObject* computeForces(PyObject *self, PyObject *args){
    int count;
    double **state = (double **)malloc(count*sizeof(double));
    double accuracy;

    if(!PyArg_ParseTuple(args, "y*id", state, &count, &accuracy)){
        return NULL;
    }

    double **forces = perform(count, state, accuracy);
}


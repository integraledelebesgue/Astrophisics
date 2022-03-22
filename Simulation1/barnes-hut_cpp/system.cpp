#include "headers.h"
#include<iostream>

extern double threshold;

using namespace std;

void arrayToBody(double **arr, Body *bodies, int count){
    for(int i=0; i<count; i++){
        bodies[i].mass = arr[i][0];
        bodies[i].position.x = arr[i][1];
        bodies[i].position.y = arr[i][2];
    }
}

void vectorToArray(Vector *vec, double **arr, int count){
    for(int i=0; i<count; i++){
        arr[i][0] = vec[i].x;
        arr[i][1]  =vec[i].y;
    }
}

double **perform(double **state, int count, double radius, double accuracy){
    threshold = accuracy;

    double **force_arr = nullptr;
    Vector forces[count];
    Body bodies[count];

    puts("Converting to bodies.. ");
    arrayToBody(state, bodies, count);

    Node root(count, 2*radius, Vector(0, 0), bodies);

    puts("Constructing tree..");
    constructTree(root);

    cout << "Constructing resultant array..";
    force_arr = new double*[count];
    for(int i=0; i<count; i++){
        force_arr[i] = new double[2];
    }
    cout << "Resultant array ready!";

    puts("Computing forces.. ");
    computeForces(forces, root);

    puts("Converting results to array..");
    vectorToArray(forces, force_arr, count);

    return force_arr;
}

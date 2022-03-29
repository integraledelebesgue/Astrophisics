#include <iostream>
#include "Body.h"
#include "Vector.h"
#include "Node.h"
#include "Quadtree.h"
#include "Physics.h"
#include "barnes-hut.h"
#include<list>
#include<fstream>
#include<chrono>

using namespace std;

extern double threshold;

double **perform(double **state, int count, double radius, double accuracy){
    Vector *result;
    list<Body> bodies;
    threshold = accuracy;

    cout << "Computation starting.. " << endl;

    //printArr(state, count);

    auto start = chrono::high_resolution_clock::now();

    result = new Vector[count];

    double **result_arr = new double *[count];

    for(int i=0; i<count; i++){
        result_arr[i] = new double[2];
    }

    cout << "Conversion.. " << endl;

    stateToBody(state, bodies, count);

    Node root(radius, Vector(), bodies);

    cout << "Tree construction.." << endl;

    constructTree(root);

    cout << "Force computation.. " << endl;

    computeForces(root, result);

    cout << "Conversion.. " << endl;

    vectorToArr(result_arr, result, count);

    cout << "Done!" << endl;

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    ofstream log;
    log.open("stats.txt", ios::app);

    log << "Computing ";
    log << count << " bodies with accuracy ";
    log << accuracy << " took ";
    log << duration.count() << " µs" << endl;

    log.close();

    delete[](result);

    return result_arr;
}


void vectorToArr(double **arr, Vector *vectors, int count){
    for(int i=0; i<count; i++){
        arr[i][0] = vectors[i].x;
        arr[i][1] = vectors[i].y;
    }
}

void printArr(double **arr, int count){
    printf("{\n");
    for(int i=0; i<count; i++){
        printf("[%lf, %lf, %lf]\n", arr[i][0], arr[i][1], arr[i][2]);
    }
    printf("}\n");
}

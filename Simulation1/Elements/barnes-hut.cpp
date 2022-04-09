#include <iostream>
#include "Body.h"
#include "Vector.h"
#include "Node.h"
#include "Quadtree.h"
#include "Physics.h"
#include "barnes-hut.h"
#include "memory.h"
#include<list>
#include<vector>
#include<fstream>
#include<chrono>

using namespace std;
//double threshold;
//std::stack<void *> *memStack;

vector<vector<double>> getForces(const vector<vector<double>> &state, int count, double radius, double accuracy){
    Vector *result;
    list<Body> bodies;
    threshold = accuracy;

    cout << "Computation starting.. " << endl;

    //printArr(state, count);

    auto start = chrono::high_resolution_clock::now();

    result = new Vector[count];
    memStack = new std::stack<void *>;

    /*double **result_arr = new double *[count];

    for(int i=0; i<count; i++){
        result_arr[i] = new double[2];
    }*/

    vector<vector<double>> result_arr(count);

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

    root.traverse(printNode);

    cout << "Cleaning up memory.. ";

    freeMemory();

    cout << "Memory stack: ";
    cout << memStack->size() << endl;

    delete(memStack);

    return result_arr;
}

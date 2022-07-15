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

vector<vector<double>> getForces(const vector<vector<double>> &state, int count, double radius, double accuracy){
    Vector *result;
    list<Body> bodies;
    threshold = accuracy;

    auto start = chrono::high_resolution_clock::now();

    result = new Vector[count];
    memStack = new std::stack<void *>;

    vector<vector<double>> result_arr(count);

    stateToBody(state, bodies, count);

    Node root(radius, Vector(), bodies);

    constructTree(root);
    computeForces(root, result);
    vectorToArr(result_arr, result, count);

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
    freeMemory();
    delete(memStack);

    return result_arr;
}

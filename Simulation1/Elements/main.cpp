#include <iostream>
#include "Body.h"
#include "Vector.h"
#include "Node.h"
#include "Quadtree.h"
#include "Physics.h"
#include "barnes-hut.h"
#include<list>
#include<cmath>
#include<chrono>

//extern double threshold;

using namespace std;

int main(){
    int i, count = 10000;
    double radius = 100000;
    double *state[count];
    double accuracy = 0.1;
    //Vector result[count];

    //threshold = 0.3;

    srandom(time(nullptr));

    auto start = chrono::high_resolution_clock::now();

    for(i=0; i<count; i++){
        state[i] = new double[3];
        state[i][0] = 10.0 + (double)(random()%100);
        state[i][1] = pow(-1, random()+1)*(double)(random()%(int)radius);
        state[i][2] = pow(-1, random())*(double)(random()%(int)radius);
    }

    cout << "Initializing.. ";

    //printArr(state, count);

    cout << "Done! " << endl;

    /*list<Body> bodies;

    cout << "Conversion:" << endl;

    stateToBody(state, bodies, count);

    for(const auto &body : bodies){
        printf("mass: %lf, position: (%lf, %lf)\n", body.mass, body.position.x, body.position.y);
    }

    for(i=0; i<count; i++) delete(state[i]);

    list<Body> test;
    test.emplace_back(100, Vector(-1, -5));

    //Node *node = new Node(1.0, Vector(), test);

    //test.pop_back();

    //printNode(*node);


    cout << endl << "Root node:" << endl;

    Node root(100.0, Vector(), bodies);

    root.traverse(printNode);

    cout << "Constructing tree.." << endl;

    constructTree(root);

    cout << endl << "Tree constructed!" << endl;

    //root.traverse(printNode);

    cout << endl << "Computing forces.." << endl;

    computeForces(root, result);

    cout << endl << "Resultant forces: " << endl;

    for(i=0; i<count; i++)
        printf("[%lf, %lf]\n", result[i].x, result[i].y);

    cout << endl;

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Procedure took ";
    cout << duration.count() << " microseconds" << endl;*/

    double **result = perform(state, count, radius, accuracy);
    //printArr(result, count);

    return 0;
}

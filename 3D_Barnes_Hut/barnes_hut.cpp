#include "Vector.h"
#include "Body.h"
#include "Node.h"
#include "Physics.h"
#include "Quadtree.h"
#include<list>
#include<vector>
#include<array>
#include<fstream>
#include<chrono>
#include<stack>

using namespace std;

void freeMemory(stack<Node *> &st){
    while(!st.empty())
        free(st.top());
        st.pop();
}

vector<array<double, 3>> computeForces(const vector<array<double, 4>> &bodies, double radius, double accuracy){
    stack<Node *> mem_stack;
    vector<array<double, 3>> result;
    int count = 0;

    auto start = chrono::high_resolution_clock::now();

    Node *root = new Node{Vector(), radius, list<Body>()};
    mem_stack.push(root);

    for(Body body : bodies){
        root->bodies.push_back(body);
        count++;
    }

    buildTree(*root, mem_stack);
    computeResultants(*root, result, accuracy);

    freeMemory(mem_stack);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    ofstream log;
    log.open("stats.txt", ios::app);

    log << "Computing ";
    log << count << " bodies with accuracy ";
    log << accuracy << " took ";
    log << duration.count() << " µs" << endl;

    return result;
}
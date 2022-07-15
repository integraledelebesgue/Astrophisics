#include "Quadtree.h"
#include "Body.h"
#include "Node.h"
#include<stack>
#include<vector>

using namespace std;


void buildTree(Node &root, stack<Node *> &memory_stack){
    stack<Node *> Stack;
    vector<Node *> processed;
    Node *curr;

    Stack.push(&root);

    while(!Stack.empty()){
        curr = Stack.top();

        divideNode(*curr, processed);
        
        while(processed.size()){
            if(!processed.back()->trivial()) Stack.push(processed.back());
            memory_stack.push(processed.back());
            processed.pop_back();
        }

        Stack.pop();
    }
}

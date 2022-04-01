#include "memory.h"
#include "barnes-hut.h"
#include<cstdlib>
#include "Node.h"

double threshold;
std::stack<void *> *memStack;

void freeMemory(){
    while(!memStack->empty()){
        delete((Node *)memStack->top());
        memStack->pop();
    }
}
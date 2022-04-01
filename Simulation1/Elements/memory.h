#ifndef ELEMENTS_MEMORY_H
#define ELEMENTS_MEMORY_H

#include<stack>

extern std::stack<void *> *memStack;
extern double threshold;

void freeMemory();

#endif //ELEMENTS_MEMORY_H

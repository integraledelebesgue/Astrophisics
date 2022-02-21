#include "headers.h"
#include<stdbool.h>
#include<malloc.h>


//tree traversal function with any given action performed:
void traverse(Node *root, body *(*action)(body *chunk)){
    Stack *stack = construct_stack(8);

}


// tree construction - get a whole system and divide it to a single or empty chunks:
void construct_tree(long length, body *bodies, Node *root){
    Stack *stack = construct_stack(length/2);

}

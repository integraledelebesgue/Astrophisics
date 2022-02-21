#include "headers.h"


//tree traversal function with any pointer-given action performed:
void traverse(Node *root, body *(*action)(Node *chunk)){
    Stack *stack = construct_stack(4, 'n');
    push(stack, root);

    while(!empty(stack)){
        Node *curr = pop(stack);
        if(curr){
            action(curr);
            if(curr->NW) push(stack, curr->NW);
            if(curr->NE) push(stack, curr->NE);
            if(curr->SW) push(stack, curr->SW);
            if(curr->SE) push(stack, curr->SE);
        }
    }
}


// tree construction - get a whole system and divide it to a single or empty chunks:
void construct_tree(long length, body *bodies, Node *root){
    Stack *stack = construct_stack(4, 'b');

}

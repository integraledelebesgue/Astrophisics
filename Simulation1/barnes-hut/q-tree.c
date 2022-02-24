#include "headers.h"

//TODO: replace simple parent->children node structure with more memory-effective - parent->child->brothers
void traverse(node *root, body *(*action)(node *chunk)){
    /// Traverses the quadtree with any pointer-given action function performed.
    stack *stack = construct_stack(4);
    push(stack, (void *)root);

    while(!empty(stack)){
        node *curr = (node *)pop(stack);
        if(curr){
            action(curr);
            if(curr->NW) push(stack, (void *)curr->NW);
            if(curr->NE) push(stack, (void *)curr->NE);
            if(curr->SW) push(stack, (void *)curr->SW);
            if(curr->SE) push(stack, (void *)curr->SE);
        }
    }
}


// tree construction - get a whole system and divide it to a single or empty chunks:
void construct_tree(long length, body *bodies, node *root){
    /// Construct the division quadtree from any pointer-given body list.
    stack *stack = construct_stack(4);

}

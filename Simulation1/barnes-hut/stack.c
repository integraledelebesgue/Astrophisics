#include "headers.h"
#include<stdbool.h>
#include<malloc.h>
#include<stdlib.h>

int default_opt(int x){
    return 2*x; // optimal for quadtree traverse function
}

int (*opt)(int) = default_opt; // TODO: optimization function dependent on system's density, for balanced stack extending

// simple universal stack control functions (any items stored must be void *):

stack *construct_stack(int cap){
    /// Allocates memory and returns a pointer to a stack.
    puts("  Constructing stack..");
    stack *st = (stack *)malloc(sizeof(stack));
    st->capacity = cap;
    st->size = 0;
    st->items = (void *)malloc(cap*sizeof(void));

    return st;
}

void extend_stack(stack *st, int (*opt_fun)(int)){
    /// Reallocates memory and expands the stack's capacity memory-optimally using opt_fun.
    puts("  Reallocating..");
    //st->capacity = opt_fun(st->capacity); // TODO: memory-optimal size extension
    st->capacity = st->capacity*2;
    st->items = (void **)realloc(st->items, st->capacity*sizeof(void **));
}

bool empty(stack *st){
    if(st->size == 0) return true;
    return false;
}

void push(stack *st, void *new_item){
    /// Pushes all the possible types of elements, casted to a void *.
    //puts("      Pushing..");
    if(st->size == st->capacity){
        extend_stack(st, opt);
    }

    st->items[++st->size] = new_item;
}

void *pop(stack *st){
    /// Pops an element. All the elements popped must be casted to a proper type.
    //puts("      Popping!");
    if(empty(st)){
        free(st->items); // only the empty stack is no longer needed
        return NULL;
    }

    return st->items[st->size--];
}

void print_bodies(stack *st){
    puts("Bodies on stack:");

    for(int i=0; i<st->size; i++){
        puts("In loop..");
        void *curr_v = st->items[i];
        body *curr = (body *)curr_v;
        printf("[%lf, %lf, %lf]", curr->mass, curr->position.x, curr->position.y);
    }
    //free(curr);
}

#include "headers.h"
#include<stdbool.h>
#include<malloc.h>

long default_opt(long x){
    return 2*x; // optimal for quadtree traverse function
}

long (*opt)(long) = default_opt; // optimization function dependent on system's density, for balanced stack extending (TODO)

// simple universal stack control functions (any items stored must be void *):

stack *construct_stack(long cap){
    stack *st = (stack *)malloc(sizeof(stack));
    st->capacity = cap;
    st->size = 0;
    st->items = (void *)malloc(cap*sizeof(void));

    return st;
}

void extend_stack(stack *st, long (*opt_fun)(long)){
    st->capacity = opt_fun(st->capacity); // memory-optimal size extension (TODO)
    st->items = (void **)realloc(st->items, st->capacity*sizeof(void));
}

bool empty(stack *st){
    if(st->size == 0) return true;
    return false;
}

void push(stack *st, void *new_item){
    if(st->size == st->capacity){
        extend_stack(st, opt);
    }

    st->items[++st->size] = new_item;
}

void *pop(stack *st){
    if(!empty(st)){
        free(st->items); // only the empty stack is no longer needed
        return NULL;
    }

    return st->items[st->size--];
}

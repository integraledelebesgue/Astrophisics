#include "headers.h"
#include<stdbool.h>
#include<malloc.h>

long default_opt(long x){
    return (long)(1.25*(double)x);
}

long (*opt)(long) = default_opt; // optimization function dependent on system's density, for balanced stack extending (TODO)

// simple stack control functions:

Stack *construct_stack(long cap){
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->capacity = cap;
    st->size = 0;
    st->bodies = (body **)malloc(st->capacity*sizeof(body));

    return st;
}

void extend_stack(Stack *st, long (*opt_fun)(long)){
    st->capacity = opt_fun(st->capacity); // memory-optimal extension (TODO)
    st->bodies = (body **)realloc(st->bodies, st->capacity*sizeof(body));
}

bool empty(Stack *st){
    if(st->size == 0){
        return true;
    }
    return false;
}

void push(Stack *st, body *new_bodies){
    if(st->size == st->capacity){
        extend_stack(st, opt);
    }

    st->bodies[++st->size] = new_bodies;
}

body *pop(Stack *st){
    if(!empty(st)){
        free(st->bodies); // only the empty stack is no longer needed
        return NULL;
    }

    return st->bodies[st->size--];
}




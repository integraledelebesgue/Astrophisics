#include "headers.h"
#include<stdbool.h>
#include<malloc.h>

long default_opt(long x){
    return 2*x;
}

long (*opt)(long) = default_opt; // optimization function dependent on system's density, for balanced stack extending (TODO)

// simple stack control functions:

Stack *construct_stack(long cap){
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->capacity = cap;
    st->size = 0;
    st->items = (Node **)malloc(st->capacity*sizeof(Node));

    return st;
}

void extend_stack(Stack *st, long (*opt_fun)(long)){
    st->capacity = opt_fun(st->capacity); // memory-optimal extension (TODO)
    st->items = (Node **)realloc(st->items, st->capacity*sizeof(Node));
}

bool empty(Stack *st){
    if(st->size == 0){
        return true;
    }
    return false;
}

void push(Stack *st, Node *new_item){
    if(st->size == st->capacity){
        extend_stack(st, opt);
    }

    st->items[++st->size] = new_item;
}

Node *pop(Stack *st){
    if(!empty(st)){
        free(st->items); // only the empty stack is no longer needed
        return NULL;
    }

    return st->items[st->size--];
}




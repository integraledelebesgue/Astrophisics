#include "headers.h"
#include<stdbool.h>
#include<malloc.h>

long default_opt(long x){
    return 2*x;
}

long (*opt)(long) = default_opt; // optimization function dependent on system's density, for balanced stack extending (TODO)

// simple stack control functions:

Stack *construct_stack(long cap, char type){
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->capacity = cap;
    st->size = 0;
    if(type == 'b') {
        (body **)(st->items);
        st->items = (body **)malloc(st->capacity*sizeof(body));
        st->type = 'b';
    }
    else
    {
        (Node *)st->items;
        st->items = (Node *)malloc(st->capacity*sizeof(Node));
        st->type = 'n';
    }

    return st;
}

void extend_stack(Stack *st, long (*opt_fun)(long)){
    st->capacity = opt_fun(st->capacity); // memory-optimal extension (TODO)
    if(st->type == 'n') st->items = (Node *)realloc(st->items, st->capacity*sizeof(Node));
    else st->items = (body **)realloc(st->items, st->capacity*sizeof(body));
}

bool empty(Stack *st){
    if(st->size == 0){
        return true;
    }
    return false;
}

void push(Stack *st, void *new_item){
    if(st->size == st->capacity){
        extend_stack(st, opt);
    }

    st->items[++st->size] = new_item;
}

void *pop(Stack *st){
    if(!empty(st)){
        free(st->items); // only the empty stack is no longer needed
        return NULL;
    }

    return st->items[st->size--];
}




#include <math.h>
#include <malloc.h>
#include<stdbool.h>
#include "headers.h"

//stack control functions:

Stack *construct_stack(){
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->top = -1;
    st->bodies[0] = (body *)malloc(sizeof(body));
    return st;
}

bool empty(Stack *st){
    if(st->top == -1){
        return true;
    }
    return false;
}

void push(Stack *st, body *new_bodies){
    st->bodies[++st->top] = new_bodies; // nie wiem czy prefiksowe dodawanie "++" zmienia wartość st->top.
    realloc(st->bodies, ((st->top) + 1)*sizeof(body)); // nie wiem czy top jest tyle co był czy top+1?
}

body *pop(Stack *st){
    if(!empty(st)){
        return 0;
    }
}



// real type 2-dim raw state array to body type list:
body *construct_system(long length, double **state){
    body *bodies = (body *)malloc(length*sizeof(body));

    for(long i=0; i<length; i++){
        bodies[i].mass = state[i][0];
        bodies[i].position.x = state[i][1];
        bodies[i].position.y = state[i][2];
    }

    return bodies;
}

// get a whole system and divide it to a single or empty chunks:
void construct_tree(body *bodies, Node *root){


}
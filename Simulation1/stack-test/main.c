#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct{
   int x, y;
} point;

typedef struct{
    double x, y, z;
} vector;

typedef struct{
    int size;
    int capacity;
    void **items;

} stack;

bool empty(stack *st){
    if(st->size == 0) return true;
    return false;
}

bool full(stack *st){
    if(st->size == capacity) return true;
    return false;
}

void push(stack *st, void *item){
    if(!full(st)) st->items[++st->size] = item;
}

void *pop(stack *st){
    if(!empty(st)) return st->items[st->size--];
    return NULL;
}

int main(){
    int cap = 2;
    stack *Stack = (stack *)malloc(sizeof(stack));
    Stack->size = 0;
    Stack->capacity = cap;
    Stack->items = (void **)malloc(cap*sizeof(void));

    point A, B;
    A.x = 1;
    A.y = 2;
    B.x = 10;
    b.y = 3;

    vector u, v;
    u.x = 1.2;
    u.y = 3.7;
    u.z = 4.20;
    v.x = 1.11;
    v.y = 7.1;
    v.z = 1.1;

    push(Stack, A);
    push(Stack, B);

    point *a = (point *)pop(Stack);
    point *b = (point *)pop(Stack);

    printf("Punkty: %d, %d, %d, %d", a->x, a->y, b->x, b->y);

    return 0;
}

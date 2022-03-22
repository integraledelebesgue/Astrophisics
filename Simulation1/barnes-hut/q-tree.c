#include "headers.h"
//#include<stdlib.h>
#include <stdio.h>
#include<malloc.h>
#include<stdbool.h>

//TODO: replace simple parent->children node structure with more memory-effective - parent->child->brothers
void traverse(node *root, void (*action)(node *chunk)){
    /// Traverses the quadtree with any pointer-given action function performed.
    stack *Stack = (stack *)malloc(sizeof(stack *));

    construct_stack(Stack, 5);

    push(Stack, (void *)root);

    while(!empty(Stack)){
        node *curr = (node *)pop(Stack);
        if(curr){
            action(curr);
            if(curr->NW) push(Stack, (void *)curr->NW);
            if(curr->NE) push(Stack, (void *)curr->NE);
            if(curr->SW) push(Stack, (void *)curr->SW);
            if(curr->SE) push(Stack, (void *)curr->SE);
        }
    }

    free(Stack->items);
    free(Stack);
}

node *new_node(node *parent, stack *st, int count, double size, vector centre){
    /// Allocate the memory for a new quadtree node, then write down the list of bodies to that node.
    node *child = (node *)malloc(sizeof(node));

    child->bodies = (body *)malloc(count*sizeof(body));
    child->parent = parent;
    //child->bodies = bodies;
    for(int i=0; i<count; i++){
        child->bodies[i] = *((body *)pop(st));
    }

    child->count = count;
    child->size = size;
    child->centre = centre;
    child->pseudo_body = compute_mass_centre(count, child->bodies);

    puts("      NEW NODE:");
    print_node(child);

    return child;
}

// tree construction - get a whole system and divide it into single or empty chunks:
void construct_tree(node *root){  // TODO: new division.
    /// Construct the division quadtree from any system represented by a root node.
    vector new_centre;
    node *curr;

    stack *Stack = (stack *)malloc(sizeof(stack));
    puts("Stack allocated");

    stack st;
    stack *pst = &st;

    construct_stack(Stack, 4);

    push(Stack, (void *)root);

    printf("Root: %d\n", root->count);

    stack *NW = (stack *)malloc(sizeof(stack));
    stack *NE = (stack *)malloc(sizeof(stack));
    stack *SW = (stack *)malloc(sizeof(stack));
    stack *SE = (stack *)malloc(sizeof(stack));

    construct_stack(NW, 2);
    construct_stack(NE, 2);
    construct_stack(SW, 2);
    construct_stack(SE, 2);

    while(!empty(Stack)){
        puts("In loop!");

        curr = (node *)pop(Stack);

        printf("%p\n", curr);
        printf("Current count: %d", curr->count);

        qualify(curr, NW, NE, SW, SE);

        puts("Qualified!");

        if(!empty(NW)){
            new_centre.x = (curr->centre.x-(curr->size/4));
            new_centre.y = (curr->centre.y+(curr->size/4));
            curr->NW = new_node(curr, NW, NW->size, curr->size/2, new_centre);
            if(curr->NW->count > 1) push(Stack, curr->NW);
        }

        if(!empty(NE)){
            new_centre.x = (curr->centre.x+(curr->size/4));
            new_centre.y = (curr->centre.y+(curr->size/4));
            curr->NE = new_node(curr, NE, NE->size, curr->size/2, new_centre);
            if(curr->NE->count > 1) push(Stack, curr->NE);
        }

        if(!empty(SW)){
            new_centre.x = (curr->centre.x-(curr->size/4));
            new_centre.y = (curr->centre.y-(curr->size/4));
            curr->SW = new_node(curr, SW, SW->size, curr->size/2, new_centre);
            if(curr->SW->count > 1) push(Stack, curr->SW);
        }

        if(!empty(SE)){
            new_centre.x = (curr->centre.x+(curr->size/4));
            new_centre.y = (curr->centre.y-(curr->size/4));
            curr->SE = new_node(curr, SE, SE->size, curr->size/2, new_centre);
            if(curr->SE->count > 1) push(Stack, curr->SE);
        }

        puts("");
        puts("QUADTREE:");
        traverse(root, print_node);
        puts("");
    }

    free(NW->items);
    free(NE->items);
    free(SW->items);
    free(SE->items);

    free(NW);
    free(NE);
    free(SW);
    free(SE);

    free(curr);
}

void qualify(node *curr, stack *NW, stack *NE, stack *SW, stack *SE){
    puts("     Qualifying..");
    printf("    Node count: %d", curr->count);

    for(int i = 0; i < curr->count; i++){
        puts("          In loop..");
        if(curr->bodies[i].position.x - curr->centre.x > 0 && curr->bodies[i].position.y - curr->centre.y > 0) push(NE, (void *)&(curr->bodies[i]));
        if(curr->bodies[i].position.x - curr->centre.x > 0 && curr->bodies[i].position.y - curr->centre.y < 0) push(SE, (void *)&(curr->bodies[i]));
        if(curr->bodies[i].position.x - curr->centre.x < 0 && curr->bodies[i].position.y - curr->centre.y > 0) push(NW, (void *)&(curr->bodies[i]));
        if(curr->bodies[i].position.x - curr->centre.x < 0 && curr->bodies[i].position.y - curr->centre.y < 0) push(SW, (void *)&(curr->bodies[i]));
    }

    /*print_bodies(NW);
    print_bodies(NE);
    print_bodies(SW);
    print_bodies(SE);*/

}

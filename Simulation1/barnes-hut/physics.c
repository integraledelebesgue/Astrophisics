#include "headers.h"
#include<math.h>
#include<malloc.h>

double threshold;

body compute_mass_centre(int count, body *bodies){
    /// Computes the centre of mass for the body list given.
    vector centre;
    double total_mass = 0;

    for(int i = 0; i<count; i++){
        centre.x = bodies[i].mass*bodies[i].position.x;
        centre.y = bodies[i].mass*bodies[i].position.y;
        total_mass += bodies[i].mass;
    }

    printf("Total mass of %d bodies: %lf\n", count, total_mass);

    centre.x /= total_mass;
    centre.y /= total_mass;

    body pseudobody = {.mass = total_mass, .position = centre};

    return pseudobody;
}

vector compute_force(body particle, body source){
    /// Returns a force vector representing gravity affected on "particle" by "source.
    double d = distance(particle.position, source.position);

    double scalar_force = pow(10, -11)*6.67*particle.mass*source.mass/(d*d);

    vector force_vector = {.x = scalar_force*(source.position.x - particle.position.x)/d, .y = scalar_force*(source.position.y - particle.position.y)/d};

    return force_vector;
}

double distance(vector a, vector b){
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

void add(vector *to, vector from){
    to->x += from.x;
    to->y += from.y;
}

void compute_forces(double **forces, node *root, int count){
    //printf("Count: %d\n", count);
    puts("Allocating force vectors..");
    //vector *forces = (vector *)malloc(count*sizeof(vector));

    vector *v_forces = (vector *)malloc(count*sizeof(vector));

    puts("Force vectors initialized!");

    for(int i = 0; i < count; i++){
        puts("      In loop!");
        v_forces[i] = resultant_force(root, i);
    }

    puts("Transforming vectors to array..");

    forces = vector_to_array(v_forces, count);

    free(v_forces);

    puts("Done!");

    //return vector_to_array(forces, count);
}

vector resultant_force(node *root, int i){
    /// Go through all the bodies and calculate resultant force for each, traversing the quadtree.
    stack *Stack = (stack *)malloc(sizeof(stack));
    construct_stack(Stack, 4);
    push(Stack, (void *)root);

    double scale;
    double dist;
    vector result;
    node *curr;

    while(!empty(Stack)){
        curr = (node *)pop(Stack);
        if(curr){
            if((dist = distance(root->bodies[i].position, curr->pseudo_body.position))){
                scale = curr->size/dist;
                if(scale <= threshold) add(&result, compute_force(root->bodies[i], curr->pseudo_body));
                else{
                    if(curr->NW) push(Stack, (void *)curr->NW);
                    if(curr->NE) push(Stack, (void *)curr->NE);
                    if(curr->SW) push(Stack, (void *)curr->SW);
                    if(curr->SE) push(Stack, (void *)curr->SE);
                }
            }
        }
    }

    free(Stack->items);
    free(Stack);
    return result;
}

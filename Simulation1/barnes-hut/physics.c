#include "headers.h"
#include<math.h>
#include<malloc.h>

double threshold;

body compute_mass_centre(int count, body *bodies){
    /// Computes the centre of mass for the body list given.
    vector centre;
    double total_mass;
    for(int i = 0; i<count; i++){
        centre.x = bodies[i].mass*bodies[i].position.x;
        centre.y = bodies[i].mass*bodies[i].position.y;
        total_mass += bodies[i].mass;
    }

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

double **compute_forces(node *root, int count){
    vector *forces = (vector *)malloc(count * sizeof(vector));

    for(int i = 0; i < count; i++){
        forces[i] = resultant_force(root, i);
    }

    return vector_to_array(forces, count);
}

vector resultant_force(node *root, int i){
    /// Go through all the bodies and calculate resultant force for each, traversing the quadtree.
    stack *stack = construct_stack(4);
    push(stack, (void *)root);

    double scale;
    double dist;
    vector result;
    node *curr;

    while(!empty(stack)){
        curr = (node *)pop(stack);
        if(curr){
            if(!(dist = distance(root->bodies[i].position, curr->pseudo_body.position))){
                scale = curr->size/dist;
                if(scale <= threshold) add(&result, compute_force(root->bodies[i], curr->pseudo_body));
                else{
                    if(curr->NW) push(stack, (void *)curr->NW);
                    if(curr->NE) push(stack, (void *)curr->NE);
                    if(curr->SW) push(stack, (void *)curr->SW);
                    if(curr->SE) push(stack, (void *)curr->SE);
                }
            }
        }
    }

    return result;
}

#include "headers.h"
#include<math.h>
#include<malloc.h>

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

double **compute_forces(node *root, int count){
    vector *forces = (vector *)malloc(count * sizeof(vector));

    for(long i = 0; i < count; i++){
        forces[i] = resultant_force(root, i); //TODO resultant force function
    }

    return point_to_array(forces, count); //TODO vector to array function
}

vector resultant_force(node *root, int i){
    vector force;

}

//
// Created by jsmolka on 23.03.2022.
//

#ifndef ELEMENTS_VECTOR_H
#define ELEMENTS_VECTOR_H


class Vector {
public:
    double x;
    double y;

    Vector();
    Vector(double x_coord, double y_coord);
    Vector(const Vector &other);
    void operator += (const Vector &other);
};

Vector operator * (const double &scalar, const Vector &vec);
Vector operator * (const Vector &vec, const double &scalar);


#endif //ELEMENTS_VECTOR_H

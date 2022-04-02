#ifndef ELEMENTS_VECTOR_H
#define ELEMENTS_VECTOR_H

#include<vector>


class Vector {
public:
    double x;
    double y;

    Vector();
    Vector(double x_coord, double y_coord);
    Vector(const Vector &other);
    void operator += (const Vector &other);
    void operator *= (const double &scalar);
};

Vector operator * (const double &scalar, const Vector &vec);
Vector operator * (const Vector &vec, const double &scalar);
Vector operator / (const Vector &vec, const double &scalar);
Vector operator / (const double &scalar, const Vector &vec);
Vector operator - (const Vector &vec1, const Vector &vec2);
Vector operator + (const Vector &vec1, const Vector &vec2);

void vectorToArr(std::vector<std::vector<double>> &arr, Vector *vectors, int count);


#endif //ELEMENTS_VECTOR_H

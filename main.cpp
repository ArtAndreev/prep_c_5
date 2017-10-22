#include <iostream>

#include "Vector.h"

void check_collinearity(const Vector& a, const Vector &b);
void check_orthogonality(const Vector& a, const Vector &b);

int main() {
    Vector vectors[4] = {Vector(1, 2, 3),
                         Vector(2, 4, 6),
                         Vector(1, 0, 0),
                         Vector(0, 0, 1)};

    check_collinearity(vectors[0], vectors[1]);
    check_orthogonality(vectors[2], vectors[3]);
    check_collinearity(vectors[0], vectors[2]);
    check_orthogonality(vectors[0], vectors[2]);

    return 0;
}

void check_collinearity(const Vector& a, const Vector &b) {
    if ((a ^ b).is_zero_vector())
        std::cout << "Vectors are collinear." << std::endl;
    else
        std::cout << "Vectors are not collinear." << std::endl;
}

void check_orthogonality(const Vector& a, const Vector &b) {
    if (!(a * b))
        std::cout << "Vectors are orthogonal." << std::endl;
    else
        std::cout << "Vectors are not orthogonal." << std::endl;
}

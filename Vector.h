#ifndef C_TASK5_VECTOR_H
#define C_TASK5_VECTOR_H

#include <iostream>

class Vector {
public:
    explicit Vector(double x = 0.0, double y = 0.0, double z = 0.0);
    Vector& operator+=(const Vector& rhs);
    Vector operator+(const Vector& rhs) const;
    Vector& operator-=(const Vector& rhs);
    Vector operator-(const Vector& rhs) const;
    double operator*(const Vector& rhs) const; // dot (scalar) product
    Vector& operator^=(const Vector& rhs);
    Vector operator^(const Vector& rhs) const; // cross (vector) product
    Vector& operator*=(double rhs);
    Vector operator*(double rhs) const;
    double operator[](int index) const;
    Vector& operator=(const Vector& rhs);
    bool is_zero_vector() const;
    friend std::ostream& operator<<(std::ostream& os, const Vector& rhs);
    friend Vector operator*(double lhs, const Vector& rhs);

private:
    double x;
    double y;
    double z;

    void set_fields(double x, double y, double z);
};

#endif //C_TASK5_VECTOR_H

#include "Vector.h"

Vector::Vector(double x, double y, double z) :
        x(0.0), y(0.0), z(0.0) {
    set_fields(x, y, z);
}

Vector& Vector::operator+=(const Vector& rhs) {
    set_fields(x + rhs.x, y + rhs.y, z + rhs.z);

    return *this;
}

Vector Vector::operator+(const Vector& rhs) const {
    Vector result = *this;
    result += rhs;

    return result;
}

Vector& Vector::operator-=(const Vector& rhs) {
    set_fields(x - rhs.x, y - rhs.y, z - rhs.z);

    return *this;
}

Vector Vector::operator-(const Vector& rhs) const {
    Vector result = *this;
    result -= rhs;

    return result;
}

double Vector::operator*(const Vector& rhs) const {
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vector& Vector::operator^=(const Vector& rhs) {
    set_fields(y * rhs.z - z * rhs.y,
               z * rhs.x - x * rhs.z,
               x * rhs.y - y * rhs.x);

    return *this;
}

Vector Vector::operator^(const Vector& rhs) const {
    Vector result = *this;
    result ^= rhs;

    return result;
}

Vector& Vector::operator*=(double rhs) {
    set_fields(x * rhs, y * rhs, z * rhs);

    return *this;
}

Vector Vector::operator*(double rhs) const {
    Vector result = *this;
    result *= rhs;

    return result;
}

double Vector::operator[](int index) const {
    switch (index) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: std::cerr << "Wrong index given." << std::endl; return 0;
    }
}

Vector& Vector::operator=(const Vector& rhs) {
    if (this == &rhs)
        return *this;
    set_fields(rhs.x, rhs.y, rhs.z);

    return *this;
}

bool Vector::is_zero_vector() const {
    if (x || y || z)
        return false;
    return true;
}

void Vector::set_fields(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector operator*(double lhs, const Vector& rhs) {
    return rhs * lhs;
}

std::ostream& operator<<(std::ostream& os, const Vector& rhs) {
    os << '(' << rhs.x << ", " << rhs.y << ", " << rhs.z << ')' << std::endl;

    return os;
}

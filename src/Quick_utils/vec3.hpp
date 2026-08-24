#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3{
  public:
    double e[3];

    // default and parameterised constructors for e[3]
    vec3() : e {0,0,0} {};
    vec3(double x, double y, double z) : e {x,y,z} {};

    // value getters
    double x() const {
        return e[0];
    }

    double y() const {
        return e[1];
    }

    double z() const {
        return e[2];
    }
    vec3& operator=(const vec3& other) {
        e[0] = other.x();
        e[1] = other.y();
        e[2] = other.z();
        return *this;
    }

    vec3 operator-() const { return {-e[0], -e[1], -e[2]}; } // we return value copies, as it "augments" state
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    vec3& operator+=(const vec3& other) {
        e[0] += other.x();
        e[1] += other.y();
        e[2] += other.z();
        return *this;
    }

    vec3& operator*=(double scalar) {
        e[0] *= scalar;
        e[1] *= scalar;
        e[2] *= scalar;
        return *this;
    }

    vec3& operator/=(double scalar) {
        return *this *= 1/scalar;
    }

    double length() const {
        return std::sqrt(length_squared());
    }

    double length_squared() const{
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }
};

using point3 = vec3;

// useful helper functions
inline std::ostream& operator<<(std::ostream& out, const vec3& v){
    return out << v[0] << ' ' << v[1] << ' ' << v[2] ;
}

inline vec3 operator+(const vec3& v1, const vec3& v2){
    return {v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]};
}

inline vec3 operator-(const vec3& v1, const vec3& v2){
    return {v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]};
}

inline vec3 operator*(const vec3& v1, const vec3& v2){
    return {v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]};
}

inline vec3 operator*(double d, const vec3& v2){
    return {d * v2[0], d * v2[1], d * v2[2]};
}

inline vec3 operator*(const vec3& v2, double d){
    return d * v2;
}

inline vec3 operator/(const vec3& v, double d){
    return (1/d) * v;
}

inline double dot(const vec3& v1, const vec3& v2){
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& u) {
    return u / u.length();
}

#endif

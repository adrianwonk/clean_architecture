#pragma once
#include <cmath>
#include <iostream>
#include <concepts>

template<typename T>
concept IntOrDouble = std::same_as<T, int> || std::same_as<T, double>;

template<typename T>
concept Double = std::same_as<T, double>;

template<typename T>
concept Int = std::same_as<T, int>;

template<IntOrDouble T>
class vec3{
  public:
    T e[3];

    // default and parameterised constructors for e[3]
    vec3() : e {0,0,0} {};
    vec3(T x, T y, T z) : e {x,y,z} {};
    vec3(vec3<double>& v) requires Int<T> : e {
        static_cast<T>(std::floor(v.x())),
        static_cast<T>(std::floor(v.y())),
        static_cast<T>(std::floor(v.z()))
    } {};

    // value getters
    T x() const {
        return e[0];
    }

    T y() const {
        return e[1];
    }

    T z() const {
        return e[2];
    }
    vec3& operator=(const vec3& other) {
        e[0] = other.x();
        e[1] = other.y();
        e[2] = other.z();
        return *this;
    }

    vec3 operator-() const { return {-e[0], -e[1], -e[2]}; } // we return value copies, as it "augments" state
    T operator[](int i) const { return e[i]; }
    T& operator[](int i) { return e[i]; }

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

template<IntOrDouble T>
using point3 = vec3<T>;

// useful helper functions
template<IntOrDouble T>
inline std::ostream& operator<<(std::ostream& out, const point3<T>& v){
    return out << v[0] << ' ' << v[1] << ' ' << v[2] ;
}

template<IntOrDouble T>
inline vec3<T> operator+(const vec3<T>& v1, const vec3<T>& v2){
    return {v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]};
}

template<IntOrDouble T>
inline vec3<T> operator-(const vec3<T>& v1, const vec3<T>& v2){
    return {v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]};
}

template<IntOrDouble T>
inline vec3<T> operator*(const vec3<T>& v1, const vec3<T>& v2){
    return {v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]};
}

template<Double T>
inline vec3<T> operator*(double d, const vec3<T>& v2){
    return {d * v2[0], d * v2[1], d * v2[2]};
}

template<Int T>
inline vec3<T> operator*(double d, const vec3<T>& v2){
    return {
        static_cast<T>(std::floor(d * v2[0])),
        static_cast<T>(std::floor(d * v2[1])),
        static_cast<T>(std::floor(d * v2[2]))
    };
}

template<IntOrDouble T>
inline vec3<T> operator*(const vec3<T>& v2, double d){
    return d * v2;
}

template<IntOrDouble T>
inline vec3<T> operator/(const vec3<T>& v, double d){
    return (1/d) * v;
}

template<Double T>
inline T dot(const vec3<T>& v1, const vec3<T>& v2){
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

template<Double T>
inline vec3<T> cross(const vec3<T>& u, const vec3<T>& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

template<Double T>
inline vec3<T> unit_vector(const vec3<T>& u) {
    return u / u.length();
}

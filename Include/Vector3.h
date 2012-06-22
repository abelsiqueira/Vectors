#ifndef vector3_h
#define vector3_h

#include <cmath>

template <typename T>
struct Vector3 {
    Vector3 (T a = 0, T b = 0, T c = 0) : x(a), y(b), z(c) {}
    Vector3 (const T & v) : x(v.x), y(v.y), z(v.z) {}
    ~Vector3 () {}
    T x, y, z;

    void Update (T a, const Vector3<T> & v) {
      x += a*v.x;
      y += a*v.y;
      z += a*v.z;
    }

    void Scale (T a) {
      x *= a;
      y *= a;
      z *= a;
    }

    float Dot (const Vector3 & v) {
      return x*v.x + y*v.y + z*v.z;
    }

    void Normalize () {
      float n = Magnitude();
      x /= n;
      y /= n;
      z /= n;
    }

    float Magnitude () const {
      return sqrt(x*x + y*y + z*z);
    }

    float SqrMagnitude () const {
      return x*x + y*y + z*z;
    }

    float Distance (const Vector3<T> & v) const {
      return sqrt( pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2) );
    }
    
    float SqrDistance (const Vector3<T> & v) const {
      return pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2);
    }
};

typedef Vector3<float>        Vector3f;
typedef Vector3<int>          Vector3i;
typedef Vector3<unsigned int> Vector3ui;

#endif

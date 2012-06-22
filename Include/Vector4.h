#ifndef vector4_h
#define vector4_h

#include <cmath>

template <typename T>
struct Vector4 {
    Vector4 (T a = 0, T b = 0, T c = 0, T d = 0) : x(a), y(b), z(c), w(d) {}
    Vector4 (const T & v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
    ~Vector4 () {}
    T x, y, z, w;

    void Update (T a, const Vector4<T> & v) {
      x += a*v.x;
      y += a*v.y;
      z += a*v.z;
      w += a*v.w;
    }

    void Scale (T a) {
      x *= a;
      y *= a;
      z *= a;
      w *= a;
    }

    float Dot (const Vector4 & v) {
      return x*v.x + y*v.y + z*v.z + w*v.w;
    }

    void Normalize () {
      float n = Magnitude();
      x /= n;
      y /= n;
      z /= n;
      w /= n;
    }

    float Magnitude () const {
      return sqrt(x*x + y*y + z*z + w*w);
    }

    float SqrMagnitude () const {
      return x*x + y*y + z*z + w*w;
    }

    float Distance (const Vector4<T> & v) const {
      return sqrt( pow(x - v.x, 2) + pow(y - v.y, 2) + 
          pow(z - v.z, 2) + pow(w - v.w, 2) );
    }
    
    float SqrDistance (const Vector4<T> & v) const {
      return pow(x - v.x, 2) + pow(y - v.y, 2) + 
        pow(z - v.z, 2) + pow(w - v.w, 2);
    }
};

typedef Vector4<float>        Vector4f;
typedef Vector4<int>          Vector4i;
typedef Vector4<unsigned int> Vector4ui;

#endif

#ifndef vector2_h
#define vector2_h

#include <cmath>

template <typename T>
struct Vector2 {
    Vector2 (T a = 0, T b = 0) : x(a), y(b) {}
    Vector2 (const T & v) : x(v.x), y(v.y) {}
    ~Vector2 () {}
    T x, y;

    void Update (T a, const Vector2<T> & v) {
      x += a*v.x;
      y += a*v.y;
    }

    void Scale (T a) {
      x *= a;
      y *= a;
    }

    Vector2 Tangent (bool clockwise = true) {
      int s = (clockwise ? 1 : -1);
      Vector2 t(s*y, -s*x);
      return t;
    }

    float Dot (const Vector2 & v) {
      return x*v.x + y*v.y;
    }

    void Normalize () {
      float n = Magnitude();
      x /= n;
      y /= n;
    }

    float Magnitude () const {
      return sqrt(x*x + y*y);
    }

    float SqrMagnitude () const {
      return x*x + y*y;
    }

    float Distance (const Vector2<T> & v) const {
      return sqrt( pow(x - v.x, 2) + pow(y - v.y, 2) );
    }
    
    float SqrDistance (const Vector2<T> & v) const {
      return pow(x - v.x, 2) + pow(y - v.y, 2);
    }
};

typedef Vector2<float>        Vector2f;
typedef Vector2<int>          Vector2i;
typedef Vector2<unsigned int> Vector2ui;

#endif

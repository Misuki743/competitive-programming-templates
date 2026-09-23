namespace FPS {
  
  template<class T>
  vc<T>& operator+=(vc<T> &a, const vc<T> b) {
    if (size(a) < size(b)) a.resize(size(b), 0);
    for(int i = 0; i < ssize(a); i++)
      a[i] += b[i];
    return a;
  }

  template<class T>
  vc<T>& operator-=(vc<T> &a, const vc<T> b) {
    if (size(a) < size(b)) a.resize(size(b), 0);
    for(int i = 0; i < ssize(a); i++)
      a[i] -= b[i];
    return a;
  }

  template<class Mint>
  vc<Mint>& operator*=(vc<Mint> &a, const vc<Mint> b) {
    return a = convolution<Mint>(a, b);
  }
  
  template<class T>
  vc<T>& operator+=(vc<T> &a, const T b) {
    for(int i = 0; i < ssize(a); i++)
      a[i] += b;
    return a;
  }

  template<class T>
  vc<T>& operator-=(vc<T> &a, const T b) {
    for(int i = 0; i < ssize(a); i++)
      a[i] -= b;
    return a;
  }

  template<class T>
  vc<T>& operator*=(vc<T> &a, const T b) {
    for(int i = 0; i < ssize(a); i++)
      a[i] *= b;
  }

  template<class T>
  vc<T>& operator<<=(vc<T> &a, int s) {
    a.insert(a.begin(), s, 0);
    return a;
  }

  template<class T>
  vc<T>& operator>>=(vc<T> &a, int s) {
    a.resize(ssize(a) - s);
    return a;
  }
}

using namespace FPS;

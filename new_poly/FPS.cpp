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
    return a = convolution(a, b);
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
    return a;
  }

  template<class T>
  vc<T>& operator<<=(vc<T> &a, int s) {
    a.insert(a.begin(), s, 0);
    return a;
  }

  template<class T>
  vc<T>& operator>>=(vc<T> &a, int s) {
    assert(s <= ssize(a));
    a.erase(a.begin(), a.begin() + s);
    return a;
  }

  template<class T>
  vc<T> operator+(vc<T> a, vc<T> b) { return a += b; }
  template<class T>
  vc<T> operator-(vc<T> a, vc<T> b) { return a -= b; }
  template<class Mint>
  vc<Mint> operator*(vc<Mint> a, vc<Mint> b) { return a *= b; }
  template<class T>
  vc<T> operator*(vc<T> a, T b) { return a *= b; }

  template<class Mint>
  vc<Mint> derivative(vc<Mint> a) {
    a >>= 1;
    for(int i = 0; i < ssize(a); i++)
      a[i] *= i + 1;
    return a;
  }

  template<class Mint>
  vc<Mint> integral(vc<Mint> a) {
    a <<= 1;
    for(int i = 1; i < ssize(a); i++)
      a[i] *= inverse<Mint>(i);
    return a;
  }

  template<class Mint>
  vc<Mint> inv(vc<Mint> &a, int k = -1) {
    assert(!empty(a) and a[0] != 0);
    if (k == -1) k = ssize(a);
    vc<Mint> b(1, a[0].inverse());
    for(int i = 1; (1 << (i - 1)) < k; i++) {
      vc<Mint> c(1 << (i + 1));
      ranges::copy(a | views::take(1 << i), c.begin());
      DFT(c, 0);

      b.resize(1 << (i + 1));
      auto d = b * Mint(2);
      DFT(b, 0);

      for(int j = 0; j < ssize(b); j++)
        b[j] *= b[j] * c[j];
      DFT(b, 1);

      b = d - b;
      b.resize(1 << i);
    }
    b.resize(k);
    return b;
  }

  template<class Mint>
  vc<Mint> log(vc<Mint> a, int k = -1) {
    assert(!empty(a) and a[0] == 1);
    if (k == -1) k = ssize(a);
    vc<Mint> b = inv(a, k);
    a = derivative(a) * b;
    a.resize(k - 1);
    return integral(a);
  }

  template<class Mint>
  vc<Mint> exp(vc<Mint> a, int k = -1) {
    assert(!empty(a) and a[0] == 0);
    if (k == -1) k = ssize(a);
    vc<Mint> b(1, 1);
    for(int i = 1; (1 << (i - 1)) < k; i++) {
      vc<Mint> c(1 << i);
      ranges::copy(a | views::take(1 << i), c.begin());
      b = b * (vc<Mint>(1, 1) + c - log(b, 1 << i));
      b.resize(1 << i);
    }
    b.resize(k);
    return b;
  }
}

using namespace FPS;

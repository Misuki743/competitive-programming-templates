template<ranges::random_access_range R>
void zeta_divisor(R &v) {
  primes(ssize(v), [&](int p) {
    for(int i = 1; i * p < ssize(v); i++)
      v[i * p] += v[i];
  });
}

template<ranges::random_access_range R>
void mobius_divisor(R &v) {
  primes(ssize(v), [&](int p) {
    for(int i = (ssize(v) - 1) / p; i > 0; i--)
      v[i * p] -= v[i];
  });
}

template<class T>
void zeta_multiple(vc<T> &v) {
  primes(ssize(v), [&](int p) {
    for(int i = (ssize(v) - 1) / p; i > 0; i--)
      v[i] += v[i * p];
  });
}

template<class T>
void mobius_multiple(vc<T> &v) {
  primes(ssize(v), [&](int p) {
    for(int i = 1; i * p < ssize(v); i++)
      v[i] -= v[i * p];
  });
}

template<class T>
vc<T> lcm_convolution(vc<T> a, vc<T> b) {
  assert(ssize(a) == ssize(b));
  zeta_divisor(a), zeta_divisor(b);
  for(int i = 0; i < ssize(a); i++)
    a[i] *= b[i];
  mobius_divisor(a);
  return a;
}

template<class T>
vc<T> gcd_convolution(vc<T> a, vc<T> b) {
  assert(ssize(a) == ssize(b));
  zeta_multiple(a), zeta_multiple(b);
  for(int i = 0; i < ssize(a); i++)
    a[i] *= b[i];
  mobius_multiple(a);
  return a;
}

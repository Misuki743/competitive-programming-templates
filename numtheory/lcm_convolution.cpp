//#include "numtheory/linear_sieve.cpp"
//#include "numtheory/zeta_mobius_on_divisibility_lattice.cpp"

template<class T, int32_t C>
vector<T> lcm_convolution(vector<T> a, vector<T> b) {
  assert(ssize(a) == ssize(b));
  a = zeta_transform_on_divisor<T, C>(a);
  b = zeta_transform_on_divisor<T, C>(b);
  for(int i = 0; i < ssize(a); i++)
    a[i] *= b[i];
  return mobius_transform_on_divisor<T, C>(a);
}

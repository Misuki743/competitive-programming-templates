//both a and b are convex, i.e. f(i+2) - f(i+1) >= f(i+1) - f(i)
template<class T>
vc<T> min_plus_convolution(vc<T> a, vc<T> b) {
  vc<T> c(ssize(a) + ssize(b) - 1);
  adjacent_difference(a.begin(), a.end(), a.begin());
  adjacent_difference(b.begin(), b.end(), b.begin());
  c[0] = a[0] + b[0];
  merge(a.begin() + 1, a.end(), b.begin() + 1, b.end(), c.begin() + 1);
  pSum(c);
  return c;
}

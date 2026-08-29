vi continuous_fraction_of_sqrt(int n) {
  int a = 1, b = n, c = 0;
  vi v;
  while(ssize(v) <= 1 or (ull)v.back() != 2 * kth_root(n, 2)) {
    int m = (kth_root(b, 2) + c) / a;
    v.eb(m);
    c -= m * a;

    int A = (b - c * c) / a, C = -c;
    a = A, c = C;
  }

  return v;
}

pair<__int128, __int128> expand(vi v) {
  __int128 u = 1, d = v.back();
  __int128 v0 = v[0];
  v.erase(v.begin());
  for(__int128 x : v | views::reverse | views::drop(1)) {
    u += x * d;
    swap(u, d);
    __int128 g = gcd(u, d);
    u /= g, d /= g;
  }
  u += d * v0;
  __int128 g = gcd(u, d);
  u /= g, d /= g;
  return {u, d};
}

//x^2 - dy^2 = 1
pair<__int128, __int128> pell_equation_fundamental(int d) {
  if (int s = kth_root(d, 2); s * s == d)
    return pii(-1, -1);

  auto v = continuous_fraction_of_sqrt(d);
  if (ssize(v) % 2 == 0)
    for(int i = 1, n = ssize(v); i < n; i++)
      v.eb(v[i]);
  v.pop_back();

  return expand(v);
}

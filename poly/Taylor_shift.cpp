//#include "modint/Montgomery_modint.cpp"
//#include "poly/NTT.cpp"

template<class Mint>
vc<Mint> Taylor_shift(vc<Mint> f, Mint c) {
  static NTT ntt;
  int n = ssize(f);
  vc<Mint> a = f;
  for(int i = 0; i < n; i++)
    a[i] *= factorial<Mint>(i);
  vc<Mint> b(n);
  Mint pre = 1;
  for(int i = 0; i < n; i++, pre *= c)
    b[i] = pre * factorial_inv<Mint>(i);
  ranges::reverse(b);
  f = ntt.conv(a, b);
  f.erase(f.begin(), f.begin() + n - 1);
  for(int i = 0; i < n; i++)
    f[i] *= factorial_inv<Mint>(i);
  return f;
}

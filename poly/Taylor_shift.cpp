//#include "modint/Montgomery_modint.cpp"
//#include "poly/NTT.cpp"
//#include "poly/FPS.cpp"
//#include "combi/binom.cpp"

template<class Mint>
FPS<Mint> Taylor_shift(FPS<Mint> f, Mint c) {
  int n = ssize(f);
  FPS<Mint> a = f;
  for(int i = 0; i < n; i++)
    a[i] *= bn.fac(i);
  FPS<Mint> b(n);
  Mint pre = 1;
  for(int i = 0; i < n; i++, pre *= c)
    b[i] = pre * bn.faci(i);
  ranges::reverse(b);
  f = a * b;
  f.erase(f.begin(), f.begin() + n - 1);
  for(int i = 0; i < n; i++)
    f[i] *= factorial_inv<Mint>(i);
  return f;
}

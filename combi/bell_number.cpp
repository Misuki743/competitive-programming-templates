//#include "modint/Montgomery_modint.cpp"
//#include "poly/NTTmint.cpp"
//#include "poly/FPS.cpp"
//#include "combi/binomial.cpp"

template<class Mint>
FPS<Mint> bell_number(int n) {
  FPS<Mint> f(n);
  for(int i = 1; i < n; i++) f[i] = factorial_inv<Mint>(i);
  f = f.exp(n);
  for(int i = 0; i < n; i++) f[i] *= factorial<Mint>(i);
  return f;
}

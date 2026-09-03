//#include<modint/Montgomery_modint.cpp>
//#include<poly/NTTmint.cpp>
//#include<poly/FPS.cpp>

template<class Mint>
vc<Mint> bernoulli_number(int n) {
  FPS<Mint> f(n + 1);
  f[n] = Mint(1) / factorial<Mint>(n);
  for(int i = n - 1; i > 0; i--)
    f[i] = f[i + 1] * (i + 1);
  f.erase(f.begin());
  f = f.inv(n);
  vc<Mint> v(n);
  for(int i = 0; i < n; i++)
    v[i] = f[i] * factorial<Mint>(i);
  return v;
}

//#include<modint/Montgomery_modint.cpp>

template<class Mint>
Mint factorial(int n) {
  static vc<Mint> dat;
  if (n >= ssize(dat)) {
    if (dat.empty()) dat.eb(1);
    int size0 = ssize(dat);
    dat.resize(min(Mint::get_mod(), bit_ceil((uint32_t)(n + 1))));
    for(int i = size0; i < ssize(dat); i++)
      dat[i] = dat[i - 1] * i;
  }
  return dat[n];
}

template<class Mint>
Mint factorial_inv(int n) {
  static vc<Mint> dat;
  if (n >= ssize(dat)) {
    int size0 = ssize(dat);
    dat.resize(min(Mint::get_mod(), bit_ceil((uint32_t)(n + 1))));
    dat.back() = factorial<Mint>(ssize(dat) - 1).inverse();
    for(int i = ssize(dat) - 2; i >= size0; i--)
      dat[i] = dat[i + 1] * (i + 1);
  }
  return dat[n];
}

template<class Mint>
Mint inverse(int n) {
  return factorial_inv<Mint>(n) * factorial<Mint>(n - 1);
}

template<class Mint>
Mint binomial(int n, int k) {
  if (0 <= k and k <= n)
    return factorial<Mint>(n) * factorial_inv<Mint>(k) * factorial_inv<Mint>(n - k);
  else
    return Mint(0);
}

template<class Mint>
Mint catalan(int n) {
  return binomial<Mint>(2 * n, n) - binomial<Mint>(2 * n, n + 1);
}

//number of up-down path with n (+1), m (-1) and never touch y = -k
template<class Mint>
Mint excatalan(int n, int m, int k) {
  if (k > m) return binomial<Mint>(n + m, m);
  else if (k > m - n) return binomial<Mint>(n + m, m) - binomial<Mint>(n + m, m - k);
  else return Mint(0);
}

template<class Mint>
auto binomial_functions() {
  return tuple(
    &factorial<Mint>,
    &factorial_inv<Mint>,
    &inverse<Mint>,
    &binomial<Mint>,
    &catalan<Mint>,
    &excatalan<Mint>
  );
}

//auto [fac, faci, inv, binom, cat, excat] = binomial_functions<mint>();

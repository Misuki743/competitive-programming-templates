//sum(binom(n, i)) for i <= m
template<class Mint>
class binomial_partial_sum {
  int _n, _m;
  Mint ans = 0, i2 = Mint(2).inverse();

  public:

  binomial_partial_sum(int n, int m) : _n(n), _m(m) {
    for(int i = 0; i <= m; i++)
      ans += binomial<Mint>(n, i);
  }

  Mint query(int n, int m) {
    while(_m < m) ans += binomial<Mint>(_n, ++_m);
    while(_m > m) ans -= binomial<Mint>(_n, _m--);
    while(_n < n) ans += ans - binomial<Mint>(_n++, _m);
    while(_n > n) ans = (ans + binomial<Mint>(--_n, _m)) * i2;
    return ans;
  }
};

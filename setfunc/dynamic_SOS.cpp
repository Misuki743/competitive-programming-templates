//#include<enumerate/enumerate_bit.cpp>

template<class T>
struct dynamic_SOS {
  vc<T> f;
  array<ull, 3> g;
  dynamic_SOS(int W, vc<pii> add = {}, vi get = {}) : f(1 << W) {
    ll opt_cost = LLONG_MAX;
    mt19937_64 rng(clock);
    uniform_int_distribution<int> unif(0, 2);
    for(int i = 0; i < 64; i++) {
      array<ull, 3> g_tmp = {};
      for(int j = 0; j < W; j++)
        g_tmp[unif(rng)] |= 1 << j;
      ll cost = 0;
      for(auto [l, u] : add)
        cost += 1ll << (popcount((g_tmp[0] & ~u) | (g_tmp[1] & l) | (g_tmp[2] & u & ~l)));
      for(auto z : get)
        cost += 1ll << (popcount((z & g_tmp[0]) | (~z & g_tmp[1])));
      if (chmin(opt_cost, cost))
        g = g_tmp;
    }
  }

  void add(int l, int u, T x) {
    ull tar = (g[0] & ~u) | (g[1] & l) | (g[2] & u & ~l);
    ull inv = l | (g[1] & u & ~l);
    enumerate_subset(tar, [&](ull msk) {
      f[msk ^ inv] += (popcount((~u | l) & msk) % 2 == 1 ? -x : x);
    });
  };
  T get(int l) {
    T s = 0;
    ull tar = (l & g[0]) | (~l & g[1]);
    enumerate_subset(tar, [&](ull msk) {
      s += f[msk ^ l];
    });
    return s;
  };
};

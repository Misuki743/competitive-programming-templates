template<class T = int, typename F = void*>
struct rollback_DSU {
  vi sz_par;
  vc<pii> his;
  int nxt;

  vc<T> data;
  vc<T> data_his;
  F op;

  rollback_DSU(int n) requires same_as<F, void*> : sz_par(n, -1), his(2 * (n - 1)), nxt(0) {}

  rollback_DSU(vc<T> init, F f) requires R_invocable<void, F, T&, T&> &&
    (!R_invocable<void, F, T, T&>) && (!R_invocable<void, F, T&, T>)
    : sz_par(ssize(init), -1), his(2 * (ssize(init) - 1)), nxt(0), data(init), data_his(ssize(init) - 1), op(f) {}

  int query(int v) {
    int r = v;
    while(sz_par[r] >= 0) r = sz_par[r];
    return r;
  }

  bool merge(int v1, int v2) {
    int b1 = query(v1), b2 = query(v2);

    if (b1 == b2)
      return false;

    if (-sz_par[b1] > -sz_par[b2])
      swap(b1, b2);

    his[nxt] = pair(b2, sz_par[b2]);
    his[nxt + 1] = pair(b1, sz_par[b1]);
    sz_par[b2] += sz_par[b1];
    sz_par[b1] = b2;
    if constexpr (!same_as<F, void*>) {
      data_his[nxt / 2] = data[b2];
      op(data[b2], data[b1]);
    }
    nxt += 2;

    return true;
  }

  int time() { return nxt; }
  int size(int v) { return -sz_par[query(v)]; }

  void rollback(int t) {
    chmin(t, nxt);
    for(int j = nxt - 1; j >= t; j--) {
      auto [i, x] = his[j];
      sz_par[i] = x;
      if constexpr (!same_as<F, void*>) {
        if (j % 2 == 0)
          data[i] = data_his[j / 2];
      }
    }
    nxt = t;
  }
  T& get(int v) requires (!same_as<F, void*>) {
    return data[query(v)];
  }
};

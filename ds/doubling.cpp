template<class T = int, typename F = void*>
struct doubling {
  vvi jp;

  vvc<T> data;
  T id;
  F op;

  doubling(int LOG, vi to) : jp(LOG) {
    jp[0].swap(to);
    for(int i = 1; i < LOG; i++) {
      jp[i] = jp[i - 1];
      for(int &k : jp[i])
        if (k != -1)
          k = jp[i - 1][k];
    }
  }

  doubling(int LOG, vi to, vc<T> init, T _id, F f)
  requires R_invocable<T, F, T, T>
  : jp(LOG), data(LOG), id(_id), op(f) {
    jp[0].swap(to), data[0].swap(init);
    for(int i = 1; i < LOG; i++) {
      jp[i] = jp[i - 1], data[i] = data[i - 1];
      for(int j = -1; int &k : jp[i]) {
        j++;
        if (k != -1) {
          if (jp[i - 1][k] != -1)
            data[i][j] = op(data[i][j], data[i - 1][k]);
          k = jp[i - 1][k];
        }
      }
    }
  }

  int jump(int v, uint64_t k) {
    for(; k > 0 and v != -1; k -= k & (-k))
      v = jp[countr_zero(k)][v];
    return v;
  }

  pair<int, T> jump(int v, uint64_t k)
  requires (!same_as<F, void*>) {
    T prod = id;
    for(; k > 0 and v != -1; k -= k & (-k)) {
      if (jp[countr_zero(k)][v] != -1)
        prod = op(prod, data[countr_zero(k)][v]);
      v = jp[countr_zero(k)][v];
    }
    return pair(v, prod);
  }

  template<typename P>
  requires R_invocable<bool, P, int>
  int jump_while_true(int v, P pred) {
    if (!pred(v)) return v;
    for(int i = ssize(jp) - 1; i >= 0; i--) {
      if (jp[i][v] == -1) continue;
      if (pred(jp[i][v]))
        v = jp[i][v];
    }
    return v;
  }

  template<typename P>
  requires R_invocable<bool, P, int, T> && (!same_as<F, void*>)
  pair<int, T> jump_while_true(int v, P pred) {
    T prod = id;
    if (!pred(v, prod)) return pair(v, prod);
    for(int i = ssize(jp) - 1; i >= 0; i--) {
      if (jp[i][v] == -1) continue;
      if (T tmp = op(prod, data[i][v]); pred(jp[i][v], tmp))
        prod = tmp, v = jp[i][v];
    }
    return pair(v, prod);
  }
};

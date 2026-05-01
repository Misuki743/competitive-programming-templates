template<integral T>
struct shortest_path_LP {
  const T INF = numeric_limits<T>::max() >> 2;
  vc<tuple<int, int, T>> e;
  vi x;

  shortest_path_LP(int n) : x(n, INF) {}

  void var_max(int i, T mx) { chmin(x[i], mx); }
  void dif_max(int i, int j, T d) { e.eb(j, i, d); }
  void dif_min(int i, int j, T d) { e.eb(i, j, -d); }
  void dif_min_max(int i, int j, T d, T u) {
    dif_min(i, j, d);
    dif_max(i, j, u);
  }

  bool solve() {
    bool relax = true;
    for(int iter = 0; iter < ssize(x) and relax; iter++) {
      relax = false;
      for(auto [i, j, w] : e)
        if (chmin(x[j], x[i] + w))
          relax = true;
      if (iter + 1 == ssize(x) and relax)
        return false;
    }
    return true;
  }
};

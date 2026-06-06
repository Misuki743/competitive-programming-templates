#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include "../default/t.cpp"
#include "../graph/misc/maximum_independent_set.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<ull> g(n);
  while(m--) {
    int u, v; cin >> u >> v;
    g[u] |= 1LL << v, g[v] |= 1LL << u;
  }

  auto mis = maximum_independent_set(g, n);
  cout << ssize(mis) << '\n';
  cout << mis << '\n';

  return 0;
}

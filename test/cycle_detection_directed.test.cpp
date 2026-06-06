#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include "../default/t.cpp"
#include "../graph/misc/cycle_detection.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<array<int, 2>> e(m);
  for(auto &[u, v] : e)
    cin >> u >> v;
  
  auto [vs, es] = cycle_detection<true>(e);
  if (es.empty()) {
    cout << -1 << '\n';
  } else {
    cout << ssize(es) << '\n';
    for(int x : es)
      cout << x << '\n';
  }

  return 0;
}

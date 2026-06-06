#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_directed"

#include "../default/t.cpp"
#include "../graph/misc/eulerian_trail.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<array<int, 2>> e(m);
    for(auto &[u, v] : e)
      cin >> u >> v;
    auto [vid, eid] = eulerian_trail<true>(n, e);
    if (vid.empty()) {
      cout << "No\n"; 
    } else {
      cout << "Yes\n";
      cout << vid << '\n';
      cout << eid << '\n';
    }
  }

  return 0;
}

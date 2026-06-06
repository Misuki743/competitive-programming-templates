#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_directed"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../linalg/matrix_mint.cpp"
#include "../combi/count_spanning_forest.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m, r; cin >> n >> m >> r;
  vector<tuple<int, int, mint>> e(m);
  for(auto &[u, v, w] : e) {
    cin >> u >> v;
    w = 1;
  }

  cout << count_spanning_forest<mint, true>(e, n, vector<int>(1, r)) << '\n';

  return 0;
}

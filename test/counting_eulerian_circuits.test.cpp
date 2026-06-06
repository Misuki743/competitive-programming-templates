#define PROBLEM "https://judge.yosupo.jp/problem/counting_eulerian_circuits"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../linalg/matrix_mint.cpp"
#include "../combi/binomial.cpp"
#include "../combi/count_spanning_forest.cpp"
#include "../combi/count_eulerian_circuit.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<array<int, 2>> e(m);
  for(auto &[u, v] : e) cin >> u >> v;

  cout << count_eulerian_circuit<mint>(e, n) << '\n';

  return 0;
}

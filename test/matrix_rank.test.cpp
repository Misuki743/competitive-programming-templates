#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../linalg/matrix_mint.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  matrix<mint> M(n, m);
  cin >> M;
  cout << M.rank() << '\n';

  return 0;
}

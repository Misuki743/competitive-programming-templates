#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/FPS.cpp"
#include "../combi/stirling_second_kind_column.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, k; cin >> n >> k;
  cout << stirling_second_kind_column<mint>(n + 1, k) << '\n';

  return 0;
}

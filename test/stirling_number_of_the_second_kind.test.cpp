#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/FPS.cpp"
#include "../combi/binomial.cpp"
#include "../combi/stirling_second_kind.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  cout << stirling_second_kind<mint>(n) << '\n';

  return 0;
}

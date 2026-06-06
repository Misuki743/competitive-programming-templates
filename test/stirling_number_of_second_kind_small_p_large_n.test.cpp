#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_small_p_large_n"

#include "../default/t.cpp"
#include "../modint/dynamic_modint.cpp"
#include "../combi/stirling_second_kind_mod_P.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t, p; cin >> t >> p;
  mint::set_mod(p);
  stirling_second_kind_mod_P<mint> stir;
  while(t--) {
    ll n, k; cin >> n >> k;
    cout << stir.S(n, k) << '\n';
  }

  return 0;
}

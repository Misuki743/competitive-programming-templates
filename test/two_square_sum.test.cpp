#define PROBLEM "https://judge.yosupo.jp/problem/two_square_sum"

#include "../default/t.cpp"
#include "../numtheory/factorize_pollard_rho.cpp"
#include "../numtheory/primitive_root.cpp"
#include "../numtheory/two_square_sum.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int q; cin >> q;
  while(q--) {
    ll n; cin >> n;
    auto sol = two_square_sum(n);
    cout << size(sol) << '\n';
    for(auto pr : sol)
      cout << pr << '\n';
  }

  return 0;
}


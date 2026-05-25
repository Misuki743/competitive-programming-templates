#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include "../default/t.cpp"
#include "../numtheory/quotient_enumerate.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  ll n; cin >> n;
  ll x = sqrtl(n);
  while(x * (x + 1) <= n) x++;
  cout << n / x + x - 1 << '\n';
  vll sol;
  sol.reserve(n / x + x - 1);
  quotient_floor_enumerate(n, [&](ll v, ll, ll) { sol.eb(v); });
  ranges::reverse(sol);
  cout << sol << '\n';

  return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../tree/HLD.cpp"
#include "../dp/rerooting_DP.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<mint> a(n), b(n - 1), c(n - 1);
  for(mint &x : a) cin >> x;
  vc<pii> e(n - 1);
  for(int i = 0; i < n - 1; i++)
    cin >> e[i].first >> e[i].second >> b[i] >> c[i];

  using V = array<mint, 2>;
  using E = array<mint, 2>;
  auto id = [&](int i) { return V{a[i], 1}; };
  auto add_e = [&](const V &v, int i) { return E{b[i] * v[0] + c[i] * v[1], v[1]}; };
  auto ee = [&](const E &l, const E &r) { return E{l[0] + r[0], l[1] + r[1]}; };
  auto add_v = [&](const E &e, int i) { return V{e[0] + a[i], e[1] + 1}; };

  HLD hld(e);
  for(int v = 0; v < n; v++)
    dbg(v, hld.parent_eid(v));
  rerooting_DP<V, E> dp(hld, id, ee, add_v, add_e);
  for(int v = 0; v < n; v++)
    cout << dp[v][0] << " \n"[v + 1 == n];

  return 0;
}

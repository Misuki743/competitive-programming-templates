#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../segtree/segment_tree.cpp"
#include "../acted_monoid/affine_sum.cpp"
#include "../tree/HLD.cpp"

using am = affine_sum<mint>;

am::T R_Top(const am::T &a, const am::T &b) { return am::T{a[0] * b[0], b[1] * a[0] + a[1]}; }

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vc<array<mint, 2>> init(n);
  for(auto &[a, b] : init)
    cin >> a >> b;
  vc<pii> e(n - 1);
  for(auto &[u, v] : e)
    cin >> u >> v;

  HLD hld(std::move(e));
  init = hld.reorder_init(std::move(init));
  segment_tree<am::T, am::Tid, R_Top> st_rev(init);
  segment_tree<am::T, am::Tid, am::Top> st(init);
  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int p, c, d; cin >> p >> c >> d;
      st.set(hld.query_point(p), am::M{c, d});
      st_rev.set(hld.query_point(p), am::M{c, d});
    } else {
      int u, v, x; cin >> u >> v >> x;
      am::T prod = am::T{1, 0};
      for(auto [l, r] : hld.query_path_non_commutative(u, v)) {
        if (l < r) prod = am::Top(prod, st.query(l, r));
        else prod = am::Top(prod, st_rev.query(r, l));
      }
      cout << prod[0] * x + prod[1] << '\n';
    }
  }

  return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/range_add_range_min"

#include "../default/t.cpp"
#include "../segtree/lazy_segment_tree.cpp"
#include "../segtree/acted_monoid_segment_tree.cpp"
#include "../acted_monoid/add_min.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<ll> a(n);
  for(ll &x : a) cin >> x;
  acted_monoid_segment_tree<add_min<ll>> st(a);

  while(q--) {
    int op, l, r; cin >> op >> l >> r;
    if (op == 0) {
      int x; cin >> x;
      st.modify(l, r, x);
    } else {
      cout << st.query(l, r) << '\n';
    }
  }

  return 0;
}


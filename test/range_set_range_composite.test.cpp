#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../segtree/range_set_segment_tree.cpp"
#include "../actedmonoid/affine_sum.cpp"

using am = affine_sum<mint>;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<am::T> ab(n);
  for(auto &[a, b] : ab)
    cin >> a >> b;

  range_set_segment_tree<am::T, am::Tid, am::Top> st(ab);
  while(q--) {
    int t; cin >> t;
    if (t == 0) {
      int l, r, c, d; cin >> l >> r >> c >> d;
      st.set(l, r, am::T{c, d});
    } else {
      int l, r, x; cin >> l >> r >> x;
      cout << am::Top(am::T{0, x}, st.query(l, r))[1] << '\n';
    }
  }

  return 0;
}

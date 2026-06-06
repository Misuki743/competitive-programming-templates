#define PROBLEM "https://judge.yosupo.jp/problem/static_range_count_distinct"

#include "../default/t.cpp"
#include "../ds/fenwick_tree.cpp"
#include "../ds_problem/range_count_distinct.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vi a(n);
  for(int &x : a) cin >> x;
  vc<pii> lr(q);
  for(auto &[l, r] : lr) cin >> l >> r;
  for(int x : range_count_distinct(a, lr))
    cout << x << '\n';

  return 0;
}

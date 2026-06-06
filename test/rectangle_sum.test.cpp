#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../default/t.cpp"
#include "../ds/fenwick_tree.cpp"
#include "../ds_problem/rectangle_sum.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vc<tuple<int, int, ll>> pt(n);
  for(auto &[x, y, w] : pt) cin >> x >> y >> w;
  vc<array<int, 4>> query(q);
  for(auto &x : query) for(int &y : x) cin >> y;

  for(ll x : rectangle_sum(pt, query))
    cout << x << '\n';

  return 0;
}

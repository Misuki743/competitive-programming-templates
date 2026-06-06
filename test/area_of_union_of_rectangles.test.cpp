#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include "../default/t.cpp"
#include "../segtree/lazy_segment_tree.cpp"
#include "../segtree/acted_monoid_segment_tree.cpp"
#include "../acted_monoid/add_min_count.cpp"
#include "../ds_problem/area_of_union_of_rectangles.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<array<int, 4>> rect(n);
  for(auto &[l, d, r, u] : rect)
    cin >> l >> d >> r >> u;

  cout << area_of_union_of_rectangles<int, ll>(rect) << '\n';

  return 0;
}


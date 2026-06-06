#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "../default/t.cpp"
#include "../misc/compression.cpp"
#include "../ds/wavelet_matrix.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int &x : a)
    cin >> x;

  a.emplace_back(INT_MAX);
  compression<int> xs(a);
  wavelet_matrix<int, 18> wv(xs.ord);

  while(q--) {
    int l, r, x; cin >> l >> r >> x;
    int y = xs.lower_bound(x);
    if (xs.val[y] != x)
      cout << 0 << '\n';
    else
      cout << wv.rect_query(l, r, y, y + 1) << '\n';
  }

  return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../default/t.cpp"
#include "../ds/wavelet_matrix.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vi a(n);
  for(int &x : a) cin >> x;

  wavelet_matrix<int, 30> WM(a);

  while(q--) {
    int l, r, k; cin >> l >> r >> k;
    cout << WM.kth(l, r, k) << '\n';
  }

  return 0;
}

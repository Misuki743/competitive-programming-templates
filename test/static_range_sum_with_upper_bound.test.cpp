#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum_with_upper_bound"

#include "../default/t.cpp"
#include "../ds/wavelet_matrix.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vi a(n);
  for(int &x : a) cin >> x;

  vi xs = a;
  Unique(xs);
  for(int &x : a)
    x = ranges::lower_bound(xs, x) - xs.begin();

  wavelet_matrix<int, 19> WM(a, true);
  vvll ps;
  for(auto &p : WM.perms) {
    ps.eb(n);
    for(int i = 0; i < n; i++)
      ps.back()[i] = xs[a[p[i]]];
    pSum(ps.back());
  }

  while(q--) {
    int l, r, x; cin >> l >> r >> x;
    x = ranges::upper_bound(xs, x) - xs.begin();

    int cnt = 0;
    ll sum = 0;
    WM.rect_query(l, r, 0, x, [&](int i, int l, int r) {
      cnt += r - l;
      sum += ps[i][r - 1] - (l == 0 ? 0 : ps[i][l - 1]);
    });

    cout << cnt << ' ' << sum << '\n';
  }

  return 0;
}


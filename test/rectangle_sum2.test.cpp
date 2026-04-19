#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../default/t.cpp"
#include "../ds/wavelet_matrix.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vc<tuple<int, int, int>> xyw(n);
  for(auto &[x, y, w] : xyw) 
    cin >> x >> y >> w;

  vi xs, ys;
  for(auto [x, y, w] : xyw)
    xs.eb(x), ys.eb(y);
  ranges::sort(xs), ranges::sort(ys);

  vi tx(n), ty(n);
  for(auto &[x, y, w] : xyw) {
    int xi = ranges::lower_bound(xs, x) - xs.begin();
    x = xi + tx[xi]++;
    y = ranges::lower_bound(ys, y) - ys.begin();
  }

  vi a(n), z(n);
  for(auto [x, y, w] : xyw)
    a[x] = y, z[x] = w;

  wavelet_matrix<int, 19> WM(a, 1);
  vc ps(20, vll(n));
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < n; j++)
      ps[i][j] = z[WM.perms[i][j]];
    pSum(ps[i]);
  }

  while(q--) {
    int l, d, r, u; cin >> l >> d >> r >> u;
    l = ranges::lower_bound(xs, l) - xs.begin();
    r = ranges::lower_bound(xs, r) - xs.begin();
    d = ranges::lower_bound(ys, d) - ys.begin();
    u = ranges::lower_bound(ys, u) - ys.begin();

    ll ans = 0;
    WM.rect_query(l, r, d, u, [&](int I, int L, int R) {
      ans += ps[I][R - 1] - (L == 0 ? 0 : ps[I][L - 1]);
    });

    cout << ans << '\n';
  }

  return 0;
}

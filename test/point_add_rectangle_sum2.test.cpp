#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../default/t.cpp"
#include "../ds/fenwickTree.cpp"
#include "../ds/wavelet_matrix.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vc<tuple<int, int, int>> xyw(n);
  for(auto &[x, y, w] : xyw) 
    cin >> x >> y >> w;
  vc<array<int, 5>> qry(q);
  for(auto &[op, x, y, z, w] : qry) {
    cin >> op >> x >> y >> z;
    if (op == 0) {
      xyw.eb(x, y, z);
    } else {
      cin >> w;
    }
  }

  vi xs, ys;
  for(auto [x, y, w] : xyw)
    xs.eb(x), ys.eb(y);
  ranges::sort(xs), ranges::sort(ys);

  vi tx(size(xyw)), ty(size(xyw));
  for(auto &[x, y, w] : xyw) {
    int xi = ranges::lower_bound(xs, x) - xs.begin();
    x = xi + tx[xi]++;
    y = ranges::lower_bound(ys, y) - ys.begin();
  }

  vi a(size(xyw)), z(size(xyw));
  for(int i = 0; auto [x, y, w] : xyw)
    a[x] = y, z[x] = (i++ < n ? w : 0);

  wavelet_matrix<int, 19> WM(a, 1);
  vc<fenwickTree<ll>> ft;
  for(auto &p : WM.perms) {
    vll init(size(xyw));
    for(int j = 0; j < size(xyw); j++)
      init[j] = z[p[j]];
    ft.eb(init);
  }

  for(auto [op, x, y, z, w] : qry) {
    if (op == 0) {
      auto [X, Y, W] = xyw[n++];
      WM.point_update(X, [&](int i, int j) {
        ft[i].add(j, W);
      });
    } else {
      x = ranges::lower_bound(xs, x) - xs.begin();
      z = ranges::lower_bound(xs, z) - xs.begin();
      y = ranges::lower_bound(ys, y) - ys.begin();
      w = ranges::lower_bound(ys, w) - ys.begin();

      ll ans = 0;
      WM.rect_query(x, z, y, w, [&](int I, int L, int R) {
        dbg(I, L, R);
        ans += ft[I].query(L, R);
      });
      cout << ans << '\n';
    }
  }

  return 0;
}

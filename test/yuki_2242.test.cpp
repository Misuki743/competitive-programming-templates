#define PROBLEM "https://yukicoder.me/problems/no/2242"

#include "../default/t.cpp"
#include "../ds/doubling.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vi h(n), t(n);
  for(int &x : h) cin >> x;
  for(int &x : t) cin >> x;
  int q; cin >> q;
  vc<pii> ab(q);
  for(auto &[a, b] : ab) { cin >> a >> b; a--, b--; }

  {
    auto p = invPerm(argSort(h));
    vi v(n);
    for(int i = 0; i < n; i++)
      v[p[i]] = h[i];
    h.swap(v);
    for(int i = 0; i < n; i++)
      v[p[i]] = t[i];
    t.swap(v);
    for(auto &[a, b] : ab)
      a = p[a], b = p[b];
  }

  vi argmax(n);
  for(int i = 1; i < n; i++) {
    argmax[i] = argmax[i - 1];
    if (t[i] > t[argmax[i]])
      argmax[i] = i;
  }

  vi to(n);
  for(int i = 0; i < n; i++)
    to[i] = argmax[ranges::upper_bound(h, t[i]) - h.begin() - 1];

  for(int i = 0; i < n; i++)
    if (t[to[i]] <= t[i])
      to[i] = -1;

  doubling db(18, to, vi(n, 1), 0, [](int a, int b) { return a + b; });

  for(auto [a, b] : ab) {
    auto [v, step] = db.jump_while_true(a, [&](int x, int) { return t[x] < h[b]; });
    if (t[a] >= h[b])
      cout << 1 << '\n';
    else if (to[v] == -1)
      cout << -1 << '\n';
    else
      cout << step + 2 << '\n';
  }

  return 0;
}

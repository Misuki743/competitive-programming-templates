#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"

#include "../default/t.cpp"
#include "../numtheory/Stern_Brocot_tree.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    string op; cin >> op;
    if (op == "ENCODE_PATH") {
      ll a, b; cin >> a >> b;
      auto path = encode_path(fraction(a, b));
      cout << ssize(path) << ' ';
      for(auto [c, x] : path) cout << c << ' ' << x << ' ';
      cout << '\n';
    } else if (op == "DECODE_PATH") {
      int k; cin >> k;
      vc<pair<char, ll>> path(k);
      for(auto &[c, x] : path) cin >> c >> x;
      cout << decode_path(path) << '\n';
    } else if (op == "LCA") {
      ll a, b, c, d; cin >> a >> b >> c >> d;
      cout << LCA(fraction{a, b}, fraction{c, d}) << '\n';
    } else if (op == "ANCESTOR") {
      ll k, a, b; cin >> k >> a >> b;
      auto [u, d] = ancestor(k, fraction{a, b});
      if (u == -1) cout << -1 << '\n';
      else cout << u << ' ' << d << '\n';
    } else if (op == "RANGE") {
      ll a, b; cin >> a >> b;
      cout << range(fraction{a, b}) << '\n';
    }
  }

  return 0;
}


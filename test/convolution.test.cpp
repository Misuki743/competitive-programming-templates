#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<mint> a(n), b(m);
  for(mint &x : a)
    cin >> x;
  for(mint &x : b)
    cin >> x;

  NTT ntt;
  cout << ntt.conv(a, b) << '\n';

  return 0;
}

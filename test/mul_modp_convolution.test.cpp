#define PROBLEM "https://judge.yosupo.jp/problem/mul_modp_convolution"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/convolution_multiplicative.cpp"

NTT ntt;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int p; cin >> p;
  vector<mint> a(p), b(p);
  for(mint &x : a)
    cin >> x;
  for(mint &x : b)
    cin >> x;

  convolution_multiplicative mu(p);
  cout << mu.conv(a, b, ntt.conv) << '\n';

  return 0;
}

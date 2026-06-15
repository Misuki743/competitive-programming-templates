#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../setfunc/FWHT.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vc<mint> a(1 << n), b(1 << n);
  for(mint &x : a) cin >> x;
  for(mint &x : b) cin >> x;

  FWHT(a, 0), FWHT(b, 0);
  for(int i = 0; i < (1 << n); i++)
    a[i] *= b[i];
  FWHT(a, 1);
  cout << a << '\n';

  return 0;
}

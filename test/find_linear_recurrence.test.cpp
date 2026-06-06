#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/Berlekamp_Massey.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<mint> a(n);
  for(mint &x : a)
    cin >> x;

  auto c = Berlekamp_Massey(a);
  cout << ssize(c) - 1 << '\n';
  for(int i = 1; i < ssize(c); i++)
    cout << c[i] << " \n"[i + 1 == ssize(c)];

  return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../default/t.cpp"
#include "../string/z_function.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  string s; cin >> s;
  cout << z_function(s) << '\n';

  return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/wildcard_pattern_matching"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/FPS.cpp"
#include "../string/wildcard_pattern_matching.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  string s, t; cin >> s >> t;
  for(int x : wildcard_pattern_matching<mint>(s, t))
    cout << x;
  cout << '\n';

  return 0;
}

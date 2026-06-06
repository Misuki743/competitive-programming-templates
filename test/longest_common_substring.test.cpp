#define PROBLEM "https://judge.yosupo.jp/problem/longest_common_substring"

#include "../default/t.cpp"
#include "../string/suffix_array.cpp"
#include "../string/longest_common_substring.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  string s, t; cin >> s >> t;
  cout << longest_common_substring(s, t) << '\n';

  return 0;
}

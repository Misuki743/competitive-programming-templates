#define PROBLEM "https://judge.yosupo.jp/problem/aho_corasick"

#include "../default/t.cpp"
#include "../string/Aho_Corasick.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  Aho_Corasick ac(1 << 20);
  vector<int> vs;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    vs.emplace_back(ac.insert(s));
  }

  ac.build();

  cout << ssize(ac.v) << '\n';
  for(auto &node : ac.v | views::drop(1))
    cout << node.p << ' ' << node.link << '\n';
  cout << vs << '\n';

  return 0;
}


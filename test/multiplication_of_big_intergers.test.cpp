#define PROBLEM "https://judge.yosupo.jp/problem/multiplication_of_big_integers"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../misc/bigint.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    string a, b; cin >> a >> b;
    bigint<true> A(a), B(b);
    cout << A * B << '\n';
  }

  return 0;
}


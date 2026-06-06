#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/FPS.cpp"
#include "../misc/sharp_P_subset_sum.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, t; cin >> n >> t;
  vector<int> w(n);
  for(int &x : w)
    cin >> x;

  auto f = sharp_P_subset_sum<mint>(w, t);
  f.erase(f.begin());
  cout << f << '\n';

  return 0;
}

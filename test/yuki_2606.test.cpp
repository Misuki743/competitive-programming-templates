#define PROBLEM "https://yukicoder.me/problems/no/2606"

#include "../default/t.cpp"
#include "../string/palindromic_tree.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  string s; cin >> s;
  
  palindromic_tree pt(s);
  vector<ll> dp(ssize(pt.len));
  for(int i = 2; i < ssize(pt.len); i++)
    dp[i] = dp[pt.link[i]] + pt.freq[i] * pt.len[i];

  cout << ranges::max(dp) << '\n';

  return 0;
}

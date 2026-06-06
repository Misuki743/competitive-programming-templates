#define PROBLEM "https://yukicoder.me/problems/no/2613"

#include "../default/t.cpp";
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/convolution_multiplicative.cpp"

int p;
array<int, 200'000> fac, facInv;
int C(int a, int b) {
  if (b > a or b < 0) return 0;
  else return (ll)fac[a] * facInv[b] % p * facInv[a - b] % p;
}

NTT ntt;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  ll n; cin >> n >> p;

  fac[0] = 1;
  for(int i = 1; i < p; i++)
    fac[i] = (ll)fac[i - 1] * i % p;
  facInv[p - 1] = 1;
  for(int i = 0; i < p - 2; i++)
    facInv[p - 1] = (ll)facInv[p - 1] * fac[p - 1] % p;
  for(int i = p - 2; i >= 0; i--)
    facInv[i] = (ll)facInv[i + 1] * (i + 1) % p;

  convolution_multiplicative mu(p);

  vector<mint> f(p);
  f[1] = 1;
  while(n) {
    int nd = n % p; n /= p;
    vector<mint> g(p);
    for(int i = 0; i < p; i++)
      g[C(nd, i)] += 1;
    f = mu.conv(f, g, ntt.conv);
  }

  mint ans = 0;
  for(int i = 1; i < p; i++)
    ans += f[i] * i;

  cout << ans << '\n';

  return 0;
}

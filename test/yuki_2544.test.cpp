#define PROBLEM "https://yukicoder.me/problems/no/2544"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../combi/binomial.cpp"
#include "../poly/NTT.cpp"

NTT<23, 119, 3, mint> ntt;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;

  vector<mint> A(n + 1), B(n + 1);
  for(int i = 0; i <= n; i++)
    A[i] = factorial<mint>(i), B[i] = factorial_inv<mint>(n - i);

  A = ntt.conv(A, B);

  mint ans = 0;
  for(int l = 1; l <= n; l++)
    ans += (n - l + 1) * factorial<mint>(n - l) * A[l + n];

  cout << ans * mint((ll)n * (n + 1) / 2).pow(q - 1) * q << '\n';

  return 0;
}

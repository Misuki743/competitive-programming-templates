#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "../default/t.cpp"
#include "../numtheory/prime_counting.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  ll N; cin >> N;
  cout << prime_counting(N) << '\n';

  return 0;
}

template<class Mint>
vc<Mint> prefix_polynomial(vc<Mint> F) {
  const int n = ssize(F);
  F.resize(bit_ceil(n * 2u));
  Mint f0 = F[0];

  auto B = bernoulli_number<Mint>(n);
  vc<Mint> G(size(F));
  for(int i = 0; i < n; i++) {
    F[i] *= factorial<Mint>(i);
    G[i] = (i % 2 == 1 ? -1 : 1) * factorial_inv<Mint>(i) * B[i];
  }
  reverse(G.begin() + 1, G.end());
  ntt.ntt(F, 0), ntt.ntt(G, 0);
  for(int i = 0; i < ssize(F); i++)
    F[i] *= G[i];
  ntt.ntt(F, 1);
  F.back() = 0;
  ranges::rotate(F, prev(F.end()));
  F.resize(n + 1);
  for(int i = 0; i <= n; i++)
    F[i] *= factorial_inv<Mint>(i);
  F = Taylor_shift<Mint>(F, -1);
  F[0] += f0;

  return F;
}

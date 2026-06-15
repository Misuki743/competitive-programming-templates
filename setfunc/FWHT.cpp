template<class Mint>
void FWHT(vector<Mint> &a, bool inverse) {
  for(int n = ssize(a), step = 1; step < n; step <<= 1)
    for(int i = 0; i < n; i += step << 1)
      for(int j = i; j < i + step; j++)
        tie(a[j], a[j + step]) = pair(a[j] + a[j + step], a[j] - a[j + step]);
  if (inverse) {
    Mint I = Mint(1) / Mint(ssize(a));
    for(Mint &x : a) x *= I;
  }
}

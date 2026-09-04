int Pisano_period(int p) {
  if (p == 2) return 3;
  if (p == 5) return 20;
  mint::set_mod(p);
  matrix<mint> M(2, 2);
  M[0][0] = M[0][1] = M[1][0] = 1;

  int period = (p % 5 == 1 or p % 5 == 4) ? p - 1 : 2 * (p + 1);
  factorize(period, [&](int q, int) {
    while(period % q == 0 and M.pow(period / q) == matrix<mint>::I(2))
    period /= q;
  });

  return period;
}

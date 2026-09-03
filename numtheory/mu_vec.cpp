template<class T>
vc<T> mu_vec(int n) {
  vc<T> mu(n);
  if (n > 1) mu[1] = 1;
  for(int i = 2; i < n; i++) {
    int MPF = mpf(i);
    mu[i] = MPF == mpf(i / MPF) ? T(0) : -mu[i / MPF];
  }
  return mu;
}

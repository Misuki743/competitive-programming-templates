template<class T, int32_t C>
array<T, C> mu_array() {
  array<T, C> mu = {};
  if (C > 1) mu[1] = T(1);
  auto &mpf = linear_sieve<C>::mpf_array();
  for(int i = 2; i < C; i++)
    mu[i] = (mpf[i] == mpf[i / mpf[i]] ? T(0) : -mu[i / mpf[i]]);
  return mu;
}

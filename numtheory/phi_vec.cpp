template<class T>
vc<T> phi_vec(int n) {
  vc<T> phi(n);
  if (n > 1) phi[1] = 1;
  for(int i = 2; i < n; i++) {
    int MPF = mpf(i);
    phi[i] = phi[i / MPF] * (MPF - (MPF != mpf(i / MPF)));
  }
  return phi;
}

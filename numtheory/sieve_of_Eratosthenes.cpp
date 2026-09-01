namespace sieve_of_Eratosthenes {

  int _C = 5;
  vc<int32_t> _mpf, _prime = {2, 3};

  //n % 6 == 1 or 5
  int _id(int n) {
    return (n - 2) / 6 * 2 + (n % 6 == 1);
  }

  int _first_valid(int n) {
    static int d[6] = {1, 0, 3, 2, 1, 0};
    return n + d[n % 6];
  }

  int _next_valid(int n) {
    static int d[6] = {1, 4, 3, 2, 1, 2};
    return n + d[n % 6];
  }

  void sieve(int n) {
    assert(n <= (1 << 30));
    _C = _first_valid(_C);
    n = _first_valid(bit_ceil(n * 1ull));
    if (n <= _C) return;
    _mpf.resize(_id(n));
    for(int i = _C, d = _next_valid(_C) - _C; i < n; i += d, d = 6 - d)
      _mpf[_id(i)] = i;
    for(int i = 5, d = 2; i * i < n; i += d, d = 6 - d) if (_mpf[_id(i)] == i) {
      int k = _first_valid(max(i, ceilDiv(_C, i)));
      for(int j = i * k, e = _next_valid(k) - k; j < n; j += i * e, e = 6 - e)
        chmin(_mpf[_id(j)], i);
    }
    _C = n;
  }

  int mpf(int n) {
    if (n == 1) return 0;
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    if (n >= _C) sieve(n);
    return _mpf[_id(n)];
  }

  template<typename F>
  requires invocable<F, int, int>
  void factorize(int n, F f) {
    if (n >= _C) sieve(n);
    if (n % 2 == 0) f(2, countr_zero(n * 1ull)), n >>= countr_zero(n * 1ull);
    if (n % 3 == 0) {
      int e = 0;
      while(n % 3 == 0) n /= 3, e++;
      f(3, e);
    }
    while(n > 1) {
      int p = mpf(n), e = 0;
      while(n % p == 0) n /= p, e++;
      f(p, e);
    }
  }

  vi divisor(int n) {
    static array<int, 1 << 12> buf;
    if (n >= _C) sieve(n);
    vi v = {1};
    factorize(n, [&v](int p, int e) {
      int old_size = ssize(v);
      v.resize(old_size * (e + 1));
      for(int i = old_size; i < ssize(v); i++)
        v[i] = v[i - old_size] * p;
      for(int d = old_size; d < ssize(v); d <<= 1) {
        for(int i = 0; i + d < ssize(v); i += 2 * d) {
          merge(v.begin() + i, v.begin() + i + d, v.begin() + i + d, v.begin() + min(i + 2 * d, (int)size(v)), buf.begin());
          copy(buf.begin(), buf.begin() + min(2 * d, (int)size(v) - i), v.begin() + i);
        }
      }
    });
    return v;
  }

  template<typename F>
  requires invocable<F, int>
  void primes(int m, F f) {
    if (_prime.back() < m) {
      if (m >= _C) sieve(m);
      _prime.reserve(1.1 * _C / log(_C));
      int s = _next_valid(_prime.back());
      for(int i = s, d = _next_valid(s) - s; i < _C; i += d, d = 6 - d)
        if (_mpf[_id(i)] == i)
          _prime.eb(i);
    }
    for(int p : _prime) {
      if (p >= m) break;
      f(p);
    }
  }
};

//using namespace sieve_of_Eratosthenes;

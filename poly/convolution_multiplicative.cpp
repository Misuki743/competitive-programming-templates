//#include "poly/NTT.cpp"
//#include "modint/Montgomery_modint.cpp"

struct convolution_multiplicative {
  const int P, root;
  vector<int> powR, logR;

  int primitive_root(int p) {
    vector<int> pf;
    {
      int tmp = p - 1;
      for(int i = 2; i * i <= (p - 1); i++) {
        if (tmp % i != 0) continue;
        pf.emplace_back(i);
        while(tmp % i == 0) tmp /= i;
      }
      if (tmp != 1)
        pf.emplace_back(tmp);
    }

    auto modpow = [p](ll a, int x) -> int {
      if (x == 0) return 1;
      if (a == 0) return 0;
      ll b = 1;
      while(x) {
        if (x & 1) b = b * a % p;
        a = a * a % p, x >>= 1;
      }
      return b;
    };

    for(int r = 1; ; r++) {
      bool is_root = true;
      for(int d : pf) {
        if (modpow(r, (p - 1) / d) == 1) {
          is_root = false;
          break;
        }
      }
      if (is_root)
        return r;
    }
  }

  convolution_multiplicative(int _P) : P(_P), root(primitive_root(_P)), powR(P - 1), logR(P, -1) {
    for(int i = 0, tmp = 1; i < P - 1; i++, tmp = (ll)tmp * root % P)
      powR[i] = tmp, logR[tmp] = i;
  }

  template<class Mint>
  vector<Mint> transform(vector<Mint> &f) {
    assert(ssize(f) == P);
    vector<Mint> g(P - 1);
    for(int i = 1; i < P; i++)
      g[logR[i]] = f[i];
    return g;
  }

  template<class Mint>
  vector<Mint> inverse_transform(vector<Mint> &f) {
    assert(ssize(f) == P - 1);
    vector<Mint> g(P);
    for(int i = 0; i < P - 1; i++)
      g[powR[i]] = f[i];
    return g;
  }

  template<class Mint>
  vector<Mint> conv(vector<Mint> a, vector<Mint> b, vector<Mint>(*conv)(vector<Mint>, vector<Mint>)) {
    Mint zero = accumulate(a.begin(), a.end(), Mint(0)) * b[0] + accumulate(b.begin() + 1, b.end(), Mint(0)) * a[0];
    a = transform(a), b = transform(b);
    a = conv(a, b);
    for(int i = P - 1; i < 2 * P - 3; i++)
      a[i - (P - 1)] += a[i];
    a.resize(P - 1);
    a = inverse_transform(a);
    a[0] = zero;
    return a;
  }
};

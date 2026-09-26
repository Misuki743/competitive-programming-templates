namespace NTT {
  template<class Mint>
  void DFT(vc<Mint> &a, bool inv) {
    static array<Mint, 30> w, w_inv;

    if (w[0] == 0) {
      int mod = Mint::get_mod();
      Mint r = 2;
      while(r.pow((mod - 1) / 2) == 1) r += 1;
      for(int i = 0; i < 30; i++)
        w[i] = -(r.pow((mod - 1) >> (i + 2))), w_inv[i] = 1 / w[i];
    }

    int n = ssize(a);
    if (!inv) {
      for(int m = n; m >>= 1; ) {
        Mint ww = 1;
        for(int s = 0, l = 0; s < n; s += 2 * m) {
          for(int i = s, j = s + m; i < s + m; i++, j++) {
            Mint x = a[i], y = a[j] * ww;
            a[i] = x + y, a[j] = x - y;
          }
          ww *= w[__builtin_ctz(++l)];
        }
      }
    } else {
      for(int m = 1; m < n; m *= 2) {
        Mint ww = 1;
        for(int s = 0, l = 0; s < n; s += 2 * m) {
          for(int i = s, j = s + m; i < s + m; i++, j++) {
            Mint x = a[i], y = a[j];
            a[i] = x + y, a[j] = (x - y) * ww;
          }
          ww *= w_inv[__builtin_ctz(++l)];
        }
      }
      for(Mint i = Mint(n).inverse(); Mint &x : a) x *= i;
    }
  }

  template<bool neg_b = false, class Mint>
  vc<Mint> convolution(vc<Mint> a, vc<Mint> b) {
    if (empty(a) or empty(b)) return {};
    int sz = ssize(a) + ssize(b) - 1;
    int n = bit_ceil(sz * 1ull);

    a.resize(n, 0), DFT(a, false);
    b.resize(n, 0);
    if constexpr (neg_b)
      ranges::reverse(b | views::drop(1));
    DFT(b, false);

    for(int i = 0; i < n; i++)
      a[i] *= b[i];

    DFT(a, true);
    if constexpr (!neg_b)
      a.resize(sz);

    return a;
  }

  template<class Mint>
  vc<Mint> full_pow(vc<Mint> a, int e) {
    if (e == 0) return vc<Mint>(1, 1);

    int sz = (ssize(a) - 1) * e + 1;
    a.resize(bit_ceil(sz * 1ull));
    DFT(a, 0);
    for(Mint &x : a) x = x.pow(e);
    DFT(a, 1);
    a.resize(sz);

    return a;
  }

  template<class T1, class T2>
  vc<T1> vec_conversion(vc<T2> &a) {
    vc<T1> r(size(a));
    for(int i = 0; i < ssize(a); i++) {
      if constexpr (is_integral_v<T2>)
        r[i] = a[i];
      else
        r[i] = a[i].get();
    }
    return r;
  }

  using Mint0 = Montgomery_modint<998'244'353>;
  using Mint1 = Montgomery_modint<469'762'049>;
  using Mint2 = Montgomery_modint<167'772'161>;

  //(T1 = mint): n * mod^2 < prod of mods(~= 5e26) should hold
  //(T1 = ll): result should be within long long
  template<class T1, class T2>
  vc<T1> convolution_CRT(vc<T2> a, vc<T2> b) {
    if (empty(a) or empty(b)) return {};

    auto x = convolution(vec_conversion<Mint0>(a),
                         vec_conversion<Mint0>(b));
    auto y = convolution(vec_conversion<Mint1>(a),
                         vec_conversion<Mint1>(b));
    auto z = convolution(vec_conversion<Mint2>(a),
                         vec_conversion<Mint2>(b));

    static constexpr uint32_t mod0 = 998'244'353, mod1 = 469'762'049;
    static const Mint1 im0 = 1 / Mint1(mod0);
    static const Mint2 im1 = 1 / Mint2(mod1), im0m1 = im1 / mod0;
    static const T1 m0 = mod0, m0m1 = m0 * mod1;

    vc<T1> r(size(x));
    for(int i = 0; i < ssize(x); i++) {
      int y0 = x[i].get();
      int y1 = (im0 * (y[i] - y0)).get();
      int y2 = (im0m1 * (z[i] - y0) - im1 * y1).get();
      r[i] = y0 + m0 * y1 + m0m1 * y2;
    }

    return r;
  }

  template<class T1, class T2>
  vc<T1> full_pow_CRT(vc<T2> a, int e) {
    if (e == 0) return vc<T1>(1, 1);

    auto x = full_pow(vec_conversion<Mint0>(a), 2);
    auto y = full_pow(vec_conversion<Mint1>(a), 2);
    auto z = full_pow(vec_conversion<Mint2>(a), 2);

    static constexpr uint32_t mod0 = 998'244'353, mod1 = 469'762'049;
    static const Mint1 im0 = 1 / Mint1(mod0);
    static const Mint2 im1 = 1 / Mint2(mod1), im0m1 = im1 / mod0;
    static const T1 m0 = mod0, m0m1 = m0 * mod1;

    vc<T1> r(size(x));
    for(int i = 0; i < ssize(x); i++) {
      int y0 = x[i].get();
      int y1 = (im0 * (y[i] - y0)).get();
      int y2 = (im0m1 * (z[i] - y0) - im1 * y1).get();
      r[i] = y0 + m0 * y1 + m0m1 * y2;
    }

    return r;
  }
}

using namespace NTT;

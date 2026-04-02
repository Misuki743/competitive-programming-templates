namespace Stern_Brocot_tree {
  using i128 = __int128;
  struct fraction {
    ll u, d;
    void reduce() {
      ll g = gcd(u, d);
      u /= g, d /= g;
    }
  };
  auto operator<=>(fraction a, fraction b) { return (i128)a.u * b.d <=> (i128)a.d * b.u; }
  bool operator==(fraction a, fraction b) { return (i128)a.u * b.d == (i128)a.d * b.u; }
  ostream& operator<<(ostream &os, fraction f) { os << f.u << ' ' << f.d; return os; }

  auto encode_path(fraction f) {
    f.reduce();

    fraction l{0, 1}, m{1, 1}, r{1, 0};
    vc<pair<char, ll>> path;
    while(f != m) {
      if (f < m) {
        ll x = ceilDiv((i128)f.d * m.u - (i128)f.u * m.d, (i128)f.u * l.d - (i128)f.d * l.u);
        r = fraction{l.u * (x - 1) + m.u, l.d * (x - 1) + m.d};
        path.eb('L', x);
      } else {
        ll x = ceilDiv((i128)f.u * m.d - (i128)f.d * m.u, (i128)f.d * r.u - (i128)f.u * r.d);
        l = fraction{r.u * (x - 1) + m.u, r.d * (x - 1) + m.d};
        path.eb('R', x);
      }
      m = fraction{l.u + r.u, l.d + r.d};
    }
    return path;
  }

  fraction decode_path(vc<pair<char, ll>> path) {
    fraction l{0, 1}, m{1, 1}, r{1, 0};
    for(auto [c, x] : path) {
      if (c == 'L') r = fraction{l.u * (x - 1) + m.u, l.d * (x - 1) + m.d};
      else l = fraction{r.u * (x - 1) + m.u, r.d * (x - 1) + m.d};
      m = fraction{l.u + r.u, l.d + r.d};
    }
    return m;
  }

  fraction LCA(fraction a, fraction b) {
    a.reduce(), b.reduce();
    auto pa = encode_path(a);
    auto pb = encode_path(b);
    ranges::reverse(pa);
    ranges::reverse(pb);
    vc<pair<char, ll>> path;
    while(!pa.empty() and !pb.empty() and pa.back() == pb.back())
      path.eb(pa.back()), pa.pop_back(), pb.pop_back();
    if (!pa.empty() and !pb.empty() and pa.back().first == pb.back().first)
      path.eb(pa.back().first, min(pa.back().second, pb.back().second));
    return decode_path(path);
  }

  fraction ancestor(ll k, fraction f) {
    f.reduce();
    auto path = encode_path(f);
    for(int i = 0; i < ssize(path); i++) {
      auto &[_, x] = path[i];
      if (k <= x) {
        chmin(x, k);
        return decode_path(vector(path.begin(), path.begin() + i + 1));
      }
      k -= x;
    }
    return fraction{-1, 1};
  }

  auto range(fraction f) {
    f.reduce();

    fraction l{0, 1}, m{1, 1}, r{1, 0};
    vc<pair<char, ll>> path;
    while(f != m) {
      if (f < m) {
        ll x = ceilDiv((i128)f.d * m.u - (i128)f.u * m.d, (i128)f.u * l.d - (i128)f.d * l.u);
        r = fraction{l.u * (x - 1) + m.u, l.d * (x - 1) + m.d};
        path.eb('L', x);
      } else {
        ll x = ceilDiv((i128)f.u * m.d - (i128)f.d * m.u, (i128)f.d * r.u - (i128)f.u * r.d);
        l = fraction{r.u * (x - 1) + m.u, r.d * (x - 1) + m.d};
        path.eb('R', x);
      }
      m = fraction{l.u + r.u, l.d + r.d};
    }
    return pair(l, r);
  }
};

using namespace Stern_Brocot_tree;

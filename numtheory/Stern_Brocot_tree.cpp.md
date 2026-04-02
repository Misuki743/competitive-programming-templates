---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/stern_brocot_tree.test.cpp
    title: test/stern_brocot_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/Stern_Brocot_tree.cpp\"\nnamespace Stern_Brocot_tree\
    \ {\n  using i128 = __int128;\n  struct fraction {\n    ll u, d;\n    void reduce()\
    \ {\n      ll g = gcd(u, d);\n      u /= g, d /= g;\n    }\n  };\n  auto operator<=>(fraction\
    \ a, fraction b) { return (i128)a.u * b.d <=> (i128)a.d * b.u; }\n  bool operator==(fraction\
    \ a, fraction b) { return (i128)a.u * b.d == (i128)a.d * b.u; }\n  ostream& operator<<(ostream\
    \ &os, fraction f) { os << f.u << ' ' << f.d; return os; }\n\n  auto encode_path(fraction\
    \ f) {\n    f.reduce();\n\n    fraction l{0, 1}, m{1, 1}, r{1, 0};\n    vc<pair<char,\
    \ ll>> path;\n    while(f != m) {\n      if (f < m) {\n        ll x = ceilDiv((i128)f.d\
    \ * m.u - (i128)f.u * m.d, (i128)f.u * l.d - (i128)f.d * l.u);\n        r = fraction{l.u\
    \ * (x - 1) + m.u, l.d * (x - 1) + m.d};\n        path.eb('L', x);\n      } else\
    \ {\n        ll x = ceilDiv((i128)f.u * m.d - (i128)f.d * m.u, (i128)f.d * r.u\
    \ - (i128)f.u * r.d);\n        l = fraction{r.u * (x - 1) + m.u, r.d * (x - 1)\
    \ + m.d};\n        path.eb('R', x);\n      }\n      m = fraction{l.u + r.u, l.d\
    \ + r.d};\n    }\n    return path;\n  }\n\n  fraction decode_path(vc<pair<char,\
    \ ll>> path) {\n    fraction l{0, 1}, m{1, 1}, r{1, 0};\n    for(auto [c, x] :\
    \ path) {\n      if (c == 'L') r = fraction{l.u * (x - 1) + m.u, l.d * (x - 1)\
    \ + m.d};\n      else l = fraction{r.u * (x - 1) + m.u, r.d * (x - 1) + m.d};\n\
    \      m = fraction{l.u + r.u, l.d + r.d};\n    }\n    return m;\n  }\n\n  fraction\
    \ LCA(fraction a, fraction b) {\n    a.reduce(), b.reduce();\n    auto pa = encode_path(a);\n\
    \    auto pb = encode_path(b);\n    ranges::reverse(pa);\n    ranges::reverse(pb);\n\
    \    vc<pair<char, ll>> path;\n    while(!pa.empty() and !pb.empty() and pa.back()\
    \ == pb.back())\n      path.eb(pa.back()), pa.pop_back(), pb.pop_back();\n   \
    \ if (!pa.empty() and !pb.empty() and pa.back().first == pb.back().first)\n  \
    \    path.eb(pa.back().first, min(pa.back().second, pb.back().second));\n    return\
    \ decode_path(path);\n  }\n\n  fraction ancestor(ll k, fraction f) {\n    f.reduce();\n\
    \    auto path = encode_path(f);\n    for(int i = 0; i < ssize(path); i++) {\n\
    \      auto &[_, x] = path[i];\n      if (k <= x) {\n        chmin(x, k);\n  \
    \      return decode_path(vector(path.begin(), path.begin() + i + 1));\n     \
    \ }\n      k -= x;\n    }\n    return fraction{-1, 1};\n  }\n\n  auto range(fraction\
    \ f) {\n    f.reduce();\n\n    fraction l{0, 1}, m{1, 1}, r{1, 0};\n    vc<pair<char,\
    \ ll>> path;\n    while(f != m) {\n      if (f < m) {\n        ll x = ceilDiv((i128)f.d\
    \ * m.u - (i128)f.u * m.d, (i128)f.u * l.d - (i128)f.d * l.u);\n        r = fraction{l.u\
    \ * (x - 1) + m.u, l.d * (x - 1) + m.d};\n        path.eb('L', x);\n      } else\
    \ {\n        ll x = ceilDiv((i128)f.u * m.d - (i128)f.d * m.u, (i128)f.d * r.u\
    \ - (i128)f.u * r.d);\n        l = fraction{r.u * (x - 1) + m.u, r.d * (x - 1)\
    \ + m.d};\n        path.eb('R', x);\n      }\n      m = fraction{l.u + r.u, l.d\
    \ + r.d};\n    }\n    return pair(l, r);\n  }\n};\n\nusing namespace Stern_Brocot_tree;\n"
  code: "namespace Stern_Brocot_tree {\n  using i128 = __int128;\n  struct fraction\
    \ {\n    ll u, d;\n    void reduce() {\n      ll g = gcd(u, d);\n      u /= g,\
    \ d /= g;\n    }\n  };\n  auto operator<=>(fraction a, fraction b) { return (i128)a.u\
    \ * b.d <=> (i128)a.d * b.u; }\n  bool operator==(fraction a, fraction b) { return\
    \ (i128)a.u * b.d == (i128)a.d * b.u; }\n  ostream& operator<<(ostream &os, fraction\
    \ f) { os << f.u << ' ' << f.d; return os; }\n\n  auto encode_path(fraction f)\
    \ {\n    f.reduce();\n\n    fraction l{0, 1}, m{1, 1}, r{1, 0};\n    vc<pair<char,\
    \ ll>> path;\n    while(f != m) {\n      if (f < m) {\n        ll x = ceilDiv((i128)f.d\
    \ * m.u - (i128)f.u * m.d, (i128)f.u * l.d - (i128)f.d * l.u);\n        r = fraction{l.u\
    \ * (x - 1) + m.u, l.d * (x - 1) + m.d};\n        path.eb('L', x);\n      } else\
    \ {\n        ll x = ceilDiv((i128)f.u * m.d - (i128)f.d * m.u, (i128)f.d * r.u\
    \ - (i128)f.u * r.d);\n        l = fraction{r.u * (x - 1) + m.u, r.d * (x - 1)\
    \ + m.d};\n        path.eb('R', x);\n      }\n      m = fraction{l.u + r.u, l.d\
    \ + r.d};\n    }\n    return path;\n  }\n\n  fraction decode_path(vc<pair<char,\
    \ ll>> path) {\n    fraction l{0, 1}, m{1, 1}, r{1, 0};\n    for(auto [c, x] :\
    \ path) {\n      if (c == 'L') r = fraction{l.u * (x - 1) + m.u, l.d * (x - 1)\
    \ + m.d};\n      else l = fraction{r.u * (x - 1) + m.u, r.d * (x - 1) + m.d};\n\
    \      m = fraction{l.u + r.u, l.d + r.d};\n    }\n    return m;\n  }\n\n  fraction\
    \ LCA(fraction a, fraction b) {\n    a.reduce(), b.reduce();\n    auto pa = encode_path(a);\n\
    \    auto pb = encode_path(b);\n    ranges::reverse(pa);\n    ranges::reverse(pb);\n\
    \    vc<pair<char, ll>> path;\n    while(!pa.empty() and !pb.empty() and pa.back()\
    \ == pb.back())\n      path.eb(pa.back()), pa.pop_back(), pb.pop_back();\n   \
    \ if (!pa.empty() and !pb.empty() and pa.back().first == pb.back().first)\n  \
    \    path.eb(pa.back().first, min(pa.back().second, pb.back().second));\n    return\
    \ decode_path(path);\n  }\n\n  fraction ancestor(ll k, fraction f) {\n    f.reduce();\n\
    \    auto path = encode_path(f);\n    for(int i = 0; i < ssize(path); i++) {\n\
    \      auto &[_, x] = path[i];\n      if (k <= x) {\n        chmin(x, k);\n  \
    \      return decode_path(vector(path.begin(), path.begin() + i + 1));\n     \
    \ }\n      k -= x;\n    }\n    return fraction{-1, 1};\n  }\n\n  auto range(fraction\
    \ f) {\n    f.reduce();\n\n    fraction l{0, 1}, m{1, 1}, r{1, 0};\n    vc<pair<char,\
    \ ll>> path;\n    while(f != m) {\n      if (f < m) {\n        ll x = ceilDiv((i128)f.d\
    \ * m.u - (i128)f.u * m.d, (i128)f.u * l.d - (i128)f.d * l.u);\n        r = fraction{l.u\
    \ * (x - 1) + m.u, l.d * (x - 1) + m.d};\n        path.eb('L', x);\n      } else\
    \ {\n        ll x = ceilDiv((i128)f.u * m.d - (i128)f.d * m.u, (i128)f.d * r.u\
    \ - (i128)f.u * r.d);\n        l = fraction{r.u * (x - 1) + m.u, r.d * (x - 1)\
    \ + m.d};\n        path.eb('R', x);\n      }\n      m = fraction{l.u + r.u, l.d\
    \ + r.d};\n    }\n    return pair(l, r);\n  }\n};\n\nusing namespace Stern_Brocot_tree;\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/Stern_Brocot_tree.cpp
  requiredBy: []
  timestamp: '2026-04-03 02:38:47+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/stern_brocot_tree.test.cpp
documentation_of: numtheory/Stern_Brocot_tree.cpp
layout: document
redirect_from:
- /library/numtheory/Stern_Brocot_tree.cpp
- /library/numtheory/Stern_Brocot_tree.cpp.html
title: numtheory/Stern_Brocot_tree.cpp
---

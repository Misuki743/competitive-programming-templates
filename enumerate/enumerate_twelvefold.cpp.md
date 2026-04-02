---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest_auxiliary_tree.test.cpp
    title: test/mytest_auxiliary_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_enumerate_twelvefold.test.cpp
    title: test/mytest_enumerate_twelvefold.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree.test.cpp
    title: test/mytest_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree_diameter.test.cpp
    title: test/mytest_tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/enumerate_twelvefold.cpp\"\n//#include \"enumerate/bit.cpp\"\
    \n\n//n^k\ntemplate<typename F>\nrequires invocable<F, vector<int>>\nvoid enumerate_cartesian_power(int\
    \ n, int k, F f) {\n  assert(min(n, k) >= 0);\n  vector<int> p(k);\n  auto dfs\
    \ = [&](int i, auto &self) -> void {\n    if (i == k) {\n      f(p);\n    } else\
    \ {\n      for(int x = 0; x < n; x++) {\n        p[i] = x;\n        self(i + 1,\
    \ self);\n      }\n    }\n  };\n  dfs(0, dfs);\n}\n\n//factorial:\n//[1, 2, 6,\
    \ 24, 120,\n// 720, 5040, 40320, 362880, 3628800,\n// 39916800, 479001600, 6227020800,\
    \ 87178291200, 1307674368000]\ntemplate<typename F>\nrequires invocable<F, vector<int>>\n\
    void enumerate_permutation(int n, F f) {\n  assert(n >= 0);\n  vector<int> p(n);\n\
    \  iota(p.begin(), p.end(), 0);\n  do { f(p); } while(next_permutation(p.begin(),\
    \ p.end()));\n}\n\n//binom(n, k)\ntemplate<typename F>\nrequires invocable<F,\
    \ vector<int>>\nvoid enumerate_combination(int n, int k, F f) {\n  assert(min(n,\
    \ k) >= 0);\n  vector<int> p;\n  auto dfs = [&](auto &self) -> void {\n    if\
    \ (ssize(p) == k) {\n      f(p);\n    } else {\n      for(int x = (p.empty() ?\
    \ 0 : p.back() + 1); x + k - ssize(p) <= n; x++) {\n        p.emplace_back(x);\n\
    \        self(self);\n        p.pop_back();\n      }\n    }\n  };\n  dfs(dfs);\n\
    }\n\n//Bell's number:\n//[1, 2, 5, 15, 52,\n// 203, 877, 4140, 21147, 115975,\n\
    // 678570, 4213597, 27644437, 190899322, 1382958545]\ntemplate<typename F>\nrequires\
    \ invocable<F, vector<int>>\nvoid enumerate_set_partition(int n, F f) {\n  assert(n\
    \ >= 0);\n  vector<int> p;\n  int msk = (1 << n) - 1;\n  auto dfs = [&](auto &self)\
    \ -> void {\n    if (msk == 0) {\n      f(p);\n    } else {\n      int x = msk\
    \ & (-msk);\n      msk ^= x;\n      enumerate_subset(msk, [&](int sub) {\n   \
    \     p.emplace_back(sub | x);\n        msk ^= sub;\n        self(self);\n   \
    \     msk ^= sub;\n        p.pop_back();\n      });\n      msk ^= x;\n    }\n\
    \  };\n  dfs(dfs);\n}\n\n//f[0] + f[1] + ... + f[n - 1] = sum, f[i] >= 0\n//binom(sum\
    \ + (n - 1), sum)\ntemplate<typename F>\nrequires invocable<F, vector<int>>\n\
    void enumerate_multisubset(int n, int sum, F f) {\n  assert(min(n, sum) >= 0);\n\
    \  vector<int> p(n);\n  auto dfs = [&](int i, auto &self) -> void {\n    if (i\
    \ == n) {\n      if (sum == 0) f(p);\n    } else {\n      for(int x = sum; x >=\
    \ 0; x--) {\n        p[i] = x, sum -= x;\n        self(i + 1, self);\n       \
    \ sum += x;\n      }\n    }\n  };\n  dfs(0, dfs);\n}\n\n//partition number:\n\
    //n = 10: 42\n//n = 20: 627\n//n = 30: 5604\n//n = 40: 37338\n//n = 50: 204226\n\
    //n = 60: 966467\n//n = 70: 4087968\n//n = 80: 15796476\n//n = 90: 56634173\n\
    //n = 100: 190569292\ntemplate<typename F>\nrequires invocable<F, vector<int>>\n\
    void enumerate_integer_partition(int n, F f) {\n  assert(n >= 0);\n  vector<int>\
    \ p;\n  auto dfs = [&](int s, auto &self) -> void {\n    if (s == 0) {\n     \
    \ f(p);\n    } else {\n      for(int x = (p.empty() ? s : min(p.back(), s)); x\
    \ > 0; x--) {\n        p.emplace_back(x);\n        self(s - x, self);\n      \
    \  p.pop_back();\n      }\n    }\n  };\n  dfs(n, dfs);\n}\n"
  code: "//#include \"enumerate/bit.cpp\"\n\n//n^k\ntemplate<typename F>\nrequires\
    \ invocable<F, vector<int>>\nvoid enumerate_cartesian_power(int n, int k, F f)\
    \ {\n  assert(min(n, k) >= 0);\n  vector<int> p(k);\n  auto dfs = [&](int i, auto\
    \ &self) -> void {\n    if (i == k) {\n      f(p);\n    } else {\n      for(int\
    \ x = 0; x < n; x++) {\n        p[i] = x;\n        self(i + 1, self);\n      }\n\
    \    }\n  };\n  dfs(0, dfs);\n}\n\n//factorial:\n//[1, 2, 6, 24, 120,\n// 720,\
    \ 5040, 40320, 362880, 3628800,\n// 39916800, 479001600, 6227020800, 87178291200,\
    \ 1307674368000]\ntemplate<typename F>\nrequires invocable<F, vector<int>>\nvoid\
    \ enumerate_permutation(int n, F f) {\n  assert(n >= 0);\n  vector<int> p(n);\n\
    \  iota(p.begin(), p.end(), 0);\n  do { f(p); } while(next_permutation(p.begin(),\
    \ p.end()));\n}\n\n//binom(n, k)\ntemplate<typename F>\nrequires invocable<F,\
    \ vector<int>>\nvoid enumerate_combination(int n, int k, F f) {\n  assert(min(n,\
    \ k) >= 0);\n  vector<int> p;\n  auto dfs = [&](auto &self) -> void {\n    if\
    \ (ssize(p) == k) {\n      f(p);\n    } else {\n      for(int x = (p.empty() ?\
    \ 0 : p.back() + 1); x + k - ssize(p) <= n; x++) {\n        p.emplace_back(x);\n\
    \        self(self);\n        p.pop_back();\n      }\n    }\n  };\n  dfs(dfs);\n\
    }\n\n//Bell's number:\n//[1, 2, 5, 15, 52,\n// 203, 877, 4140, 21147, 115975,\n\
    // 678570, 4213597, 27644437, 190899322, 1382958545]\ntemplate<typename F>\nrequires\
    \ invocable<F, vector<int>>\nvoid enumerate_set_partition(int n, F f) {\n  assert(n\
    \ >= 0);\n  vector<int> p;\n  int msk = (1 << n) - 1;\n  auto dfs = [&](auto &self)\
    \ -> void {\n    if (msk == 0) {\n      f(p);\n    } else {\n      int x = msk\
    \ & (-msk);\n      msk ^= x;\n      enumerate_subset(msk, [&](int sub) {\n   \
    \     p.emplace_back(sub | x);\n        msk ^= sub;\n        self(self);\n   \
    \     msk ^= sub;\n        p.pop_back();\n      });\n      msk ^= x;\n    }\n\
    \  };\n  dfs(dfs);\n}\n\n//f[0] + f[1] + ... + f[n - 1] = sum, f[i] >= 0\n//binom(sum\
    \ + (n - 1), sum)\ntemplate<typename F>\nrequires invocable<F, vector<int>>\n\
    void enumerate_multisubset(int n, int sum, F f) {\n  assert(min(n, sum) >= 0);\n\
    \  vector<int> p(n);\n  auto dfs = [&](int i, auto &self) -> void {\n    if (i\
    \ == n) {\n      if (sum == 0) f(p);\n    } else {\n      for(int x = sum; x >=\
    \ 0; x--) {\n        p[i] = x, sum -= x;\n        self(i + 1, self);\n       \
    \ sum += x;\n      }\n    }\n  };\n  dfs(0, dfs);\n}\n\n//partition number:\n\
    //n = 10: 42\n//n = 20: 627\n//n = 30: 5604\n//n = 40: 37338\n//n = 50: 204226\n\
    //n = 60: 966467\n//n = 70: 4087968\n//n = 80: 15796476\n//n = 90: 56634173\n\
    //n = 100: 190569292\ntemplate<typename F>\nrequires invocable<F, vector<int>>\n\
    void enumerate_integer_partition(int n, F f) {\n  assert(n >= 0);\n  vector<int>\
    \ p;\n  auto dfs = [&](int s, auto &self) -> void {\n    if (s == 0) {\n     \
    \ f(p);\n    } else {\n      for(int x = (p.empty() ? s : min(p.back(), s)); x\
    \ > 0; x--) {\n        p.emplace_back(x);\n        self(s - x, self);\n      \
    \  p.pop_back();\n      }\n    }\n  };\n  dfs(n, dfs);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/enumerate_twelvefold.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_auxiliary_tree.test.cpp
  - test/mytest_tree_diameter.test.cpp
  - test/mytest_enumerate_twelvefold.test.cpp
  - test/mytest_tree.test.cpp
documentation_of: enumerate/enumerate_twelvefold.cpp
layout: document
redirect_from:
- /library/enumerate/enumerate_twelvefold.cpp
- /library/enumerate/enumerate_twelvefold.cpp.html
title: enumerate/enumerate_twelvefold.cpp
---

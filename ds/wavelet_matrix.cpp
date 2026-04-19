template<class T, int H>
struct wavelet_matrix {
  using u32 = uint32_t;
  struct bitvec {
    static constexpr u32 W = 64;
    int cnt_0 = 0, sz;
    vc<ull> bit_vec;
    vi ps;

    bitvec(u32 _sz) : sz(_sz), bit_vec(sz / W + 1), ps(sz / W + 1) {}
    void set(u32 i) { bit_vec[i / W] |= 1LL << (i % W); }
    u32 get(u32 i) { return bit_vec[i / W] >> (i % W) & 1; }
    void build() {
      for(int i = 1; i < ssize(ps); i++)
        ps[i] = ps[i - 1] + popcount(bit_vec[i - 1]);
      cnt_0 = rank_0(sz);
    }
    int rank_1(u32 i) { return ps[i / W] + popcount(bit_vec[i / W] & ((1LL << i) - 1)); }
    int rank_0(u32 i) { return i - rank_1(i); }
  };

  vc<bitvec> mat;
  vvi perms; //(H + 1) permutations

  //prepare (H + 1) x size(init) array to maintain extra datas.
  wavelet_matrix(vc<T> init, bool keep = false) : mat(H, bitvec(size(init))) {
    vi perm(size(init));
    iota(perm.begin(), perm.end(), 0);
    if (keep) perms.eb(perm);
    for(int bit = H; auto &v : mat | views::reverse) {
      bit--;
      for(int i = 0; i < ssize(init); i++)
        if (init[perm[i]] >> bit & 1)
          v.set(i);
      v.build();
      vi nxt(size(init));
      array<int, 2> p = {0, v.cnt_0};
      for(int i = 0; i < ssize(init); i++)
        nxt[p[v.get(i)]++] = perm[i];
      perm.swap(nxt);
      if (keep) perms.eb(perm);
    }
    if (keep) ranges::reverse(perms);
  }

  pii next_range(int i, int l, int r, bool right) {
    auto &v = mat[i];
    if (right)
      return pii(v.cnt_0 + v.rank_1(l), v.cnt_0 + v.rank_1(r));
    else
      return pii(v.rank_0(l), v.rank_0(r));
  }

  T kth(int l, int r, int k) {
    T ans = 0;
    for(int i = H - 1; i >= 0; i--) {
      if (auto [l0, r0] = next_range(i, l, r, 0); r0 - l0 <= k) {
        ans |= T(1) << i, k -= r0 - l0;
        tie(l, r) = next_range(i, l, r, 1);
      } else {
        tie(l, r) = tie(l0, r0);
      }
    }
    return ans;
  }

  //F(i, l, r)
  template<typename F> requires R_invocable<void, F, int, int, int>
  void rect_query(int L, int R, T D, T U, F f) {
    auto dfs = [&](int i, T ql, T qr, int l, int r, T d, T u, auto &self) {
      if (l == r or d == u) return;
      if (d == ql and u == qr) {
        f(i + 1, l, r);
        return;
      }

      T mid = (ql + qr) / 2;
      if (u <= mid) {
        tie(l, r) = next_range(i, l, r, 0);
        self(i - 1, ql, mid, l, r, d, u, self);
      } else if (mid <= d) {
        tie(l, r) = next_range(i, l, r, 1);
        self(i - 1, mid, qr, l, r, d, u, self);
      } else {
        auto [l0, r0] = next_range(i, l, r, 0);
        self(i - 1, ql, mid, l0, r0, d, mid, self);
        auto [l1, r1] = next_range(i, l, r, 1);
        self(i - 1, mid, qr, l1, r1, mid, u, self);
      }
    };

    dfs(H - 1, T(0), T(1) << H, L, R, D, U, dfs);
  }

  vvi inv_perms;

  //F(i, j)
  template<typename F> requires R_invocable<void, F, int, int>
  void point_update(int x, F f) {
    if (inv_perms.empty()) {
      inv_perms = perms;
      for(auto &p : inv_perms)
        p = invPerm(p);
    }

    for(int i = 0; i <= H; i++)
      f(i, inv_perms[i][x]);
  }
};

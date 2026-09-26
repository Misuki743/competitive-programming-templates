template<int W, bool duplicate = false>
struct binary_trie {
  vc<array<int32_t, 2>> nxt;
  vi cnt;

  binary_trie(int size = 1) : nxt(1, {-1, -1}), cnt(1) {
    nxt.reserve(size), cnt.reserve(size);
  }

  int count(ull x) {
    int v = 0;
    for(int i = W - 1; i >= 0; i--) {
      v = nxt[v][x >> i & 1];
      if (v == -1) return 0;
    }
    return cnt[v];
  }

  void insert(ull x) {
    if constexpr (!duplicate)
      if (count(x))
        return;
    int v = 0;
    cnt[0]++;
    for(int i = W - 1; i >= 0; i--) {
      if (nxt[v][x >> i & 1] == -1) {
        nxt[v][x >> i & 1] = ssize(nxt);
        nxt.pb({-1, -1}), cnt.eb();
      }
      v = nxt[v][x >> i & 1], cnt[v]++;
    }
  }

  void erase(ull x) {
    if (!count(x)) return;
    int v = 0;
    cnt[0]--;
    for(int i = W - 1; i >= 0; i--)
      v = nxt[v][x >> i & 1], cnt[v]--;
  }

  ull query_min(ull XOR = 0ull) {
    assert(cnt[0] > 0);
    ull ans = 0;
    for(int i = W - 1, v = 0; i >= 0; i--) {
      ull to = XOR >> i & 1;
      if (nxt[v][to] != -1 and cnt[nxt[v][to]] > 0)
        v = nxt[v][to];
      else
        ans |= 1ull << i, v = nxt[v][to ^ 1];
    }
    return ans;
  }

  ull kth(int k, ull XOR = 0ull) {
    assert(cnt[0] > k);
    ull ans = 0;
    for(int i = W - 1, v = 0; i >= 0; i--) {
      ull to = XOR >> i & 1;
      if (nxt[v][to] != -1 and cnt[nxt[v][to]] <= k)
         k -= cnt[nxt[v][to]], to ^= 1;
      else if (nxt[v][to] == -1)
        to ^= 1;
      v = nxt[v][to], ans |= to << i;
    }
    return ans ^ XOR;
  }
};

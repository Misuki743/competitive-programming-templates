template<class V, class E>
struct rerooting_DP {
  HLD &tree;
  vc<V> dp_down, dp_up, dp_full;

  template<typename ID, typename EE, typename ADD_V, typename ADD_E>
  requires
  R_invocable<V, ID,    int             > &&
  R_invocable<E, EE,    const E, const E> &&
  R_invocable<V, ADD_V, const E, int    > &&
  R_invocable<E, ADD_E, const V, int    >
  rerooting_DP(HLD &_tree, ID id, EE ee, ADD_V add_v, ADD_E add_e) : tree(_tree) {
    const int n = tree.n;
    dp_down = dp_up = dp_full = vc<V>(n);

    vc<V> data(n);
    for(int v = 0; v < n; v++) data[v] = id(v);
    auto dfs = [&](int v, auto &self) -> void {
      E prod;
      bool leaf = 1;
      for(int x : tree.childs(v)) {
        self(x, self);
        if (leaf) prod = add_e(data[x], tree.parent_eid(x)), leaf = 0;
        else prod = ee(prod, add_e(data[x], tree.parent_eid(x)));
      }
      if (!leaf) data[v] = add_v(prod, v);
    };
    
    dfs(tree.root, dfs);

    auto dfs2 = [&](int v, auto &self) -> void {
      const int deg = ssize(tree.childs(v)) + (v != tree.root);
      vc<E> pre(deg), suf(deg);
      if (v != tree.root) {
        dp_up[v] = data[tree.parent(v)];
        pre.back() = suf.back() = add_e(data[tree.parent(v)], tree.parent_eid(v));
      }
      for(int i = 0; int x : tree.childs(v)) {
        dp_down[x] = data[x];
        pre[i] = suf[i] = add_e(data[x], tree.parent_eid(x)), i++;
      }
      pSum(pre, ee), pSum(suf | views::reverse, ee);
      V tmp = data[v];
      dp_full[v] = data[v] = (deg ? add_v(suf[0], v) : id(v));
      for(int i = -1; int x : tree.childs(v)) {
        i++;
        bool leaf = 1;
        E prod;
        if (i) prod = pre[i - 1], leaf = 0;
        if (i + 1 < deg) prod = (leaf ? suf[i + 1] : ee(prod, suf[i + 1])), leaf = 0;
        V tmp2 = data[v];
        data[v] = (leaf ? id(v) : add_v(prod, v));
        self(x, self);
        data[v] = tmp2;
      }
      data[v] = tmp;
    };

    dfs2(tree.root, dfs2);
  }

  V operator[](int v) { return dp_full[v]; }
  V get(int v, int r) { return tree.in_subtree_of(v, r) ? dp_down[v] : dp_up[tree.kth(v, r, 1)]; }
};

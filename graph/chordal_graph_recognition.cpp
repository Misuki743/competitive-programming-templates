pair<bool, vi> chordal_graph_recognition(int n, vc<pii> &e) {
  hash_table t;
  for(auto [u, v] : e) {
    if (u > v) swap(u, v);
    t[(ll)u * n + v] = 0;
  }
  auto query = [&](int u, int v) {
    if (u > v) swap(u, v);
    return t.find((ll)u * n + v) != t.end();
  };

  vvi g(n);
  for(auto [u, v] : e)
    g[u].eb(v), g[v].eb(u);

  auto cmp = [](pii &a, pii &b) { return a.first < b.first; };
  vi d(n);
  priority_queue<pii, vc<pii>, decltype(cmp)> pq(cmp, [&]() {
    vc<pii> init(n);
    for(int i = 0; i < n; i++)
      init[i].second = i;
    return init;
  }());

  vi ord, lab(n, INT_MAX);
  while(!pq.empty()) {
    auto [D, V] = pq.top(); pq.pop();
    if (lab[V] != INT_MAX) continue;

    vi adj;
    for(int x : g[V]) {
      if (lab[x] != INT_MAX)
        adj.eb(x);
      else
        pq.emplace(++d[x], x);
    }

    if (!empty(adj)) {
      int mn = ranges::min(adj, {}, [&](int i) { return lab[i]; }), u = -1;
      for(int x : adj)
        if (x != mn and !query(mn, x))
          u = x;

      if (u != -1) {
        dbg(V, lab);
        vi pre(n, -1);
        queue<int> q;
        q.push(mn);
        pre[mn] = n;
        while(!empty(q)) {
          int v = q.front(); q.pop();
          if (v == u) break;
          for(int x : g[v])
            if (pre[x] == -1 and lab[x] != INT_MAX and (x == u or !query(x, V)))
              pre[x] = v, q.push(x);
        }

        vi path = {u};
        while(path.back() != mn)
          path.eb(pre[path.back()]);
        path.eb(V);

        return pair(false, path);
      }
    }

    lab[V] = n - 1 - ssize(ord);
    ord.eb(V);
  }

  ranges::reverse(ord);
  return pair(true, ord);
}

//#include<ds/fenwick_tree.cpp>

template<integral coord, integral weight>
vc<weight> rectangle_sum(vc<tuple<coord, coord, weight>> pt, vc<array<coord, 4>> query) {
  vc<coord> ys;
  for(auto &[_, y, __] : pt) ys.eb(y);
  Unique(ys);

  for(auto &[l, d, r, u] : query) {
    d = ranges::lower_bound(ys, d) - ys.begin();
    u = ranges::lower_bound(ys, u) - ys.begin();
  }

  for(auto &[x, y, w] : pt)
    y = ranges::lower_bound(ys, y) - ys.begin();
  ranges::sort(pt, {}, [](auto &x) { return get<0>(x); });

  struct event { int qid, left; };
  vc<event> es(2 * ssize(query));
  for(int i = 0; i < ssize(query); i++)
    es[i << 1] = event{i, 0}, es[i << 1 | 1] = event{i, 1};
  ranges::sort(es, {}, [&](event &e) { return query[e.qid][e.left ? 0 : 2]; });

  fenwick_tree<weight> ft(size(ys));
  vc<weight> ans(size(query));
  for(int i = 0; auto [qid, left] : es) {
    auto [l, d, r, u] = query[qid];
    while(i < ssize(pt) and get<0>(pt[i]) < query[qid][left ? 0 : 2]) {
      auto [x, y, w] = pt[i++];
      ft.add(y, w);
    }
    ans[qid] += ft.query(d, u) * (left ? -1 : 1);
  }

  return ans;
}

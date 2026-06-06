//#include<ds/fenwick_tree.cpp>

template<integral T>
vi range_count_distinct(vc<T> a, vc<pii> query) {
  vc<T> b = a;
  Unique(b);
  for(T &x : a)
    x = ranges::lower_bound(b, x) - b.begin();

  vi ans(size(query)), pos(size(b), -1);
  fenwick_tree<int> ft(ssize(a));
  for(int j = 0; int i : argSort(query, [](pii &p) { return p.second; })) {
    auto [l, r] = query[i];
    while(j < r) {
      if (pos[a[j]] != -1)
        ft.add(pos[a[j]], -1);
      ft.add(j, 1);
      pos[a[j]] = j, j++;
    }
    ans[i] = ft.query(l, r);
  }

  return ans;
}

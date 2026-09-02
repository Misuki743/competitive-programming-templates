//only for small data structure
//init(ql): init for (ql, 0)
template<class T, typename F, typename G, typename H>
requires R_invocable<T, F, int> &&
         R_invocable<void, G, T&, int, int> && (!R_invocable<void, G, T, int, int>) &&
         R_invocable<void, H, T&, int, int> && (!R_invocable<void, H, T, int, int>)
vc<T> rollback_MO(vc<pii> qry, F init, G dec_l, H inc_r) {
  int n = 1;
  for(auto [l, r] : qry) chmax(n, r);

  const int B = ceilDiv(n, (int)(kth_root(ssize(qry), 2) + 1));

  vc<T> sol(size(qry));
  auto ord = arg_sort(qry, [B](const auto &pr) { return pii(pr.first / B, pr.second); });
  for(auto [l, r] : equal_subarrays(ord, [&](int i) { return qry[i].first / B; })) {
    int ql = (qry[ord[l]].first / B + 1) * B;
    int qr = 0;
    T ans = init(ql);
    for(int i : views::counted(ord.begin() + l, r - l)) {
      while(qr < qry[i].second) inc_r(ans, ql, qr++);
      T tmp = ans;
      for(int j = ql; j > qry[i].first; j--) dec_l(tmp, j, qr);
      sol[i] = tmp;
    }
  }

  return sol;
}

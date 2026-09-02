template<integral T>
auto arg_sort_Mo(vc<pair<T, T>> &v) {
  int n = 1;
  for(auto &[x, y] : v) chmax(n, max(x, y));
  int b = ceil_div(n, (int)kth_root(ssize(v) + 1, 2));
  return pair(
    arg_sort(v, [b](const pii &pr) {
      auto [x, y] = pr;
      return pii(x / b, x / b % 2 == 0 ? y : -y);
    }), b);
}

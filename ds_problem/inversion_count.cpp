template<ranges::random_access_range rng, class T = ranges::range_value_t<rng>>
ll inversion_count(rng R) {
  if (R.empty()) return 0;
  ll f = 0;

  vc<T> tmp(ssize(R));
  auto dc = [&](int l, int r, auto &self) -> void {
    if (l + 1 == r) return;
    int mid = (l + r) / 2;
    self(l, mid, self);
    self(mid, r, self);
    {
      int i = l, j = mid, k = l;
      while(i < mid and j < r) {
        if (R[i] <= R[j]) tmp[k++] = R[i++];
        else tmp[k++] = R[j++], f += mid - i;
      }
      while(i < mid) tmp[k++] = R[i++];
      while(j < r) tmp[k++] = R[j++];
    }
    for(int i = l; i < r; i++)
      R[i] = tmp[i];
  };

  dc(0, ssize(R), dc);

  return f;
}

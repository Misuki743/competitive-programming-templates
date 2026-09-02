namespace output {
  ostream& operator<<(ostream& os, __uint128_t x) {
    if (x == 0) {
      return os << "0";
    } else {
      string s;
      while(x)
        s += '0' + x % 10, x /= 10;
      ranges::reverse(s);
      return os << s;
    }
  }

  ostream& operator<<(ostream& os, __int128_t x) {
    if (x < 0)
      return os << "-" << -(__uint128_t)x;
    else
      return os << (__uint128_t)x;
  }

  template<size_t I = 0, typename... args>
  ostream& print_tuple(ostream& os, const tuple<args...> tu) {
    os << get<I>(tu);
    if constexpr (I + 1 != sizeof...(args)) {
      os << ' ';
      print_tuple<I + 1>(os, tu);
    }
    return os;
  }

  template<typename... args>
  ostream& operator<<(ostream& os, const tuple<args...> tu) {
    return print_tuple(os, tu);
  }

  template<class T1, class T2>
  ostream& operator<<(ostream& os, const pair<T1, T2> pr) {
    return os << pr.first << ' ' << pr.second;
  }

  template<class T>
  concept printable_range =
    ranges::input_range<T> &&
    !same_as<remove_cvref_t<T>, string> &&
    !same_as<remove_cvref_t<T>, string_view> &&
    !same_as<ranges::range_value_t<T>, char>;

  template<printable_range R>
  ostream& operator<<(ostream& os, R&& r) {
    for(bool first = true; auto &&x : r) {
      if (!first) os << ' ';
      first = false;
      os << x;
    }
    return os;
  }

#ifdef DEBUG
#define dbg(...) cerr << '(', _do(#__VA_ARGS__), cerr << ") = ", _do2(__VA_ARGS__)
  template<typename T> void _do(T &&x) { cerr << x; }
  template<typename T, typename ...S> void _do(T &&x, S&&...y) { cerr << x << ", "; _do(y...); }
  template<typename T> void _do2(T &&x) { cerr << x << endl; }
  template<typename T, typename ...S> void _do2(T &&x, S&&...y) { cerr << x << ", "; _do2(y...); }
#else
#define dbg(...)
#endif
}

template<int32_t C>
class divisor_array {
  using i32 = int32_t;

  static inline array<i32, C + 1> s = {};
  static inline vector<i32> d;
  static inline bool init = false;

  public: 

  static void initialize() {
    if (init) return;
    init = true;
    for(int i = 1; i < C; i++)
      for(int j = i; j < C; j += i)
        s[j]++;
    for(int i = 1; i <= C; i++)
      s[i] += s[i - 1];
    d.resize(s[C]);
    for(int i = C - 1; i >= 1; i--)
      for(int j = i; j < C; j += i)
        d[--s[j]] = i;
  }

  static span<const i32> divisor(int x) {
    initialize();
    return span(d.begin() + s[x], d.begin() + s[x + 1]);
  }
};

//auto divisor = &divisor_array<>::divisor;

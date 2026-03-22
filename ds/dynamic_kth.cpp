template<class T>
struct dynamic_kth {
  multiset<T> D, U;
  T Dsum = 0, Usum = 0;
  void slide(int k) { //make |D| = k
    while(ssize(D) > k) {
      T x = *D.rbegin();
      Usum += x, Dsum -= x;
      U.insert(x);
      D.erase(prev(D.end()));
    }
    while(ssize(D) < k and !U.empty()) {
      T x = *U.begin();
      Dsum += x, Usum -= x;
      D.insert(x);
      U.erase(U.begin());
    }
  }
  void insert(T x) {
    if ((U.empty() and (D.empty() or x > *D.rbegin())) or (!U.empty() and x >= *U.begin()))
      U.insert(x), Usum += x;
    else
      D.insert(x), Dsum += x;
  }
  void erase(T x) {
    if (auto ite = U.find(x); ite != U.end())
      U.erase(ite), Usum -= x;
    else if (auto ite2 = D.find(x); ite2 != D.end())
      D.erase(ite2), Dsum -= x;
  }
  T kth(int k) { slide(k); assert(!U.empty()); return *U.begin(); }
  T min() { return D.empty() ? *U.begin() : *D.begin(); }
  T max() { return U.empty() ? *D.rbegin() : *U.rbegin(); }
  uint64_t size() { return ssize(D) + ssize(U); }
};

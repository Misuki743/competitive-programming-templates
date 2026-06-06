//#include<segtree/lazy_segment_tree.cpp>

template<class AM>
struct acted_monoid_segment_tree : lazy_segment_tree<typename AM::M, AM::Mid, AM::Mop, typename AM::T, AM::Tid, AM::Top, AM::act> {
  using base = lazy_segment_tree<typename AM::M, AM::Mid, AM::Mop, typename AM::T, AM::Tid, AM::Top, AM::act>;
  acted_monoid_segment_tree(vector<typename AM::M> init) : base(init) {}
  acted_monoid_segment_tree(int size) : base(size) {}
};

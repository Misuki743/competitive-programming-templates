//#include<modint/Montgomery_modint.cpp>
//#include<poly/NTTmint.cpp>
//#include<poly/FPS.cpp>

template<class Mint>
FPS<Mint> stirling_first_kind(int n) {
  vector<FPS<Mint>> fs(n, {0, 1});
  for(int i = 0; i < n; i++)
    fs[i][0] = -i;
  return FPS<Mint>::allProd(fs);
}

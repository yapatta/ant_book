#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//お金を配列に
const int V[6] = {1,5,10,50,100,500};

signed main(){
  int A;
  int c[6];
  for(int i=0;i<6;i++){
    cin >> c[i];
  }
  cin >> A;
  int ans = 0;
  for(int i=5;i>=0;i--){
    //t: 何個V[i]を取ったか(最大でc[i])
    int t = min(A/V[i],c[i]);
    A -= t*V[i];
    ans += t;
  }
  cout << ans << endl;
}

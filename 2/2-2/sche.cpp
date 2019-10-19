#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define reps(i,s,n) for(ll (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define reptr(i,n) for(ll (i)=(n);(i)>=0;--(i))
#define All(x) (x).begin(),(x).end()
#define Rall(a) (a).rbegin(), (a).rend()
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
using namespace std;

signed main(){
  ll N;
  cin >> N;
  vector<ll> s(N),t(N);
  vector<pll> ts(N);
  rep(i,N){
    cin >> s[i];
  }
  rep(i,N){
    cin >> t[i];
  }
  rep(i,N){
    ts[i] = {t[i],s[i]};
  }

  sort(All(ts));
  ll ans = 1, time = ts[0].first;
  for(ll i=0;i<N;i++){
    //一番直近のfinishをansに代入
    if(time<ts[i].second){
      ans++;
      time = ts[i].first;
    }
  }
  cout << ans << endl;
}

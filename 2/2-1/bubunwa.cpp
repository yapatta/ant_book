#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll k;
ll a[22];

bool dfs(int i,ll sum){
  if(i==n){
    return sum==k;
  }
  if(dfs(i+1,sum)) return true;
  if(dfs(i+1,sum+a[i])) return true;

  return false;
}

signed main(){
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  cin >> k;
  if(dfs(0,0)) cout << "YES" << endl;
  else cout << "NO" << endl;
}

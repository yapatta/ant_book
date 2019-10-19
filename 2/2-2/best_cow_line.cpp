#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
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

int main(){
  int N;
  cin >> N;
  string s,t="";
  cin >> s;
  int l = 0,r = N-1;
  while(1){
    if(l==r){
      cout << s[l] << endl;
      t += s[l];
      break;
    }
    if(s[l]<s[r]) {
      cout << s[l] << endl;
      t += s[l];
      l++;
    }
    else if(s[l]>s[r]){
      cout << s[r] << endl;
      t += s[r];
      r--;
    }
    else{
      int i=1;
      while(1){
        if(l+i<=r-i){
          cout << s[l] << endl;
          t = s[l] + t;
          l++;
          break;
        }
        if(s[l+i]<s[r-i]){
          cout << s[l] << endl;

          t = s[l] + t;
          l++;
          break;
        }else if(s[l+i]>s[r-i]){
          cout << s[r] << endl;
          t = s[r] + t;
          r--;
          break;
        }else{
          i++;
        }
      }
    }
  }
  cout << t << endl;
}

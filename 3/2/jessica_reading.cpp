#include <stdio.h>
#include <set>
#include <map>
using namespace std;
const int MAX_N = 1e6+5;
const int INF = 1e6+5;
int P;
int A[MAX_N];

int main() {
	scanf("%d", &P);
	set<int> sz;
	map<int,int> mp;
	for(int i=0;i<P;i++) {
		scanf("%d",A+i);
		sz.insert(A[i]);
	}
	int cnt = 1;
	mp[A[0]]++;
	int left = 0, right = 1;
	int ans = INF;
	while(right <= P) {
		if(cnt>=sz.size()) {
			// cout << left << " " << right << endl;
			ans = min(ans, right-left);
			mp[A[left]]--;
			if(mp[A[left]] == 0)
				cnt--;
			left++;
		}else {
			mp[A[right]]++;
			if(mp[A[right]] == 1)
				cnt++;
			right++;
		}
	}
	printf("%d\n", ans);
}

#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
	int p;
	scanf("%d", &p);
	vector<int> v(p);
	set<int> st;
	for(int i=0;i<p;i++) {
		scanf("%d", &v[i]);
		st.insert(v[i]);
	}
	int cnt = 0, ans = p, ideas_sum = (int)st.size();
	int left = 0, right = 0;	// [left,right)
	map<int, int> mp;
	while(1) {
		if(right > p) {
			break;
		}
		if(cnt==ideas_sum) {
			// cout << left << " " << right << endl;
			ans = min(ans, right-left);
			if(mp[v[left]] == 1) {
				cnt--;
			}
			mp[v[left]]--;
			left++;
		} else {
			if(mp[v[right]] == 0) {
				cnt++;
			}
			mp[v[right]]++;
			right++;
		}
	}
	printf("%d\n", ans);
}

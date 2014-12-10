#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
	int j,b;
	bool operator < (const Job& x) const {
		return j > x.j;
	}
};

int main() {
	int n,b,j,kase = 1;
	while(scanf("%d",&n),n) {
		vector<Job> v;
		for(int i = 0;i < n;i++) {
			scanf("%d%d",&b,&j);
			v.push_back((Job){j,b});
		}
		sort(v.begin(),v.end());
		int s = 0,ans = 0;
		for(int i = 0;i < n;i++) {
			s += v[i].b;
			ans = max(ans,s + v[i].j);
		}
		printf("Case %d: %d\n",kase++,ans);
	}
	return 0;
}

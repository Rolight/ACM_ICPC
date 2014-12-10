#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

const int maxn = 10001;
int n,val[maxn],d[maxn],g[maxn];

int bsearch(int l,int r,int v) {
	while(l < r) {
		int m = (l + r) >> 1;
		if(g[m] < v) {
			l = m + 1;
		} else r = m;
	}
	return l;
}

int main() {
	while(~scanf("%d",&n)) {
		for(int i = 1;i <= n;i++) {
			scanf("%d",&val[i]);
			g[i] = INT_MAX;
			d[i] = 1;
		}
		int ans = -1;
		for(int i = 1;i <= n;i++) {
			//int k = lower_bound(g + 1,g + i + 1,val[i]) - g;
			int k = bsearch(1,i,val[i]);
			d[i] = k;
			g[k] = val[i];
			ans = max(ans,d[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

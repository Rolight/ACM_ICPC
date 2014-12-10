#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int maxn = 500000 + 5;
const int INF = INT_MAX / 2;
int top[maxn],r[maxn];

int main() {
	int n,kase = 0,a,b;
	while(~scanf("%d",&n)) {
		printf("Case %d:\n",++kase);
		int ans = -1;
		top[0] = 0;
		for(int i = 1;i <= n;i++) {
			scanf("%d%d",&a,&b);
			r[a] = b; top[i] = INF;
		}
		for(int i = 1;i <= n;i++) {
			int k = lower_bound(top + 1,top + 1 + n,r[i]) - top;
			top[k] = r[i];
			ans = max(k,ans);
		}
		printf("My king, at most %d road%s can be built.\n\n",ans,(ans > 1 ? "s" : ""));
	}
	return 0;
}


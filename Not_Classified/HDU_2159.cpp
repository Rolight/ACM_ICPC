#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int maxn = 105;
int f[maxn],c[maxn];

int main() {
	int n,m,k,s;
	while(~scanf("%d%d%d%d",&n,&m,&k,&s)) {
		int get,cost,ans = INT_MAX;
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
		for(int i = 0;i < k;i++) {
			scanf("%d%d",&get,&cost);
			for(int j = cost;j <= m;j++) {
				if(f[j - cost] + get > f[j] && c[j - cost] + 1 <= s) {
					f[j] = f[j - cost] + get;
					c[j] = c[j - cost] + 1;
				}
				if(f[j] >= n && j <= m && j < ans) ans = j;
			}
		}
		if(ans == INT_MAX) puts("-1");
		else printf("%d\n",m - ans);
	}
	return 0;
}

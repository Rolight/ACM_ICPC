#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 105;
const int INF = INT_MAX / 2;

int sum[maxn][maxn],v[maxn][maxn],t[maxn];

int maxsum(int *f,int n) {
	int ans = -INF,now = -INF;
	for(int i = 1;i <= n;i++) {
		now = max(now + f[i],f[i]);
		ans = max(ans,now);
	}
	return ans;
}

int main() {
	int n;
	while(~scanf("%d",&n)) {
		int ans = -INF;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				scanf("%d",&v[i][j]);
				sum[i][j] = sum[i - 1][j] + v[i][j];
			}
		}
		for(int j = 1;j <= n;j++) {
			for(int k = j + 1;k <= n;k++) {
				for(int i = 1;i <= n;i++) {
					t[i] = sum[k][i] - sum[j - 1][i];
				}
				ans = max(ans,maxsum(t,n));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int maxn = 1000000 + 10;
const int INF = INT_MAX / 2;
int f[2][maxn],maxv[maxn];
int a[maxn];

int main() {
	int n,m;
	while(scanf("%d%d",&m,&n) == 2) {
		int ans = -INF;
		for(int i = 1;i <= n;i++) {
			scanf("%d",&a[i]);
			maxv[i] = -INF;
			f[0][i] = f[1][i] = 0;
		}
		for(int ri = 1;ri <= n;ri++) {
			int i = ri & 1,pi = i ^ 1;
			for(int j = min(m,ri);j >= 1;j--) {
				if(ri == j) {
					f[i][j] = f[pi][j - 1] + a[ri];
				} else if(ri > j) {
					f[i][j] = max(maxv[j - 1],f[pi][j]) + a[ri];
				}
				maxv[j] = max(maxv[j],f[i][j]);
			}
			if(ri >= m) ans = max(ans,f[i][m]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
int vis[maxn][maxn],d[maxn][maxn],f[maxn][maxn],g[maxn][maxn],v[maxn],n,s[maxn];

inline int sum(int a,int b) {
	return s[b] - s[a - 1];
}

int main() {
	while(scanf("%d",&n),n) {
		s[0] = 0;
		for(int i = 1;i <= n;i++) {
			scanf("%d",&v[i]);
			d[i][i] = f[i][i] = g[i][i] = v[i];
			s[i] = s[i - 1] + v[i];
		}
		for(int L = 1;L < n;L++) {
			for(int i = 1;i + L <= n;i++) {
				int j = i + L;
				int m = 0;
				m = min(m,f[i + 1][j]);
				m = min(m,g[i][j - 1]);
				d[i][j] = sum(i,j) - m;
				f[i][j] = min(d[i][j],f[i + 1][j]);
				g[i][j] = min(d[i][j],g[i][j - 1]);
			}
		}
		printf("%d\n",2 * d[1][n] - sum(1,n));
	}
	return 0;
}

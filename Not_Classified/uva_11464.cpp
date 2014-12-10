#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 16;
const int INF = 2100000000 / 2;

int mat[maxn][maxn],ans,n;

int getsum(int x,int y,int m[maxn][maxn]) {
	int ans = 0;
	if(x > 1) ans += m[x - 1][y];
	if(x < n) ans += m[x + 1][y];
	if(y > 1) ans += m[x][y - 1];
	if(y < n) ans += m[x][y + 1];
	return ans;
}

int check() {
	int matA[maxn][maxn],ret = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			matA[i][j] = mat[i][j];
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(getsum(i,j,matA) & 1) {
				if(i == n || matA[i + 1][j] == 1) {
					return INF;
				} else {
					matA[i + 1][j] = 1;
					ret++;
				}
			}
		}
	}
	return ret;
}

void dfs(int pos,int ch) {
	if(pos > n) return;
	ans = min(check() + ch,ans);
	dfs(pos + 1,ch);
	if(mat[1][pos] == 0) {
		mat[1][pos] = 1;
		ans = min(ans,check() + ch + 1);
		dfs(pos + 1,ch + 1);
		mat[1][pos] = 0;
	}
}

int main() {
	int T; scanf("%d",&T);
	for(int kase = 1;kase <= T;kase++) {
		scanf("%d",&n);
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				scanf("%d",&mat[i][j]);
			}
		}
		ans = INF;
		dfs(1,0);
		printf("Case %d: ",kase);
		if(ans == INF) {
			puts("-1");
		} else {
			printf("%d\n",ans);
		}
	}
	return 0;
}

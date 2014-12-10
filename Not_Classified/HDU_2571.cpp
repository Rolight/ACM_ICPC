#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

const int maxn = 1010;

using namespace std;

int val[maxn][maxn],C;

int main() {
	scanf("%d",&C);
	while(C--) {
		int n,m; scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				scanf("%d",&val[i][j]);
				int maxv = -INT_MAX;
				if(j > 1) maxv = val[i][j - 1];
				if(i > 1) maxv = max(val[i - 1][j],maxv);
				for(int k = 2;j / k;k++) if(j % k == 0) 
					maxv = max(val[i][j / k],maxv);
				if(i == 1 && j == 1) maxv = 0;
				val[i][j] += maxv;
			}
		}
		printf("%d\n",val[n][m]);
	}
	return 0;
}

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 105;

int w[maxn][maxn],vis[maxn];

int main() {
	int N,Q;
	while(~scanf("%d",&N)) {
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= N;i++) 
			for(int j = 1;j <= N;j++)
				scanf("%d",&w[i][j]);
		scanf("%d",&Q);
		int a,b;
		for(int i = 0;i < Q;i++) {
			scanf("%d%d",&a,&b);
			w[a][b] = w[b][a] = 0;
		}
		//prim
		int ans = 0;
		vis[1] = 1;
		for(int k = 1;k < N;k++) {
			int min = 2100000000,minv;
			for(int i = 1;i <= N;i++) if(vis[i]) {
				for(int j = 1;j <= N;j++) if(j != i && !vis[j]) {
					if(w[i][j] < min) min = w[i][minv = j];
				}
			}
			vis[minv] = 1;
			ans += min;
		}
		printf("%d\n",ans);
	}
	return 0;
}

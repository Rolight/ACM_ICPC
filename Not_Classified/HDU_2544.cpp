#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 101;
const int INF = 1000000000;
int m,n,w[maxn][maxn],d[maxn],vis[maxn];

int main() {
	while(scanf("%d%d",&n,&m),m || n) {
		int s,e,c;
		memset(w,-1,sizeof(w));
		memset(vis,0,sizeof(vis));
		for(int i = 0;i < m;i++) {
			scanf("%d%d%d",&s,&e,&c);
			w[s][e] = w[e][s] = c;
		}
		for(int i = 1;i <= n;i++) w[i][i] = 0,d[i] = INF;
		d[1] = 0;
		for(int k = 1;k <= n;k++) {
			int min = INF,x = 0;
			for(int i = 1;i <= n;i++) if(!vis[i] && d[i] < min) {
				min = d[i]; x = i;
			}
			vis[x] = 1;
			for(int i = 1;i <= n;i++) if(w[x][i] != -1) {
				if(d[i] > d[x] + w[x][i]) d[i] = d[x] + w[x][i];
			}
		}
		printf("%d\n",d[n]);
	}
	return 0;
}

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1001;
const int INF = 1000000000;
int d[maxn],w[maxn][maxn],c[maxn][maxn],p[maxn],vis[maxn],n,m,s,t;

int main() {
	while(scanf("%d%d",&n,&m),m || n) {
		memset(w,-1,sizeof(w));
		memset(c,-1,sizeof(c));
		memset(vis,0,sizeof(vis));
		int str,end,len,cost;
		for(int i = 0;i < m;i++) {
			scanf("%d%d%d%d",&str,&end,&len,&cost);
			if(w[str][end] == -1 || w[str][end] > len || (w[str][end] == len && c[str][end] > cost)) {
				w[str][end] = w[end][str] = len;
				c[str][end] = c[end][str] = cost;
			}
		}
		scanf("%d%d",&s,&t);
		for(int i = 1;i <= n;i++) d[i] = p[i] = INF;
		d[s] = p[s] = 0;
		for(int k = 1;k <= n;k++) {
			int minw = INF,minc = INF,x;
			for(int i = 1;i <= n;i++) if(!vis[i]) {
				if((d[i] < minw) || (d[i] == minw && p[i] < minc)) {
					minw = d[i]; minc = p[i]; x = i;
				}
			}
			vis[x] = 1;
			for(int i = 1;i <= n;i++) if(w[x][i] != -1) {
				if(d[i] > w[x][i] + d[x]) {
					d[i] = w[x][i] + d[x];
					p[i] = c[x][i] + p[x];
				} else if(d[i] == w[x][i] + d[x] && c[x][i] != -1) {
					if(p[i] > c[x][i] + p[x]) {
						d[i] = w[x][i] + d[x];
						p[i] = c[x][i] + p[x];
					}
				}
			}
		}
		printf("%d %d\n",d[t],p[t]);
	}
	return 0;
}

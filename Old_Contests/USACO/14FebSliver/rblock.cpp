#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 251;
const int INF = 2100000000 / 2;
int n,k,g[maxn][maxn],d[maxn],vis[maxn],path[maxn];

void setfile() {
	freopen("rblock.in","r",stdin);
	freopen("rblock.out","w",stdout);
}

void dijkstra(){
	memset(vis,0,sizeof(vis));
	for(int i = 1;i <= n;i++) {
		g[i][i] = 0;
		if(i == 1) d[i] = 0;
		else d[i] = INF;
	}
	for(int i = 1;i <= n;i++) {
		int x,m = INF;
		for(int j = 1;j <= n;j++) 
			if(!vis[j] && d[j] < m)
				m = d[x = j];
		vis[x] = 1;
		for(int j = 1;j <= n;j++) if(g[x][j] != -1) {
			d[j] = min(d[j],d[x] + g[x][j]);
		}
	}
}

void getpath(int now,int t) {
	path[t] = now;
	if(t == 1) return;
	for(int i = 1;i <= n;i++) {
		if(d[now] == d[i] + g[i][now]) {
			getpath(i,t - 1);
			break;
		}
	}
}

int main() {
	freopen("rblock.in","r",stdin);
	freopen("rblock.out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(g,-1,sizeof(g));
	for(int i = 0;i < k;i++) {
		int a,b,t; scanf("%d%d%d",&a,&b,&t);
		g[a][b] = g[b][a] = t;
	}
	dijkstra();
	int old = d[n],ans = 0;
	getpath(n,n);
	for(int i = n;i >= 0;i--) {
		if(path[i + 1] == 1) break;
		int from = path[i],to = path[i + 1];
		g[from][to] = g[to][from] *= 2;
		dijkstra();
		ans = max(ans,d[n] - old);
		g[from][to] = g[to][from] /= 2;
	}
	printf("%d\n",ans);
	return 0;
}

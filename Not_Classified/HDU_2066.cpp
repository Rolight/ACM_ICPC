#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1003;
const int INF = 1000000000;
int w[maxn][maxn],d[maxn],vis[maxn];

int main() {
	int T,S,D;
	while(~scanf("%d%d%d",&T,&S,&D)) {
		memset(w,-1,sizeof(w));
		memset(vis,0,sizeof(vis));
		int a,b,t,N = -1;
		for(int i = 0;i < T;i++) {
			scanf("%d%d%d",&a,&b,&t);
			if(w[a][b] == -1 || w[a][b] > t) w[a][b] = w[b][a] = t;
			if(a > N) N = a; if(b > N) N = b;
		}
		N++;
		for(int i = 0;i < S;i++) {
			scanf("%d",&a);
			w[0][a] = 1;
		}
		for(int i = 0;i < D;i++) {
			scanf("%d",&a);
			w[a][N] = 1;
		}
		for(int i = 0;i <= N;i++) d[i] = INF;
		d[0] = 0;
		for(int k = 0;k <= N;k++) {
			int min = INF,x = -1;
			for(int i = 0;i <= N;i++) if(!vis[i] && d[i] < min) {
				min = d[i]; x = i;
			}
			if(x == -1) continue;
			vis[x] = 1;
			for(int i = 0;i <= N;i++) if(w[x][i] != -1) {
				if(d[i] > d[x] + w[x][i]) d[i] = d[x] + w[x][i];
			}
		}
		printf("%d\n",d[N] - 2);
	}
	return 0;
}

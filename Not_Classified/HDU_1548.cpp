#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 201;
const int INF = 1000000000;
int n,a,b,w[maxn][maxn],vis[maxn],d[maxn];

int main() {
	int tmp;
	while(scanf("%d",&n),n) {
		scanf("%d%d",&a,&b);
		memset(w,-1,sizeof(w));
		for(int i = 1;i <= n;i++) {
			scanf("%d",&tmp);
			if(i - tmp > 0) w[i][i - tmp] = 1;
			if(i + tmp <= n) w[i][i + tmp] = 1;
			w[i][i] = vis[i] = 0;
			d[i] = INF;
		}
		d[a] = 0;
		for(int k = 1;k <= n;k++) {
			int min = INF,x = 0;
			for(int i = 1;i <= n;i++) if(!vis[i] && d[i] < min) {
				min = d[i]; x = i;
			}
			vis[x] = 1; 
			for(int i = 1;i <= n;i++) if(w[x][i] != -1) {
				if(d[i] > w[x][i] + d[x]) d[i] = w[x][i] + d[x];
			}
		}
		if(d[b] == INF) printf("-1\n");
		else printf("%d\n",d[b]);
	}
	return 0;
}

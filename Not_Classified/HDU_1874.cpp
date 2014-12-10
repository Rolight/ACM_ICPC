#include <cstdio>
#include <cstring>

using namespace std;

struct edge {
	int u,v,w;
};

const int maxn = 201;
const int maxm = 1001;
const int INF = 1000000000;

int d[maxn];
edge e[maxm<<1|1];

int main() {
	int n,m,s,t;
	while(~scanf("%d%d",&n,&m)) {
		for(int i = 0;i < m;i++) {
			scanf("%d%d%d",&e[i<<1].u,&e[i<<1].v,&e[i<<1].w);
			e[i<<1|1].v = e[i<<1].u;
			e[i<<1|1].u = e[i<<1].v;
			e[i<<1|1].w = e[i<<1].w;
		}
		scanf("%d%d",&s,&t);
		for(int i = 0;i < n;i++) d[i] = INF;
		d[s] = 0;
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m * 2;j++) {
				if(d[e[j].v] > d[e[j].u] + e[j].w) {
					d[e[j].v] = d[e[j].u] + e[j].w;
				}
			}
		}
		if(d[t] == INF) printf("-1\n");
		else printf("%d\n",d[t]);
	}
	return 0;
}

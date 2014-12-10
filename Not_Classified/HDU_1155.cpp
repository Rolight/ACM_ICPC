#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100;
const int maxv = 3201;

struct Item {
	int cost,w,child,cnum[maxn],fa;
};

Item itm[maxn];
int f[maxv],g[maxv];

int main() {
	int n,limv;
	scanf("%d%d",&limv,&n);
	for(int i = 1;i <= n;i++) {
		scanf("%d%d%d",&itm[i].cost,&itm[i].w,&itm[i].fa);
		if(itm[i].fa) itm[itm[i].fa].cnum[itm[itm[i].fa].child++] = i;
		itm[i].cost /= 10;
	}
	limv /= 10;
	for(int i = 1;i <= n;i++) if(!itm[i].fa) {
		memset(g,0,sizeof(g));
		for(int j = 0;j < itm[i].child;j++) {
			Item &now = itm[itm[i].cnum[j]];
			for(int v = limv;v >= now.cost;v--) {
				g[v] = max(g[v],g[v - now.cost] + now.cost * now.w);
			}
		}
		for(int v = limv;v >= itm[i].cost;v--) {
			for(int v1 = v - itm[i].cost; v1 >= 0;v1--) {
				f[v] = max(f[v],f[v - itm[i].cost - v1] + g[v1] + itm[i].cost * itm[i].w);
			}
		}
	}
	printf("%d\n",f[limv] * 10);
	return 0;
}

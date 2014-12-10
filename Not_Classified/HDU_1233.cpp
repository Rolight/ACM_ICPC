#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge {
	int u,v,w;
};

bool cmp(edge a,edge b) {
	return a.w < b.w;
}

const int maxn = 105;
edge e[maxn * maxn];
int f[maxn];

int findset(int n) {
	return (f[n] == n) ? n : f[n] = findset(f[n]);
}

int main() {
	int n,m;
	while(scanf("%d",&n),n) {
		int ans = 0;
		for(int i = 1;i <= n;i++) f[i] = i;
		m = n * (n - 1) / 2;
		for(int i = 0;i < m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		sort(e,e + m,cmp);
		for(int k = 0;k < n - 1;k++) {
			bool ok = true;
			for(int i = 0;i < m && ok;i++) {
				int x = findset(e[i].u),y = findset(e[i].v);
				if(x != y) {
					ans += e[i].w; f[x] = y; ok = false;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

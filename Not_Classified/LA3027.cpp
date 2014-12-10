#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20001;
int f[maxn],d[maxn];

int findset(int i) {
	if(f[i] == i) return i;
	int root = findset(f[i]);
	d[i] += d[f[i]];
	return f[i] = root;
}

int main() {
	int T,n,v,u;
	char cmd;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i = 1;i <= n;i++) {
			f[i] = i; d[i] = 0;
		}
		while(scanf(" %c",&cmd),cmd != 'O') {
			if(cmd == 'I') {
				scanf("%d%d",&u,&v);
				int x = findset(u),y = findset(v);
				d[u] = abs(u - v) % 1000 + d[v];
				f[x] = y;
			} else {
				scanf("%d",&u);
				findset(u);
				printf("%d\n",d[u]);
			}
		}
	}
	return 0;
}

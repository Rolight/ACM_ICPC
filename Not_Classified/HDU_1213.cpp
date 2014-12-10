#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 2000;

int f[maxn];

int findset(int n) {
	return (f[n] == n) ? n : f[n] = findset(f[n]);
}

int main() {
	int T,n,m,a,b;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++) f[i] = i;
		for(int i = 0;i < m;i++) {
			scanf("%d%d",&a,&b);
			if(findset(a) != findset(b)) {
				f[findset(a)] = findset(b);
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++) if(f[i] == i) ans++;
		printf("%d\n",ans);
	}
	return 0;
}


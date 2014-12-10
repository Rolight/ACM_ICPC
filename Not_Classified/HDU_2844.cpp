#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int f[100001],c[101],v[101];

int main() {
	int n,m;
	while(scanf("%d%d",&n,&m),n || m) {
		memset(f,0,sizeof(f));	f[0] = 0;
		for(int i = 1;i <= n;i++) scanf("%d",v + i);
		for(int i = 1;i <= n;i++) scanf("%d",c + i);
		for(int i = 1;i <= n;i++) {
			if(c[i] * v[i] >= m) {
				for(int j = v[i];j <= m;j++) {
					f[j] = max(f[j],f[j - v[i]] + v[i]);
				}
			} else {
				int k = 1,M = c[i];
				while(k < M) {
					for(int j = m;j >= k * v[i];j--)
						f[j] = max(f[j],f[j - k * v[i]] + k * v[i]);
					M -= k; k *= 2;
				}
				for(int j = m;j >= M * v[i];j--)
					f[j] = max(f[j],f[j - M * v[i]] + M * v[i]);
			}
		}
		int ans = 0;
		for(int i = 1;i <= m;i++) if(i == f[i]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}

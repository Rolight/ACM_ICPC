#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 51;
int n,ans,h[maxn];
int f[2][500005];

void solve() {
	int sum = 0;
	memset(f,128,sizeof(f));
	f[0][0] = f[1][0] = 0;
	for(int i = 1;i <= n;i++) {
		int now = i & 1,prev = (i & 1 ^ 1);
		sum += h[i];
		for(int d = sum;d >= 0;d--) {
			f[now][d] = f[prev][d];
			if(d > h[i]) {
			   	f[now][d] = max(f[now][d],f[prev][d - h[i]]);
			}
			else {
			   	f[now][d] = max(f[now][d],f[prev][h[i] - d] + h[i] - d);
			}
			if(d + h[i] <= 500000) f[now][d] = max(f[now][d],f[prev][d + h[i]] + h[i]);
		}
		ans = max(ans,f[now][0]);
	}
}

int main() {
	while(~scanf("%d",&n)) {
		for(int i = 1;i <= n;i++) scanf("%d",&h[i]);
		ans = 0;
		solve();
		printf("%d\n",ans == 0 ? -1 : ans);
	}
	return 0;
}

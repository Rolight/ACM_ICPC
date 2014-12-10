#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10001;
int f[maxn];

int main() {
	int n,m,k;
	while(scanf("%d%d%d",&n,&k,&m),n) {
		f[1] = 0;
		for(int i = 2;i <= n;i++) f[i] = (f[i - 1] + k) % i;
		int ans = (m - k + 1 + f[n]) % n;
		while(ans <= 0) ans += n;
		printf("%d\n",ans);
	}
	return 0;
}

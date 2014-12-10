#include <cstdio>
#include <cstring>

using namespace std;

int f[1001],g[1001],h[1001];

int main() {
	f[0] = 1; g[0] = h[0] = 0;
	for(int i = 1;i <= 1000;i++) {
		f[i] = (g[i - 1] + h[i - 1]) % 10000;
		g[i] = (f[i - 1] + h[i - 1]) % 10000;
		h[i] = (g[i - 1] + f[i - 1]) % 10000;
	}
	int n;
	while(scanf("%d",&n),n) printf("%d\n",f[n]);
	return 0;
}


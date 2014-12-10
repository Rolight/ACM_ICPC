#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
int f[maxn][maxn];

int main() {
	int n,T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= i;j++)
				scanf("%d",&f[i][j]);
		for(int i = n - 1;i >= 1;i--)
			for(int j = 1;j <= i;j++)
				f[i][j] += max(f[i + 1][j],f[i + 1][j + 1]);
		printf("%d\n",f[1][1]);
	}
	return 0;
}

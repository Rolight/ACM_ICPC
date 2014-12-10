#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxk = 1005;
const int maxn = 5005;
int a[maxn],f[maxn][maxk];

#define sq(x) ((x)*(x))

int main() {
	int T,K,N;
	scanf("%d",&T);
	while(T--) {
		memset(f,127,sizeof(f));
		scanf("%d%d",&K,&N);
		for(int i = 1;i <= N;i++) {
			scanf("%d",a + i);
			f[i][0] = 0;
		}
		sort(a + 1,a + N + 1);
		f[0][0] = 0;
		
		for(int i = N - 2;i >= 1;i--) {
			for(int j = 1;j <= (N-i+1) / 3;j++) {
				f[i][j] = min(f[i+2][j-1]+sq(a[i]-a[i+1]),f[i+1][j]);
			}
		}
		printf("%d\n",f[1][K + 8]);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int maxn = 105;
int f[maxn][maxn];

int main() {
	int n,m,k,s;
	while(~scanf("%d%d%d%d",&n,&m,&k,&s)) {
		int get,cost,ans = INT_MAX;
		memset(f,0,sizeof(f));
		for(int i = 0;i < k;i++) {
			scanf("%d%d",&get,&cost);
			for(int j = cost;j <= m;j++) {
				for(int l = 1;l <= s;l++) {
					f[j][l] = max(f[j - cost][l - 1] + get,f[j][l]);
				}
			}
		}
		if(f[m][s] < n) puts("-1");
		else {
			for(int i = 1;i <= m;i++) if(f[i][s] >= n) {
				printf("%d\n",m - i);
				break;
			}
		}
	}
	return 0;
}

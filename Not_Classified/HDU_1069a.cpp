#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int maxn = 40;
bool reach[maxn * 3][maxn * 3];
int x[maxn * 3],y[maxn * 3],z[maxn * 3],f[maxn * 3];

inline bool contain(int x1,int y1,int x2,int y2) {
	return (x1 < y2 && y1 < x2) || (x1 < x2 && y1 < y2);
}

int main() {
	int n,cc = 0;
	while(scanf("%d",&n),n) {
		memset(reach,0,sizeof(reach));
		for(int i = 0;i < n * 3;i += 3) {
			int a,b,c; scanf("%d%d%d",&a,&b,&c);
			x[i] = a; y[i] = b; z[i] = c;
			x[i + 1] = b; y[i + 1] = c; z[i + 1] = a;
			x[i + 2] = a; y[i + 2] = c; z[i + 2] = b;
		}
		for(int i = 0;i < 3 * n;i++) f[i] = z[i];
		for(int k = 0;k < 3 * n;k++) {
			for(int i = 0;i < 3 * n;i++) {
				for(int j = 0;j < 3 * n;j++) {
					if(contain(x[i],y[i],x[j],y[j])) {
						f[j] = max(f[j],f[i] + z[j]);
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0;i < 3 * n;i++) if(f[i] > ans) ans = f[i];
		printf("Case %d: maximum height = %d\n",++cc,ans);
	}
	return 0;
}

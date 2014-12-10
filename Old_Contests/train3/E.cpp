#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 105;

int buf[maxn][maxn];

int main() {
	int n,m,r,c;
	while(scanf("%d%d%d%d",&n,&m,&r,&c),n|m|r|c) {
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				scanf("%1d",&buf[i][j]);
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				if(buf[i][j] && i + r - 1 <= n && j + c - 1 <= m) {
					for(int k = i;k <= i + r - 1;k++) {
						for(int l = j;l <= j + c - 1;l++) {
							buf[k][l] ^= 1;
						}
					}
					ans++;
				}
			}
		}
		int sum = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				sum += buf[i][j];
			}
		}
		if(sum == 0) printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}

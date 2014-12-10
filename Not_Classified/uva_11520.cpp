#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

const int maxn = 15;

int a[maxn][maxn];

int main() {
	int T,n;
	char ch;
	scanf("%d",&T);
	memset(a,-1,sizeof(a));
	for(int kase = 1;kase <= T;kase++) {
		scanf("%d",&n);
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				scanf(" %c",&ch);
				if(ch == '.') {
					a[i][j] = -1;
				} else {
					a[i][j] = ch - 'A';
				}
			}
		}
		printf("Case %d:\n",kase);
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				if(a[i][j] == -1) {
					for(int k = 0;k < 26;k++) {
						if(k != a[i - 1][j] && k != a[i + 1][j] && k != a[i][j - 1] && k != a[i][j + 1]) {
							a[i][j] = k; break;
						}
					}
				}
				putchar('A' + a[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}

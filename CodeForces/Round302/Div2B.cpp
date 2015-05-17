#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 105;
char bc[maxn][maxn];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			bc[i][j] = 'S';
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if((i + j) % 2 == 0 && k > 0) {
				bc[i][j] = 'L';
				k--;
			}
		}
	}
	if(k == 0) {
		puts("YES");
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				putchar(bc[i][j]);
			}
			puts("");
		}
	}
	else puts("NO");
	return 0;
}


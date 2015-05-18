#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1005;
const int mod = 100007;
int f[maxn][maxn], n;
char buf[maxn], rev[maxn];

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%s", buf + 1);
		n = strlen(buf + 1);
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++) {
			f[i][i] = 1;
		}
		for(int k = 2; k <= n; k++) {
			//³¤¶È
			for(int i = 1; i + k - 1 <= n; i++) {
				int j = i + k - 1;
				f[i][j] += f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
				f[i][j] = (f[i][j] + mod) % mod;
				if(buf[i] == buf[j]) {
					f[i][j] += f[i + 1][j - 1] + 1;
					f[i][j] %= mod;
				}
			}
		}
		printf("Case #%d: %d\n", kase, f[1][n] % mod);
	}
	return 0;
}

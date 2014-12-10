#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1005;
const int maxm = 1005;
int w[maxn][maxn], sum[maxn], num[maxn];
int n, m, f[maxn][maxm], s[maxn][maxn];

int main() {
	while (scanf("%d%d", &n, &m), n) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &num[i]);
		}
		memset(w, 0, sizeof(w));
		for (int i = 1; i <= n; i++) {
			sum[i] = num[i];
			for (int j = i + 1; j <= n; j++) {
				sum[j] = sum[j - 1] + num[j];
				w[i][j] = w[i][j - 1] + num[j] * sum[j - 1];
			}
		}
		//dp
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				f[i][j] = 1e9;
			}
		}
		for (int i = 1; i <= n; i++) {
			f[i][0] = w[1][i];
			s[0][i] = 1;
		}
		//s(i - 1,j) <= s(i,j) <= s(i,j + 1)
		for (int i = 1; i <= n; i++) {
			s[i][i] = i - 1;
			for (int j = i - 1; j >= 1; j--) {
				for (int k = s[i - 1][j]; k <= s[i][j + 1]; k++) {
					if (f[k][j - 1] + w[k + 1][i] < f[i][j]) {
						f[i][j] = f[k][j - 1] + w[k + 1][i];
						s[i][j] = k;
					}
				}
			}
		}
		printf("%d\n", f[n][m]);
	}
	return 0;
}

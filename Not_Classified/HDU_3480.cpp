#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

#define sq(x) ((x)*(x))

const int maxn = 10005;
const int maxm = 5005;
int f[maxn][maxm], s[maxn][maxm];
int val[maxn], n, m;

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1;kase <= T;kase++) {
		scanf("%d%d", &n, &m); m--;
		for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
		sort(val + 1, val + 1 + n);
		for (int i = 1; i <= n; i++) {
			f[i][0] = sq(val[i] - val[1]);
			int sj = min(m, i - 1);
			s[i][sj + 1] = i - 1;
			for (int j = sj; j >= 1;j--) {
				f[i][j] = INT_MAX / 3;
				for (int k = s[i - 1][j]; k <= s[i][j + 1]; k++) {
					if (f[k][j - 1] + sq(val[i] - val[k + 1]) < f[i][j]) {
						f[i][j] = f[k][j - 1] + sq(val[i] - val[k + 1]);
						s[i][j] = k;
					}
				}
			}
		}
		printf("Case %d: %d\n", kase, f[n][m]);
	}
	return 0;
}

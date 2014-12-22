#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 600;
const int INF = 1e9;
int f[maxn][maxn], n, k;
int px[maxn], py[maxn], dist[maxn][maxn];

inline int abs(int x) {
	return x < 0 ? -x : x;
}

int main() {
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	scanf("%d%d", &n, &k);
	k = std::min(k, n - 2);
	for(int i = 1; i <= n; i++) scanf("%d%d", &px[i], &py[i]);
	for(int i = 1; i <= n; i++) {
		f[i][0] = INF;
		for(int j = 1; j <= n; j++) {
			dist[i][j] = abs(px[i] - px[j]) + abs(py[i] - py[j]);
			f[i][j] = INF;
		}
	}
	f[1][0] = 0;
	for(int i = 1; i < n; i++) {
		for(int nk = 0; nk < i && nk <= k; nk++) {
			for(int j = 0; i + j < n && j + nk <= k; j++) {
				f[i + j + 1][nk + j] = 
					std::min(f[i + j + 1][nk + j], f[i][nk] + dist[i][i + j + 1]);
			}
		}
	}
	int ans = INF;
	for(int i = 0; i <= k; i++) ans = std::min(ans, f[n][i]);
	printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}

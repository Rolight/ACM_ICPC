#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50001;
int minv[maxn][20],maxv[maxn][20],n,val[maxn],q;
void init_RMQ() {
	for (int i = 0; i < n; i++) minv[i][0] = maxv[i][0] = val[i];
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) < n + 1; i++) {
			maxv[i][j] = max(maxv[i][j - 1], maxv[i + (1 << (j - 1))][j - 1]);
			minv[i][j] = min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) scanf("%d", val + i);
	init_RMQ();
	int a, b;
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &a, &b); a--; b--;
		int k = 0;
		while ((1 << (k + 1)) <= b - a + 1) k++;
		printf("%d\n", max(maxv[a][k], maxv[b - (1 << k) + 1][k]) - min(minv[a][k], minv[b - (1 << k) + 1][k]));
	}
	return 0;
}
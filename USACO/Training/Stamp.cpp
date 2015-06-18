/*
ID: flsnnx1
LANG: C++
TASK: stamps
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>

const int maxn = 205;
const int maxm = 1e4 + 5;
const int inf = INT_MAX / 6;

//f[i]表示构成面额i最少用几张
int N, K, f[maxn * maxm], num[maxn];

int main() {
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	int maxv = -1;
	scanf("%d%d", &K, &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
		maxv = std::max(maxv, num[i]);
	}
	f[0] = 0;
	for(int i = 1; i <= maxv * K + 1; i++) f[i] = inf;
	int ans = -1;
	for(int i = 0;; i++) {
		if(f[i] == inf) {
			ans = i - 1; break;
		}
		if(f[i] >= K) continue;
		for(int j = 1; j <= N; j++) {
			f[i + num[j]] = std::min(f[i + num[j]], f[i] + 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}


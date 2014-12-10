#include <cstdio>
#include <cstring>

using namespace std;

int val[20];

void dfs(int now, int prev, int num = 0) {
	if (now == 5) return;
	if (now >= 1) {
		val[now * 2]++; val[now * 2 - 1]++;
	}
	for (int i = prev + 1; i <= 9; i++) {
		dfs(now + 1, i, num * 10 + i);
	}
}

int main() {
	dfs(0, 0);
	int T; scanf("%d", &T);
	val[0] = 1;
	for (int i = 2; i <= 6; i++) val[i] += val[i - 1];
	while (T--) {
		int n; scanf("%d", &n);
		printf("%d\n", val[n]);
	}
	return 0;
}
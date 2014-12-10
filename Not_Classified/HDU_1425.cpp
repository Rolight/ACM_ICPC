#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)

using namespace std;
const int maxn = 1000000 + 10;
const int lp = 500000;
int cnt[maxn], n, m;

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(cnt, 0, sizeof(cnt));
		int tmp, out = 0, minval = lp * 2 + 5, maxval = -lp - 5;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			cnt[tmp + lp]++;
			minval = MIN(minval, tmp + lp);
			maxval = MAX(maxval, tmp + lp);
		}
		for (int i = maxval; i >= minval && out < m; i--) {
			for (int j = 0; j < cnt[i] && out < m; j++) {
				if (out) putchar(' ');
				printf("%d", i - lp);
				out++;
			}
		}
		putchar('\n');
	}
	return 0;
}

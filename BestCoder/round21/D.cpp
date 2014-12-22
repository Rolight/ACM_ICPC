#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;
const int inf = 1e9 + 10;
int a[maxn], ts[maxn], tcnt, n;


void gao() {
	for(int i = 0; i < n; i++) ts[i] = inf;
	int llen = 1;
	tcnt = 1;
	for(int i = 1; i <= n; i++) {
		int pos = lower_bound(ts, ts + tcnt, a[i]) - ts;
		ts[pos] = a[i];
		if(pos == tcnt) tcnt++;
		llen = max(llen, tcnt);
	}
	tcnt = 1;
	for(int i = 0; i < n; i++) ts[i] = inf;
	int ubd = 0, ans = 0, lbd = 1;
	for(int i = 1; i <= n; i++) {
		int pos = lower_bound(ts, ts + tcnt, a[i]) - ts;
		ts[pos] = a[i];
		if(pos == tcnt) tcnt++;
		if(pos == 0) {
			ubd = 0; tcnt = 1;
		}
		if(pos + 1 == llen && ubd == 0) {
			ans += (n - i + 1) * lbd;
			ubd = 1; lbd++;
		}
	}
	printf("%d\n", ans);
}

int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		gao();
	}
	return 0;
}

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
#include <cstdlib>

typedef long long LL;

const int maxn = 1e5 + 10;
const int maxv = 2e6 + 10;
int num[maxn], n, val[maxn];

bool ok(int v) {
	int rev = num[1] - v;
	for(int i = 2; i <= n; i++) {
		int now = rev + 1 - num[i];
		if(now < 0) now = -now;
		if(now <= v) rev++;
		else {
			if(num[i] + v < rev + 1) return false;
			else rev = num[i] - v;
		}
	}
	return true;
}

void solve() {
	int l = 0, r = maxv, ans = -1, mid;
	while(l <= r) {
		mid = l + r >> 1;
		if(ok(mid)) {
			ans = mid; r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", num + i);
		printf("Case #%d:\n", kase);
		solve();
	}
	return 0;
}

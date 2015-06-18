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

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

const int maxn = 1e4 + 10;

LL n, m, k, a[maxn];

void solve() {
	std::sort(a + 1, a + 1 + n);
	if(m < a[1]) {
		puts("madan!"); return;
	}
	LL str = std::lower_bound(a + 1, a + 1 + n, m) - a;
	if(str == n + 1 || a[str] > m) str--;
	LL nowk = k, flag = 0, nowm = a[str];
	for(int i = str; i <= n; i++) {
		if(nowm > a[i]) flag = 1;
		else if(nowm < a[i]) {
			puts("madan!"); return;
		}
		else if(flag == 0 && nowk > 0) {
			if(nowm + nowk >= a[n]) nowm += nowk;
			else if(i + 1 <= n) {
				if(a[i + 1] > nowm)
					nowm += std::min(nowk, a[i + 1] - nowm);
			}
		}
		nowk--;
	}
	puts("why am I so diao?");
}

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%I64d%I64d%I64d", &n, &m, &k);
		for(int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
		printf("Case #%d:\n", kase);
		solve();
	}
	return 0;
}

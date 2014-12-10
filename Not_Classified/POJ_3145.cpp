#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
const int maxn = 5e5 + 10;
const int inf = 1e9;
const int MAX = 5e5;
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
int minv[maxn << 2], num[maxn], numcnt, n, itime[maxn];
int maxval;

void build(int rt, int l, int r) {
	int mid = (l + r) >> 1;
	minv[rt] = inf;
	if(l == r) return;
	build(lson); build(rson);
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) minv[rt] = val;
	else {
		int mid = (l + r) >> 1;
		if(pos <= mid) update(lson, pos, val);
		else update(rson, pos, val);
		minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]);
	}
} 

int query(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && qr >= r) return minv[rt];
	else {
		int mid = (l + r) >> 1, ret = inf;
		if(ql <= mid) ret = min(ret, query(lson, ql, qr));
		if(qr > mid) ret = min(ret, query(rson, ql, qr));
		return ret;
	}
}

int ask_min(int mod) {
	int ans = inf, anstime = -1;
	for(int i = numcnt - 1; i >= 0; i--) {
		if(num[i] % mod < ans) {
			ans = num[i] % mod;
			anstime = itime[num[i]];
		}
		if(ans == 0) break;
	}
	return anstime;
}

int ask_max(int mod) {
	int l = 0, r = mod - 1, ans = inf, anstime = -1;
	while(l <= MAX) {
		if(r > MAX) r = MAX;
		int nowval = query(1, 0, MAX, l, r);
		if(nowval % mod == ans && nowval != inf) {
			anstime = max(anstime, itime[nowval]);
		}
		if(nowval % mod < ans && nowval != inf) {
			ans = nowval % mod; anstime = itime[nowval];
		}
		l += mod; r += mod;
	}
	return anstime;
}

int main() {
	int kase = 1;
	while(scanf("%d", &n) && n) {
		if(kase > 1) puts("");
		numcnt = 0; maxval = 0;
		printf("Case %d:\n", kase++);
		if(n == 0) break;
		build(1, 0, MAX);
		char cmd[10]; int val;
		for(int i = 1; i <= n; i++) {
			scanf("%s%d", cmd, &val);
			if(cmd[0] == 'B') {
				update(1, 0, MAX, val, val);
				num[numcnt++] = val;
				itime[val] = numcnt;
				maxval = max(maxval, val);
			}
			else {
				int ret;
				if(val <= 5000) ret = ask_min(val);
				else ret = ask_max(val);
				printf("%d\n", ret);
			}
		}
	}
	return 0;
}

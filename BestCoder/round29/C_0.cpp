//预处理前缀和+线段树解法
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

const int maxn = 1e6 + 10;
int n, q, arr[maxn], pre[maxn], maxv[maxn << 2], pos[maxn];
LL sum[maxn];

void build(int rt, int l, int r) {
	int mid = l + r >> 1;
	if(l == r) maxv[rt] = pre[l];
	else {
		build(lson); build(rson);
		maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
	}
}

int ask(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && qr >= r) return maxv[rt];
	int ret = -1, mid = l + r >> 1;
	if(ql <= mid) ret = max(ret, ask(lson, ql, qr));
	if(qr > mid) ret = max(ret, ask(rson, ql, qr));
	return ret;
}

void preprocess() {
	memset(pos, -1, sizeof(pos));
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
		pre[i] = pos[arr[i]];
		pos[arr[i]] = i;
	}
	build(1, 1, n);
}

void gao(int l, int r) {
	LL len = r - l + 1, tsum = (1 + len) * len / 2;
	int tp = ask(1, 1, n, l, r);
	if(tsum == sum[r] - sum[l - 1] && tp < l) puts("YES");
	else puts("NO");
}

int main() {
	while(scanf("%d%d", &n, &q) != EOF) {
		for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		preprocess();
		int l, r;
		for(int i = 1; i <= q; i++) {
			scanf("%d%d", &l, &r);
			gao(l, r);
		}
	}
	return 0;
}

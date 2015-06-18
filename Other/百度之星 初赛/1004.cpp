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

const int maxn = 1e4 + 10;

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

int cnt[maxn << 2];

inline void pushup(int rt) {
	cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	if(l == r) cnt[rt] = 0;
	else {
		int mid = l + r >> 1;
		build(lson); build(rson);
		pushup(rt);
	}
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) cnt[rt] = val;
	else {
		int mid = l + r >> 1;
		if(pos <= mid) update(lson, pos, val);
		else update(rson, pos, val);
		pushup(rt);
	}
}

int findkth(int rt, int l, int r, int k) {
	int lc = rt << 1, rc = rt << 1 | 1, mid = l + r >> 1;
	if(l == r) return l;
	if(cnt[lc] >= k) return findkth(lson, k);
	else return findkth(rson, k - cnt[lc]);
}


char cmd[maxn][16];
int val[maxn], n, numv[maxn], numc;

inline int getid(int c) {
	return std::lower_bound(numv + 1, numv + numc + 1, c) - numv;
}

int main() {
	int kase = 1;
	while(scanf("%d", &n) != EOF) {
		numc = 0;
		for(int i = 0; i < n; i++) {
			scanf("%s", cmd[i]);
			if(cmd[i][0] == 'i') {
				scanf("%d", &val[i]);
				numv[++numc] = val[i];
			}
		}
		std::sort(numv + 1, numv + 1 + numc);
		std::queue<int> q;
		build(1, 1, numc);
		int nowin = 0, v;
		printf("Case #%d:\n", kase++);
		for(int i = 0; i < n; i++) {
			if(cmd[i][0] == 'i') {
				nowin++;
				v = getid(val[i]);
				update(1, 1, numc, v, 1);
				q.push(v);
			}
			else if(cmd[i][0] == 'o') {
				v = q.front();
				q.pop();
				update(1, 1, numc, v, 0);
				nowin--;
			}
			else {
				v = findkth(1, 1, numc, nowin / 2 + 1);
				printf("%d\n", numv[v]);
			}
		}
	}
	return 0;
}

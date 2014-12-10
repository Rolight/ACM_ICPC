#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 100000 + 10;
const int maxm = maxn * 30;

int lc[maxm], rc[maxm], sumv[maxm], cnt;
int root[maxn], n, q, a[maxn];
vector<int> vnum;

void init() {
	cnt = 1;
	root[0] = 0;
}

void build(int rt, int l, int r) {
	sumv[rt] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	lc[rt] = cnt++; rc[rt] = cnt++;
	build(lc[rt], l, mid);
	build(rc[rt], mid + 1, r);
}


void update1(int rt, int prt, int l, int r, int pos, int val) {
	int mid = (l + r) >> 1;
	if (l == r) return;
	if (pos <= mid) {
		int newrt = cnt++;
		lc[rt] = newrt;
		sumv[newrt] = sumv[lc[prt]] + val;
		rc[rt] = rc[prt];
		update1(newrt, lc[prt], l, mid, pos, val);
	}
	else {
		int newrt = cnt++;
		rc[rt] = newrt;
		sumv[newrt] = sumv[rc[prt]] + val;
		lc[rt] = lc[prt];
		update1(newrt, rc[prt], mid + 1, r, pos, val);
	}
}

void update(int rt, int pos, int val) {
	root[rt] = cnt++;
	sumv[root[rt]] = sumv[root[rt - 1]] + val;
	update1(root[rt], root[rt - 1], 1, n, pos, val);
}

int query(int lroot, int rroot, int l, int r, int k) {
	int mid = (l + r) >> 1, nowsum = sumv[lc[rroot]] - sumv[lc[lroot]];
	if (l == r) return vnum[l - 1];
	if (nowsum >= k) return query(lc[lroot], lc[rroot], l, mid, k);
	else return query(rc[lroot], rc[rroot], mid + 1, r, k - nowsum);
}

int getid(int val) {
	return lower_bound(vnum.begin(), vnum.end(), val) - vnum.begin() + 1;
}

int main() {
	while (scanf("%d%d", &n, &q) != EOF) {
		init(); vnum.clear();
		build(root[0], 1, n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			vnum.push_back(a[i]);
		}
		sort(vnum.begin(), vnum.end());
		vnum.erase(unique(vnum.begin(), vnum.end()), vnum.end());
		for (int i = 1; i <= n; i++) {
			update(i, getid(a[i]), 1);
		}
		while (q--) {
			int l, r, k; scanf("%d%d%d", &l, &r, &k);
			int ret = query(root[l - 1], root[r], 1, n, k);
			printf("%d\n", ret);
		}
	}
	return 0;
}

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

const int maxn = 1e5 + 10;
const int maxm = maxn * 30;

struct Node {
	int lc, rc, sumv;
};

Node node[maxm];
int n, q, cnt, root[maxn];
int num[maxn], a[maxn], ncnt;

void init() {
	cnt = 1; root[0] = 0; ncnt = 0;
}

void build(int rt, int l, int r) {
	node[rt].sumv = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	node[rt].lc = cnt++; node[rt].rc = cnt++;
	build(node[rt].lc, l, mid);
	build(node[rt].rc, mid + 1, r);
}

void update(int rt, int prt, int l, int r, int pos, int val) {
	if(l == r) return;
	int newid = cnt++, mid = (l + r) >> 1;
	if(pos <= mid) {
		node[rt].lc = newid;
		node[newid].sumv = node[node[prt].lc].sumv + val;
		node[rt].rc = node[prt].rc;
		update(node[rt].lc, node[prt].lc, l, mid, pos, val);
	}
	else {
		node[rt].rc = newid;
		node[newid].sumv = node[node[prt].rc].sumv + val;
		node[rt].lc = node[prt].lc;
		update(node[rt].rc, node[prt].rc, mid + 1, r, pos, val);
	}
}

void update(int rid, int pos, int val) {
	root[rid] = cnt++;
	node[root[rid]].sumv = node[root[rid - 1]].sumv + val;
	update(root[rid], root[rid - 1], 1, n, pos, val);
}

int query(int lrt, int rrt, int l, int r, int k) {
	int mid = (l + r) >> 1, llc = node[lrt].lc, rlc = node[rrt].lc;
	if(l == r) return l;
	int lsum =  node[rlc].sumv - node[llc].sumv;
	if(lsum >= k) return query(llc, rlc, l, mid, k);
	else return query(node[lrt].rc, node[rrt].rc, mid + 1, r, k - lsum);
}

int getid(int val) {
	return lower_bound(num, num + ncnt, val) - num + 1;
}

int main() {
	while(scanf("%d%d", &n, &q) != EOF) {
		init();
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			num[ncnt++] = a[i];
		}
		sort(num, num + ncnt);
		ncnt = unique(num, num + ncnt) - num;
		build(0, 1, n);
		for(int i = 1; i <= n; i++) {
			int nowval = getid(a[i]);
			update(i, nowval, 1);
		}
		while(q--) {
			int l, r, k; scanf("%d%d%d", &l, &r, &k);
			int ret = query(root[l - 1], root[r], 1, n, k);
			printf("%d\n", num[ret - 1]);
		}
	}
	return 0;
}

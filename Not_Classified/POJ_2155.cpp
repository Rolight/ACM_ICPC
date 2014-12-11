#include <cstdio>
#include <cstring>
#include <algorithm>

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

using namespace std;

typedef char uint8;

const int maxn = 1e3 + 10;

int T, n, q;

struct SegmentTree {
	uint8 Lazy[maxn << 2];
	void Build(int rt, int l, int r) {
		Lazy[rt] = 0;
		if(l == r) return;
		int mid = (l + r) >> 1;
		Build(lson); Build(rson);
	}

	void PushDown(int rt) {
		if(Lazy[rt] == 0) return;
		int lc = rt << 1, rc = rt << 1 | 1;
		Lazy[lc] ^= 1; Lazy[rc] ^= 1;
		Lazy[rt] = 0;
	}

	void Update(int rt, int l, int r, int ql, int qr) {
		if(ql <= l && qr >= r) {
			Lazy[rt] ^= 1;
		}
		else {
			int mid = (l + r) >> 1;
			PushDown(rt);
			if(ql <= mid) Update(lson, ql, qr);
			if(qr > mid) Update(rson, ql, qr);
		}
	}

	uint8 Query(int rt, int l, int r, int pos) {
		if(l == r) return Lazy[rt];
		int mid = (l + r) >> 1;
		PushDown(rt);
		if(pos <= mid) return Query(lson, pos);
		else return Query(rson, pos);
	}
};

SegmentTree tree[maxn << 2];

void Build2D(int rt, int l, int r) {
	tree[rt].Build(1, 1, n);
	if(l == r) return;
	int mid = (l + r) >> 1;
	Build2D(lson); Build2D(rson);
}


void Update2D(int rt, int l, int r, int qx_l, int qx_r, int qy_l, int qy_r) {
	if(qx_l <= l && qx_r >= r) {
		tree[rt].Update(1, 1, n, qy_l, qy_r);
	}
	else {
		int mid = (l + r) >> 1;
		if(qx_l <= mid) Update2D(lson, qx_l, qx_r, qy_l, qy_r);
		if(qx_r > mid) Update2D(rson, qx_l, qx_r, qy_l, qy_r);
	}
}

void PushDown2D(int tid, int py) {
	int rt = 1, l = 1, r = n, mid;
	while(true) {
		mid = (l + r) >> 1;
		if(tree[tid].Lazy[rt]) {
			tree[tid << 1].Lazy[rt] ^= 1;
			tree[tid << 1 | 1].Lazy[rt] ^= 1;
			tree[tid].Lazy[rt] = 0;
		}
		if(l == r) break;
		if(py <= mid) {
			rt = rt << 1; r = mid;
		}
		else {
			rt = rt << 1 | 1; l = mid + 1;
		}
	}
}

uint8 Query2D(int px, int py) {
	int tid = 1, l = 1, r = n, mid;
	while(true) {
		if(l == r) return tree[tid].Query(1, 1, n, py);
		PushDown2D(tid, py);
		mid = (l + r) >> 1;
		if(px <= mid) {
			tid = tid << 1; r = mid;
		}
		else {
			tid = tid << 1 | 1; l = mid + 1;
		}
	}
}

int main() {
	//freopen("/tmp/in.txt", "r", stdin);
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		if(kase > 1) puts("");
		scanf("%d%d", &n, &q);
		Build2D(1, 1, n);
		char cmd;
		int x1, y1, x2, y2;
		while(q--) {
			scanf(" %c", &cmd);
			if(cmd == 'C') {
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				Update2D(1, 1, n, x1, x2, y1, y2);
			}
			else {
				scanf("%d%d", &x1, &y1);
				int ret = (int)Query2D(x1, y1);
				printf("%d\n", ret);
			}
		}
	}
	return 0;
}

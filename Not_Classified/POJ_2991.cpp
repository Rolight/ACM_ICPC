#include <cstdio>
#include <cmath>

#define lson rt<<1,l,mid
#define rson rt<<1|1,mid + 1,r

const int maxn = 1e4 + 5;
const double PI = acos(-1.0f);
const double eps = 1e-8;

struct Node {
	double x, y;
	int lazy, degree;
};

void Rotate(Node &node, int degree) {
	double rad = (double)degree / 180 * PI;
	double x = node.x, y = node.y;
	node.x = x * cos(rad) - y * sin(rad);
	node.y = x * sin(rad) + y * cos(rad);
	node.degree = (node.degree + degree) % 360;
}

Node node[maxn << 2], val[maxn];

void pushup(int rt, int l, int r) {
	int lc = rt << 1, rc = rt << 1 | 1;
	node[rt].x = node[lc].x + node[rc].x;
	node[rt].y = node[lc].y + node[rc].y;
}

void pushdown(int rt, int l, int r) {
	if (node[rt].lazy == 0) return;
	int lc = rt << 1, rc = rt << 1 | 1;
	node[lc].lazy += node[rt].lazy;
	node[rc].lazy += node[rt].lazy;
	Rotate(node[lc], node[rt].lazy);
	Rotate(node[rc], node[rt].lazy);
	node[rt].lazy = 0;
}

void build(int rt, int l, int r) {
	int mid = (l + r) >> 1;
	node[rt].lazy = 0;
	node[rt].degree = 0;
	if (l == r) {
		node[rt].x = val[l].x;
		node[rt].y = val[l].y;
	}
	else {
		build(lson); build(rson);
		pushup(rt, l, r);
	}
}

void update(int rt, int l, int r, int ql, int qr, int Val) {
	if (ql <= l && qr >= r) {
		node[rt].lazy += Val;
		Rotate(node[rt], Val);
	}
	else {
		int mid = (l + r) >> 1;
		pushdown(rt, l, r);
		if (ql <= mid) update(lson, ql, qr, Val);
		if (qr > mid) update(rson, ql, qr, Val);
		pushup(rt, l, r);
	}
}

int query(int rt, int l, int r, int pos) {
	if (l == r) return node[rt].degree;
	int mid = (l + r) >> 1;
	pushdown(rt, l, r);
	if (pos <= mid) return query(lson, pos);
	else return query(rson, pos);
}

int N, M;

int main() {
	bool first = true;
	while (scanf("%d%d", &N, &M) != EOF) {
		if (first) first = false;
		else putchar('\n');
		for (int i = 1; i <= N; i++) {
			val[i].x = 0;
			scanf("%lf", &val[i].y);
		}
		build(1, 1, N);
		for (int i = 1; i <= M; i++) {
			int pos, a; scanf("%d%d", &pos, &a); pos++;
			int deg1 = query(1, 1, N, pos - 1), 
				deg2 = query(1, 1, N, pos);
			int degree = deg1 + a + 180  - deg2;
			update(1, 1, N, pos, N, degree);
			printf("%.2lf %.2lf\n", node[1].x + eps, node[1].y + eps);
		}
	}
	return 0;
}

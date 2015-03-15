#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

const int maxn = 1e6;

int ch[maxn][2], size[maxn], root, rev[maxn], fa[maxn], sz;
int n, arr[maxn], aid[maxn];

void pushdown(int x) {
	if (rev[x] == 0) return;
	for (int i = 0; i <= 1; i++) if (ch[x][i]) {
		int u = ch[x][i];
		rev[u] ^= 1;
		swap(ch[u][0], ch[u][1]);
	}
	rev[x] = 0;
}

void pushup(int x) {
	size[x] = 1;
	for (int i = 0; i < 2; i++) if (ch[x][i]) {
		size[x] += size[ch[x][i]];
	}
}

void debug(int root) {
	int lc = ch[root][0], rc = ch[root][1];
	printf("当前节点：%d, lch: %d, rch %d, fa is %d\n",
		root, lc, rc, fa[root]);
	pushdown(root);
	if (lc) debug(lc);
	if (rc) debug(rc);
	pushup(root);
}


void rotate(int x, int d) {
	int y = fa[x];
	pushdown(y);
	pushdown(x);
	fa[ch[x][d]] = y;
	ch[y][d ^ 1] = ch[x][d];
	if (fa[y]) ch[fa[y]][ch[fa[y]][1] == y] = x;
	fa[x] = fa[y];
	ch[x][d] = y;
	fa[y] = x;
	pushup(x);
	pushup(y);
}

void splay(int x, int goal) {
	pushdown(x);
	while (fa[x] != goal) {
		int y = fa[x], d = (x == ch[y][1]);
		if (fa[y] == goal) rotate(x, d ^ 1);
		else {
			int z = fa[y], d1 = (y == ch[z][1]);
			if (d == d1) {
				rotate(y, d ^ 1); 
				rotate(x, d ^ 1); 
			}
			else {
				rotate(x, d ^ 1); rotate(x, d1 ^ 1);
			}
		}
	}
	pushup(x);
	if (goal == 0) root = x;
}

int newNode(int &r, int father, int v) {
	r = v;
	fa[r] = father;
	ch[r][0] = ch[r][1] = 0;
	size[r] = 1;
	rev[r] = 0;
	return r;
}

bool cmp(int a, int b) {
	return arr[a] < arr[b];
}

void build(int l, int r, int &rt, int father) {
	int mid = l + r >> 1;
	newNode(rt, father, mid);
	if (l == r) return;
	if (l < mid) build(l, mid - 1, ch[rt][0], rt);
	if (r > mid) build(mid + 1, r, ch[rt][1], rt);
	pushup(rt);
}

int findVal(int x, int d) {
	pushdown(x);
	while (ch[x][d]) {
		x = ch[x][d];
		pushdown(x);
	}
	return x;
}

void remove_root(int x) {
	pushdown(x);
	int lc = ch[x][0], rc = ch[x][1];
	if (lc) {
		int u = findVal(lc, 1);
		splay(u, x);
		fa[u] = 0;
		ch[u][1] = ch[x][1];
		fa[ch[x][1]] = u;
		root = u;
		pushup(u);
	}
	else if(rc) {
		fa[rc] = 0;
		root = rc;
		pushup(root);
	}
	else root = 0;
}

int main() {
	while (scanf("%d", &n), n != 0) {
		sz = root = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		for (int i = 1; i <= n; i++) aid[i] = i;
		stable_sort(aid + 1, aid + 1 + n, cmp);
		build(1, n, root, 0);
		for (int i = 1; i <= n; i++) {
			splay(aid[i], 0);
			int tlc = ch[root][0];
			if (i > 1) putchar(' ');
			printf("%d", size[tlc] + i);
			rev[tlc] ^= 1;
			swap(ch[tlc][0], ch[tlc][1]);
			remove_root(root);
		}
		puts("");
	}
	return 0;
}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>

using namespace std;

const int maxn = 1e6 + 10;
typedef long long LL;
int ch[maxn][2], lazy[maxn], fa[maxn], chcnt, root, key[maxn];
int N, Q, arr[maxn];
LL sum[maxn], size[maxn], val[maxn];

void pushdown(int x) {
	if (lazy[x] == 0) return;
	for (int i = 0; i <= 1; i++) if (ch[x][i]) {
		int u = ch[x][i];
		val[u] += lazy[x]; 
		sum[u] += size[u] * lazy[x];
		lazy[u] += lazy[x];
	}
	lazy[x] = 0;
}

void pushup(int x) {
	sum[x] = val[x]; size[x] = 1;
	for (int i = 0; i <= 1; i++) if (ch[x][i]) {
		int u = ch[x][i];
		sum[x] += sum[u]; 
		size[x] += size[u];
	}
}

void rotate(int x, int d) {
	int y = fa[x];
	pushdown(y);
	pushdown(x);
	fa[ch[x][d]] = y;
	ch[y][d ^ 1] = ch[x][d];
	if (fa[y]) ch[fa[y]][y == ch[fa[y]][1]] = x;
	fa[x] = fa[y]; 
	fa[y] = x;
	ch[x][d] = y;
	pushup(x); pushup(y);
}

void splay(int x, int goal) {
	pushdown(x);
	while (fa[x] != goal) {
		int y = fa[x], d = (x == ch[y][1]);
		if (fa[y] == goal) rotate(x, d ^ 1);
		else {
			int z = fa[y], d1 = (y == ch[z][1]);
			if (d == d1) {
				rotate(y, d ^ 1); rotate(x, d ^ 1);
			}
			else {
				rotate(x, d ^ 1); rotate(x, d1 ^ 1);
			}
		}
	}
	pushup(x);
	if (goal == 0) root = x;
}

int access(int v) {
	int u = root;
	while (u != 0 && key[u] != v) {
		pushdown(u);
		u = ch[u][v > key[u]];
	}
	return u;
}

int accessSeg(int l, int r) {
	int t = access(l - 1), t1 = access(r + 1);
	splay(t, 0); 
	splay(t1, root);
	return ch[ch[root][1]][0];
}

void update(int l, int r, int addv) {
	int u = accessSeg(l, r);
	lazy[u] += addv; 
	val[u] += addv; 
	sum[u] += size[u] * addv;
}

LL query(int l, int r) {
	int u = accessSeg(l, r);
	return sum[u];
}

int newNode(int &r, int father, int v, int k) {
	r = ++chcnt; 
	key[r] = k;
	fa[r] = father;
	val[r] = sum[r] = v; 
	size[r] = 1;
	lazy[r] = 0; 
	ch[r][0] = ch[r][1] = 0;
	return r;
}

void build(int l, int r, int &rt, int father) {
	if (l > r) return;
	int mid = l + r >> 1;
	newNode(rt, father, arr[mid], mid);
	if (l == r) return;
	build(l, mid - 1, ch[rt][0], rt);
	build(mid + 1, r, ch[rt][1], rt);
	pushup(rt);
}


int main() {
	char cmd;
	int l, r, cp;
	while (scanf("%d%d", &N, &Q) != EOF) {
		chcnt = 0;
		arr[0] = arr[N + 1] = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
		}
		build(0, N + 1, root, 0);
		for (int i = 1; i <= Q; i++) {
			scanf(" %c%d%d", &cmd, &l, &r);
			if (cmd == 'C') {
				scanf("%d", &cp);
				update(l, r, cp);
			}
			else {
				printf("%I64d\n", query(l, r));
			}
		}
	}
	return 0;
}
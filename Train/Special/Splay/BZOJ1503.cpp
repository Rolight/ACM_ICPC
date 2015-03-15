#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>

using namespace std;

const int maxn = 1e6 + 10;

int ch[maxn][2], val[maxn], size[maxn], chcnt, fa[maxn], root;
char cmd[16];
int n, min_val, tmp, tval, lcnt;

void update(int x) {
	size[x] = 1;
	if (ch[x][0]) size[x] += size[ch[x][0]];
	if (ch[x][1]) size[x] += size[ch[x][1]];
}

void rotate(int x, int d) {
	int y = fa[x];
	fa[ch[x][d]] = y; ch[y][d ^ 1] = ch[x][d];
	if (fa[y]) ch[fa[y]][y == ch[fa[y]][1]] = x;
	fa[x] = fa[y]; fa[y] = x;
	ch[x][d] = y;
	update(x); update(y);
}

void splay(int x, int goal) {
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
	if (goal == 0) root = x;
}

int findkth(int x, int k) {
	if (k <= 0 || k > size[x] || x == 0) return -1;
	int rsize = (ch[x][1] == 0 ? 0 : size[ch[x][1]]);
	if (rsize >= k) return findkth(ch[x][1], k);
	else if (k == rsize + 1) return x;
	else return findkth(ch[x][0], k - 1 - rsize);
}

int newNode(int &r, int father, int v) {
	r = ++chcnt;
	ch[r][0] = ch[r][1] = 0;
	fa[r] = father; val[r] = v;
	size[r] = 1;
	return r;
}

int insert(int v) {
	int u = root;
	if (u == 0) {
		newNode(root, 0, v); return root;
	}
	while (ch[u][v > val[u]]) u = ch[u][v > val[u]];
	int r = newNode(ch[u][v > val[u]], u, v);
	update(u);
	splay(r, 0);
	return r;
}

void remove_tree(int x) {
	if (x == 0) return;
	if (x == root) root = 0;
	else {
		ch[fa[x]][x == ch[fa[x]][1]] = 0;
		x = fa[x]; fa[x] = 0;
		while (x) {
			update(x); x = fa[x];
		}
	}
}

void debug(int root) {
	int lc = ch[root][0], rc = ch[root][1];
	printf("当前节点：%d(val = %d), lch: %d(val = %d), rch %d(val = %d), fa is %d\n",
		root, val[root], lc, val[lc], rc, val[rc], fa[root]);
	if (lc) debug(lc);
	if (rc) debug(rc);
}

int main() {
	while (scanf("%d%d", &n, &min_val) != EOF) {
		chcnt = root = tmp = lcnt = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%s%d", cmd, &tval);
			if (cmd[0] == 'I') {
				if (tval < min_val) continue;
				insert(tval - tmp);
			}
			else if (cmd[0] == 'A') tmp += tval;
			else if (cmd[0] == 'S') {
				tmp -= tval;
				insert(min_val - tmp);
				lcnt += size[ch[root][0]];
				remove_tree(ch[root][0]);
				fa[ch[root][1]] = 0;
				root = ch[root][1];
			}
			else {
				int ret = findkth(root, tval);
				printf("%d\n", ret == -1 ? -1 : val[ret] + tmp);
			}
		}
		printf("%d\n", lcnt);
	}
	return 0;
}
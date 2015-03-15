#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 3e5 + 10;
int ch[maxn][2], fa[maxn], rsize[maxn], size[maxn], key[maxn], nstr[maxn], chcnt, root;
int n, q, vnum[maxn], vcnt, qval[maxn], tpos, pos[maxn], pid[maxn];
int node_size[maxn], node_str[maxn], node_cnt;
char cmd[maxn][16];

inline void pushup(int x) {
	size[x] = rsize[x];
	for (int i = 0; i < 2; i++) if (ch[x][i]) {
		size[x] += size[ch[x][i]];
	}
}

int getID(int v) {
	return lower_bound(vnum, vnum + vcnt, v) - vnum;
}

void build_node() {
	//缩点
	for (int i = 1; i < vcnt; i++) {
		int tmp = vnum[i] - vnum[i - 1] - 1;
		if (tmp) {
			node_size[++node_cnt] = tmp;
			node_str[node_cnt] = vnum[i - 1] + 1;
		}
		node_size[++node_cnt] = 1;
		node_str[node_cnt] = vnum[i];
		pid[i] = node_cnt;
	}
	if (vnum[vcnt - 1] < n) {
		node_size[++node_cnt] = n - vnum[vcnt - 1];
		node_str[node_cnt] = vnum[vcnt - 1] + 1;
	}
}

int newNode(int &r, int father, int v, int rz, int ns) {
	r = ++chcnt;
	ch[r][0] = ch[r][1] = 0;
	rsize[r] = rz;
	key[r] = v;
	fa[r] = father;
	nstr[r] = ns;
	return r;
}

void build_tree(int l, int r, int &rt, int father) {
	int mid = l + r >> 1;
	rt = pos[mid] = newNode(rt, father, mid, node_size[mid], node_str[mid]);
	if (l < mid) build_tree(l, mid - 1, ch[rt][0], rt);
	if (r > mid) build_tree(mid + 1, r, ch[rt][1], rt);
	pushup(rt);
}

inline void rotate(int x, int d) {
	int y = fa[x];
	ch[y][d ^ 1] = ch[x][d];
	fa[ch[x][d]] = y;
	if (fa[y]) ch[fa[y]][y == ch[fa[y]][1]] = x;
	fa[x] = fa[y];
	ch[x][d] = y;
	fa[y] = x;
	pushup(x);
	pushup(y);
}

inline void splay(int x, int goal) {
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

inline int findMax(int rt) {
	while (ch[rt][1]) rt = ch[rt][1];
	return rt;
}

inline void remove(int x) {
	splay(x, 0);
	int lc = ch[x][0], rc = ch[x][1];
	if (lc) {
		int u = findMax(lc);
		splay(u, x);
		fa[u] = 0;
		if(rc) fa[rc] = u;
		ch[u][1] = rc;
		root = u;
		pushup(u);
	}
	else if(rc) {
		fa[rc] = 0;
		root = rc;
		pushup(rc);
	}
	else root = 0;
}

inline int insert(int v, int rz, int ns) {
	int u = root;
	if (root == 0) {
		newNode(root, 0, v, rz, ns);
		return root;
	}
	while (ch[u][v > key[u]]) u = ch[u][v > key[u]];
	int r = newNode(ch[u][v > key[u]], u, v, rz, ns);
	splay(r, 0);
	return r;
}

inline void setTop(int x) {
	x = pid[getID(x)];
	remove(pos[x]);
	pos[x] = insert(--tpos, node_size[x], node_str[x]);
}

inline int query(int x) {
	x = pos[pid[getID(x)]];
	splay(x, 0);
	return size[ch[x][0]] + 1;
}

inline int findkth(int rt, int k) {
	int lsize = size[ch[rt][0]];
	if (lsize >= k) return findkth(ch[rt][0], k);
	else if (lsize + rsize[rt] >= k) return nstr[rt] + k - lsize - 1;
	else return findkth(ch[rt][1], k - lsize - rsize[rt]);
}

int main() {
	int T; scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++) {
		printf("Case %d:\n", kase);
		scanf("%d%d", &n, &q);
		//加入把要进行Top,和Query操作的值离散化
		vcnt = node_cnt = tpos = 0;
		vnum[vcnt++] = 0;
		chcnt = 0;
		for (int i = 1; i <= q; i++) {
			scanf("%s%d", cmd[i], &qval[i]);
			if (cmd[i][0] == 'T' || cmd[i][0] == 'Q') {
				vnum[vcnt++] = qval[i];
			}
		}
		sort(vnum, vnum + vcnt);
		vcnt = unique(vnum, vnum + vcnt) - vnum;
		build_node();
		build_tree(1, node_cnt, root, 0);
		for (int i = 1; i <= q; i++) {
			if (cmd[i][0] == 'T') setTop(qval[i]);
			else if (cmd[i][0] == 'R') printf("%d\n", findkth(root, qval[i]));
			else printf("%d\n", query(qval[i]));
		}
	}
	return 0;
}
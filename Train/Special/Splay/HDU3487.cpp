#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 4e5 + 10;
int fa[maxn], ch[maxn][2], val[maxn], size[maxn], chcnt, root;
int lazy[maxn], n, m;
char cmd[16];
vector<int> ans;

void pushup(int rt) {
	size[rt] = 1;
	if(ch[rt][0]) size[rt] += size[ch[rt][0]];
	if(ch[rt][1]) size[rt] += size[ch[rt][1]];
}

void pushdown(int rt) {
	if(lazy[rt] == 0) return;
	for(int i = 0; i <= 1; i++) if(ch[rt][i]) {
		int u = ch[rt][i];
		lazy[u] ^= 1;
		swap(ch[u][0], ch[u][1]);
	}
	lazy[rt] = 0;
}

void rotate(int x, int o) {
	int y = fa[x];
	pushdown(y);
	pushdown(x);
	ch[y][o ^ 1] = ch[x][o];
	fa[ch[x][o]] = y;
	if(fa[y]) ch[fa[y]][y == ch[fa[y]][1]] = x;
	fa[x] = fa[y];
	fa[y] = x;
	ch[x][o] = y;
	pushup(x);
	pushup(y);
}

void splay(int x, int goal) {
	pushdown(x);
	while(fa[x] != goal) {
		int y = fa[x], d = (x == ch[y][1]);
		if(fa[y] == goal) rotate(x, d ^ 1);
		else {
			int z = fa[y], d1 = (y == ch[z][1]);
			if(d == d1) {
				rotate(y, d ^ 1); rotate(x, d ^ 1);
			}
			else {
				rotate(x, d ^ 1); rotate(x, d1 ^ 1);
			}
		}
	}
	pushup(x);
	if(goal == 0) root = x;
}

void getans(int x) {
	pushdown(x);
	if(ch[x][0]) getans(ch[x][0]);
	if(val[x] <= n && val[x] > 0) {
		ans.push_back(val[x]);
	}
	if(ch[x][1]) getans(ch[x][1]);
}

int newnode(int &r, int father, int v) {
	r = ++ chcnt;
	val[r] = v;
	fa[r] = father;
	size[r] = 1;
	lazy[r] = 0;
	ch[r][0] = ch[r][1] = 0;
	return r;
}

void build_tree(int l, int r, int &rt, int father) {
	if(l > r) return;
	int mid = (l + r) >> 1;
	newnode(rt, father, mid);
	if(l == r) return;
	build_tree(l, mid - 1, ch[rt][0], rt);
	build_tree(mid + 1, r, ch[rt][1], rt);
	pushup(rt);
}

int access(int k) {
	int u = root;
	while(true) {
		pushdown(u);
		if(size[ch[u][0]] >= k) u = ch[u][0];
		else if(k == size[ch[u][0]] + 1) return u;
		else {
			k -= size[ch[u][0]] + 1;
			u = ch[u][1];
		}
	}
	return 0;
}

void flipseg(int l, int r) {
	int u;
	l = access(l - 1);
	r = access(r + 1);
	splay(l, 0);
	splay(r, root);
	u = ch[ch[root][1]][0];
	swap(ch[u][0], ch[u][1]);
	lazy[u] ^= 1;
}

void cutseg(int l, int r, int tar) {
	int u, tmp;
	l = access(l - 1);
	r = access(r + 1);
	splay(l, 0); 
	splay(r, root);
	u = ch[ch[root][1]][0];
	//删除区间
	ch[fa[u]][0] = 0;
	pushup(fa[u]);
	fa[u] = 0;
	//插入区间
	l = access(tar);
	r = access(tar + 1);
	splay(l, 0);
	splay(r, root);
	tmp = ch[root][1];
	fa[u] = tmp;
	ch[tmp][0] = u;
	pushup(tmp);
}


int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		int ql, qr, x;
		if(n == -1 || m == -1) break;
		chcnt = root = 0;
		build_tree(0, n + 1, root, 0);
		ans.clear();
		for(int i = 0; i < m; i++) {
			scanf("%s%d%d", cmd, &ql, &qr);
			if(cmd[0] == 'C') {
				scanf("%d", &x);
				cutseg(ql + 1, qr + 1, x + 1);
			}
			else flipseg(ql + 1, qr + 1);
		}
		getans(root);
		for(int i = 0; i < ans.size(); i++) {
			if(i) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}

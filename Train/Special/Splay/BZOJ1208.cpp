#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

const int maxn = 2e6 + 10;
const int mod = 1000000;
const int PET = 0;
const int HUMAN = 1;
const int EMPTY = -1;
const int INF = INT_MAX / 3;
int ch[maxn][2], fa[maxn], val[maxn], sz, root;

void rotate(int x, int d) {
	int y = fa[x];
	ch[y][d ^ 1] = ch[x][d];
	fa[ch[x][d]] = y;
	if (fa[y] != 0) {
		ch[fa[y]][y == ch[fa[y]][1]] = x;
	}
	ch[x][d] = y;
	fa[x] = fa[y];
	fa[y] = x;
}

int newNode(int &r, int father, int v) {
	r = ++sz;
	fa[r] = father; val[r] = v;
	ch[r][0] = ch[r][1] = 0;
	return r;
}

void splay(int x, int goal) {
	while (fa[x] != goal) {
		int y = fa[x], d = val[x] > val[y];
		if (fa[y] == goal) {
			rotate(x, d ^ 1);
			break;
		}
		int z = fa[y], d1 = val[y] > val[z];
		if (d == d1) {
			rotate(y, d1 ^ 1);
			rotate(x, d ^ 1);
		}
		else {
			rotate(x, d ^ 1);
			rotate(x, d1 ^ 1);
		}
	}
	if (goal == 0) {
		fa[x] = 0;
		root = x;
	}
}

void debug(int root) {
	int lc = ch[root][0], rc = ch[root][1];
	printf("当前节点：%d(val = %d), lch: %d(val = %d), rch %d(val = %d), fa is %d\n",
		root, val[root], lc, val[lc], rc, val[rc], fa[root]);
	if (lc) debug(lc);
	if (rc) debug(rc);
}

int insert(int v) {
	if (root == 0) {
		newNode(root, 0, v);
		return root;
	}
	int u = root;
	while (ch[u][v > val[u]] != 0) 
		u = ch[u][v > val[u]];
	int r = newNode(ch[u][v > val[u]], u, v);
	splay(r, 0);
	return r;
}


//找后继
int findNext(int x) {
	//如果x节点有右子树
	if (ch[x][1] != 0) {
		//找到右子树中最小的节点
		int u = ch[x][1];
		while (ch[u][0] != 0) u = ch[u][0];
		return u;
	}
	//往上寻找
	int u = x;
	while (fa[u] != 0 && u != ch[fa[u]][0]) u = fa[u];
	return fa[u];
}

//用二叉搜索树删除节点的方式来删除节点
void remove(int x) {
	if (ch[x][0] == 0 && ch[x][1] == 0) {
		if (fa[x] == 0) root = 0;
		else ch[fa[x]][x == ch[fa[x]][1]] = 0;
	}
	else if (ch[x][0] == 0) {
		if (fa[x] == 0) {
			root = ch[x][1];
			fa[ch[x][1]] = 0;
		}
		else ch[fa[x]][x == ch[fa[x]][1]] = ch[x][1];
		fa[ch[x][1]] = fa[x];
	}
	else if (ch[x][1] == 0) {
		if (fa[x] == 0) {
			root = ch[x][0];
			fa[ch[x][0]] = 0;
		}
		else ch[fa[x]][x == ch[fa[x]][1]] = ch[x][0];
		fa[ch[x][0]] = fa[x];
	}
	else {
		int r = findNext(x);
		swap(val[r], val[x]);
		remove(r);
	}
}

//先splay到根然后删除
void remove_root() {
	int u = root;
	if (ch[u][0] == 0) {
		root = ch[u][1];
		fa[ch[u][1]] = 0;
	}
	else {
		//找到左子树中最大的值
		int x = ch[u][0];
		while (ch[x][1] != 0) x = ch[x][1];
		//splay到根的做子树
		splay(x, root);
		//debug(root);
		//此时x必然没有右子树，直接作为根
		ch[x][1] = ch[u][1];
		if (ch[u][1]) fa[ch[u][1]] = x;
		root = x; fa[x] = 0;
	}
	//debug(root);
}

int findValMinNext(int v) {
	int u = root;
	while (ch[u][v > val[u]] != 0) u = ch[u][v > val[u]];
	if (v >= val[u]) return u;
	while (fa[u] != 0 && val[fa[u]] > val[u]) u = fa[u];
	return fa[u];
}

int findValMaxNext(int v) {
	int u = root;
	while (ch[u][v > val[u]] != 0) u = ch[u][v > val[u]];
	if (v < val[u]) return u;
	while (fa[u] != 0 && val[fa[u]] <= val[u]) u = fa[u];
	return fa[u];
}

int main() {
	//freopen("INPUT.002", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, state, cmd, st, ans;
	while (scanf("%d", &n) != EOF) {
		sz = root = ans = 0;
		state = EMPTY;
		for (int i = 1; i <= n; i++) {
			//debug(root);
			scanf("%d%d", &cmd, &st);
			if (state == EMPTY) {
				state = cmd; insert(st);
			}
			else if (state == cmd) insert(st);
			else {
				val[0] = INF;
				int g1 = findValMinNext(st), g2 = findValMaxNext(st);
				//run_test();
				//printf("g1 is %d, g2 is %d\n", val[g1], val[g2]);
				int v1 = abs(st - val[g1]), v2 = abs(st - val[g2]);
				if (v1 <= v2) {
					ans = (ans + v1) % mod;
					splay(g1, 0);  
					remove(root);
					//debug(root);
					//remove_root();
				}
				else {
					ans = (ans + v2) % mod;
					splay(g2, 0); 
					//debug(root);
					remove(root);
					//remove_root();
				}
				if (root == 0) state = EMPTY;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

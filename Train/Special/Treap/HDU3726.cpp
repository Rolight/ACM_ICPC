#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

const int maxn = 2e4 + 10;
const int maxm = 6e4 + 10;
const int maxk = 6e5 + 10;

//treap
struct Node {
	Node *ch[2];
	int rkey, val, size;
	Node(int v = 0): val(v), size(1) {
		ch[0] = ch[1] = NULL;
		rkey = rand();
	}
	int cmp(int x) {
		if(val == x) return -1;
		if(val < x) return 1;
		else return 0;
	}
	void maintain() {
		size = 1;
		if(ch[0] != NULL) {
			size += ch[0]->size;
		}
		if(ch[1] != NULL) {
			size += ch[1]->size;
		}
	}
};

//0表示左旋，1表示右旋
void rotate(Node *&o, int d) {
	Node *k = o->ch[d ^ 1];
	o->ch[d ^ 1] = k->ch[d];
	k->ch[d] = o;
	o->maintain();
	k->maintain();
	o = k;
}

void insert(Node *&o, int x) {
	if(o == NULL) {
		o = new Node(x);
	}
	else {
		int d = (x < o->val ? 0 : 1);
		insert(o->ch[d], x);
		if(o->ch[d]->rkey > o->rkey) {
			rotate(o, d ^ 1);
		}
	}
	o->maintain();
}

void remove(Node *&o, int x) {
	int d = o->cmp(x);
	Node *u = o;
	if(d == -1) {
		if(o->ch[0] == NULL) {
			o = o->ch[1];
			delete u;
		}
		else if(o->ch[1] == NULL) {
			o = o->ch[0];
			delete u;
		}
		else {
			int d2 = (o->ch[0]->rkey > o->ch[1]->rkey);
			rotate(o, d2);
			remove(o->ch[d2], x);
		}
	}
	else {
		remove(o->ch[d], x);
	}
	if(o != NULL) {
		o->maintain();
	}
}

void mergetree(Node *&src, Node *&dest) {
	if(src->ch[0] != NULL) {
		mergetree(src->ch[0], dest);
	}
	if(src->ch[1] != NULL) {
		mergetree(src->ch[1], dest);
	}
	insert(dest, src->val);
	delete(src);
	src = NULL;
}

void remove_tree(Node *&x) {
	if(x->ch[0] != NULL) {
		remove_tree(x->ch[0]);
	}
	if(x->ch[1] != NULL) {
		remove_tree(x->ch[1]);
	}
	delete(x); x = NULL;
}

int findkth(Node *root, int k) {
	if(root == NULL || k > root->size || k <= 0) {
		return 0;
	}
	int rsize = (root->ch[1] == NULL ? 0 : root->ch[1]->size);
	if(k == rsize + 1) return root->val;
	if(k <= rsize) return findkth(root->ch[1], k);
	return findkth(root->ch[0], k - 1 - rsize);
}

struct Edge {
	int u, v;
	Edge(int u = 0, int v = 0): u(u), v(v) {}
};

struct Operation {
	char cmd;
	int x, k;
	Operation(char cmd = 0, int x = 0, int k = 0):
		cmd(cmd), x(x), k(k) {}
};

Edge edge[maxm];
Operation opr[maxk];
int n, m, degree[maxn], opcnt;
bool isdel[maxm];
int fa[maxn];
Node *root[maxn];

int findset(int x) {
	return x == fa[x] ? x : fa[x] = findset(fa[x]);
}

void init() {
	opcnt = 0;
	memset(isdel, 0, sizeof(isdel));
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
		if(root[i] != NULL) {
			remove_tree(root[i]);
		}
	}
}

void add_edge(int eid) {
	int u = edge[eid].u, v = edge[eid].v;
	int x = findset(u), y = findset(v);
	if(x == y) return;
	//将节点数小的树合并到节点大的树上
	if(root[x]->size < root[y]->size) {
		fa[x] = y;
		mergetree(root[x], root[y]);
	}
	else {
		fa[y] = x;
		mergetree(root[y], root[x]);
	}
}

void change_degree(int x, int k) {
	int y = findset(x);
	remove(root[y], degree[x]);
	insert(root[y], k);
	degree[x] = k;
}

int query(int x, int k) {
	return findkth(root[findset(x)], k);
}

void input() {
	for(int i = 1; i <= n; i++) {
		scanf("%d", &degree[i]);
	}
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		edge[i] = Edge(u, v);
	}
	char cmd;
	int x, k;
	while(scanf(" %c", &cmd), cmd != 'E') {
		if(cmd == 'D') {
			scanf("%d", &x);
			isdel[x] = true;
		}
		else if(cmd == 'C') {
			scanf("%d%d", &x, &k);
			int tmp = degree[x];
			degree[x] = k;
			k = tmp;
		}
		else {
			scanf("%d%d", &x, &k);
		}
		opcnt++;
		opr[opcnt] = Operation(cmd, x, k);
	}
}

void build_graph() {
	for(int i = 1; i <= n; i++) {
		root[i] = new Node(degree[i]);
	}
	for(int i = 1; i <= m; i++) if(!isdel[i]) {
		add_edge(i);
	}
}

int main() {
	int kase = 1;
	while(scanf("%d%d", &n, &m), n != 0 && m != 0) {
		init();
		input();
		build_graph();
		double ans = 0;
		int qcnt = 0;
		for(int i = opcnt; i > 0; i--) {
			if(opr[i].cmd == 'D') {
				add_edge(opr[i].x);
			}
			else if(opr[i].cmd == 'C') {
				change_degree(opr[i].x, opr[i].k);
			}
			else {
				ans += query(opr[i].x, opr[i].k);
				qcnt++;
			}
		}
		printf("Case %d: %.6f\n", kase++, ans / qcnt);
	}
	return 0;
}

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

struct Node {
	Node *ch[2];
	int rkey, size, val, cnt;
	Node(int val) : val(val) {
		ch[0] = ch[1] = NULL;
		rkey = rand();
		size = cnt = 1;
	}
	void maintain() {
		size = cnt;
		if (ch[0] != NULL) size += ch[0]->size;
		if (ch[1] != NULL) size += ch[1]->size;
	}
};

struct Treap {

	Node *root;

	Treap() {
		root = NULL;
	}

	void rotate(Node *&o, int d) {
		Node *k = o->ch[d ^ 1];
		o->ch[d ^ 1] = k->ch[d];
		k->ch[d] = o;
		k->maintain(); o->maintain();
		o = k;
	}

	void remove_tree(Node *&o) {
		if (o == NULL) return;
		if (o->ch[0] != NULL) remove_tree(o->ch[0]);
		if (o->ch[1] != NULL) remove_tree(o->ch[1]);
		delete o;
		o = NULL;
	}

	void insert(Node *&o, int x) {
		if (o == NULL) o = new Node(x);
		else if (o->val == x) o->cnt++;
		else {
			int d = x > o->val;
			insert(o->ch[d], x);
			if (o->ch[d]->rkey > o->rkey) rotate(o, d ^ 1);
		}
		o->maintain();
	}

	int getsize(Node *o) {
		if (o == NULL) return 0;
		return o->size;
	}

	int query(Node *o, int x) {
		if (o == NULL) return 0;
		if (o->val == x) {
			return getsize(o->ch[0]) + o->cnt - 1;
		}
		if (x > o->val) return getsize(o->ch[0]) + o->cnt + query(o->ch[1], x);
		else return query(o->ch[0], x);
	}

	void clear() {
		remove_tree(root);
	}

	void insert(int x) {
		insert(root, x);
	}

	int query(int x) {
		return query(root, x);
	}
};

const int maxn = 2e4 + 10;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	bool operator < (const Point &p) const {
		if (y == p.y) return x < p.x;
		return y < p.y;
	}
};

int levcnt[maxn], n;
Point p[maxn];
Treap tree;

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			int x, y; scanf("%d%d", &x, &y);
			p[i] = Point(x, y);
		}
		sort(p + 1, p + 1 + n);
		memset(levcnt, 0, sizeof(levcnt));
		tree.clear();
		for (int i = 1; i <= n; i++) {
			tree.insert(p[i].x);
			int ret = tree.query(p[i].x);
			levcnt[ret]++;
		}
		for (int i = 0; i < n; i++) {
			printf("%d\n", levcnt[i]);
		}
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
	Node *ch[2];
	int rkey, size, val;
	Node(int val) : val(val), size(1) {
		rkey = rand();
		ch[0] = ch[1] = NULL;
	}
	void maintain() {
		size = 1;
		if (ch[0] != NULL) size += ch[0]->size;
		if (ch[1] != NULL) size += ch[1]->size;
	}
};

void rotate(Node *&x, int d) {
	Node *k = x->ch[d ^ 1];
	x->ch[d ^ 1] = k->ch[d];
	k->ch[d] = x;
	x->maintain();
	k->maintain();
	x = k;
}

void insert(Node *&o, int x) {
	if (o == NULL) o = new Node(x);
	else {
		int d = x > o->val;
		insert(o->ch[d], x);
		if (o->ch[d]->rkey > o->rkey) {
			rotate(o, d ^ 1);
		}
	}
	o->maintain();
}

void remove(Node *&o, int x) {
	if (o->val == x) {
		if (o->ch[0] == NULL || o->ch[1] == NULL) {
			Node *k = o;
			if (o->ch[0] == NULL) o = o->ch[1];
			else o = o->ch[0];
			delete k;
		}
		else {
			int d = o->ch[0]->rkey > o->ch[1]->rkey;
			rotate(o, d);
			remove(o->ch[d], x);
		}
	}
	else {
		int d = x > o->val;
		remove(o->ch[d], x);
	}
}

int findkth(Node *o, int k) {
	if (o == NULL || k > o->size || k <= 0) return 0;
	int lsize = o->ch[0] == NULL ? 0 : o->ch[0]->size;
	if (k <= lsize) return findkth(o->ch[0], k);
	else if (k == lsize + 1) return o->val;
	else return findkth(o->ch[1], k - lsize - 1);
}

void remove_tree(Node *&o) {
	if (o == NULL) return;
	if (o->ch[0] != NULL) remove_tree(o->ch[0]);
	if (o->ch[1] != NULL) remove_tree(o->ch[1]);
	delete(o); o = NULL;
}

struct Seg {
	int l, r, k, id;
	Seg(int l, int r, int k, int id) :
		l(l), r(r), k(k), id(id) {}
	Seg() {}
	bool operator < (const Seg &x) const {
		if (r == x.r) return l < x.l;
		return r < x.r;
	}
};

const int maxn = 1e6 + 10;

Seg query[maxn];
Node *treap;
int ans[maxn], n, m, a[maxn];

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= m; i++) {
			int l, r, k; scanf("%d%d%d", &l, &r, &k);
			query[i] = Seg(l, r, k, i);
		}
		sort(query + 1, query + 1 + m);
		int nowl = 1, nowr = 1;
		remove_tree(treap);
		for (int i = 1; i <= m; i++) {
			while (nowr <= query[i].r) {
				insert(treap, a[nowr++]);
			}
			while (nowl < query[i].l) {
				remove(treap, a[nowl++]);
			}
			ans[query[i].id] = findkth(treap, query[i].k);
		}
		for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	}
	return 0;
}
#include <cstdio>
#include <climits>
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

const int maxn = 2e5 + 10;

struct Node {
	Node *ch[2];
	int rkey, val, size, id;
	Node(int val, int id): val(val), id(id) {
		ch[0] = ch[1] = NULL;
		rkey = rand();
		size = 1;
	}
	void maintain() {
		size = 1;
		if(ch[1] != NULL) size += ch[1]->size;
		if(ch[0] != NULL) size += ch[0]->size;
	}
};

void rotate(Node *&o, int d) {
	Node *k = o->ch[d ^ 1];
	o->ch[d ^ 1] = k->ch[d];
	k->ch[d] = o;
	o->maintain(); k->maintain();
	o = k;
}

void insert(Node *&o, int x, int id) {
	if(o == NULL) o = new Node(x, id);
	else {
		int d = x > o->val;
		insert(o->ch[d], x, id);
		if(o->ch[d]->rkey > o->rkey) 
			rotate(o, d ^ 1);
	}
	o->maintain();
}

void remove_tree(Node *&o) {
	if(o == NULL) return;
	if(o->ch[0] != NULL) remove_tree(o->ch[0]);
	if(o->ch[1] != NULL) remove_tree(o->ch[1]);
	delete(o); o = NULL;
}

Node* query(Node *o, int x, int dx) {
	//dx = 0
	Node *pre = NULL;
	while(o != NULL && o->val != x) {
		int d = x > o->val;
		if(d == dx ^ 1) pre = o;
		o = o->ch[d];
	}
	o = o->ch[dx];
	if(o == NULL) return pre;
	else {
		while(o->ch[dx ^ 1] != NULL) 
			o = o->ch[dx ^ 1];
		return o;
	}
}

int calc(Node *r, int k) {
	if(r == NULL) return INT_MAX;
	return abs(r->val - k);
}

Node *root;
int n;

int main() {
	while(scanf("%d", &n), n != 0) {
		remove_tree(root);
		insert(root, 1e9, 1);
		for(int i = 1; i <= n; i++) {
			int id, k, ans; 
			scanf("%d%d", &id, &k);
			insert(root, k, id);
			Node *r0 = query(root, k, 0), 
				*r1 = query(root, k, 1);
			int d0 = calc(r0, k), d1 = calc(r1, k);
			if(d0 > d1) ans = r1->id;
			else ans = r0->id;
			printf("%d %d\n", id, ans);
		}
	}
	return 0;
}

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

//treap
struct Node {
	Node *ch[2];
	int rkey, val, size;
	void maintain() {
		size = 1;
		if(ch[0] != NULL) size += ch[0]->size;
		if(ch[1] != NULL) size += ch[1]->size;
	}
};

void rotate(Node *&o, int d) {
	Node *k = o->ch[d ^ 1];
	o->ch[d ^ 1] = k->ch[d];
	k->ch[d] = o;
	o->maintain(); k->maintain();
	o = k;
}

void insert(Node *&o, int x) {
	if(o == NULL) {
		o = new Node();
		o->ch[0] = o->ch[1] = NULL;
		o->rkey = rand();
		o->val = x;
	}
	else {
		int d = (x > o->val);
		insert(o->ch[d], x);
		if(o->ch[d]->rkey > o->rkey) rotate(o, d ^ 1);
	}
	o->maintain();
}

int findkth(Node *o, int k) {
	if(o == NULL || k > o->size || k <= 0) return 0;
	int lsize = o->ch[0] == NULL ? 0 : o->ch[0]->size;
	if(lsize + 1 == k) return o->val;
	if(k <= lsize) return findkth(o->ch[0], k);
	return findkth(o->ch[1], k - 1 - lsize);
}

void remove_tree(Node *&o) {
	if(o == NULL) return;
	for(int i = 0; i < 1; i++) if(o->ch[i] != NULL) {
		remove_tree(o->ch[i]);
	}
	delete o; o = NULL;
}

const int maxn = 5e4 + 10;
int n, m, a[maxn];
Node *root;

int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		remove_tree(root);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int nowi = 0, nsz;
		for(int i = 1, j = 0; i <= m; i++) {
			scanf("%d", &nsz);
			while(j < nsz)  {
				j++; insert(root, a[j]);
			}
			nowi++;
			printf("%d\n", findkth(root, nowi));
		}
	}
	return 0;
}

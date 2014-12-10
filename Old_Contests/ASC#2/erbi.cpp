#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

typedef long long LL;

const int maxn = 5e5 + 10;
int n, p[maxn], len[maxn];
int cnt;

struct TreeNode {
	int nid, lc, rc;
};

struct Node {
	int tid;
	LL W;
	Node(int tid = 0, LL W = 0):
		tid(tid), W(W) {}
	bool operator < (const Node &x) const {
		return W > x.W;
	}
};

TreeNode tnode[maxn << 2];

void dfs(int now, int nowdep) {
	if(tnode[now].nid != -1) {
		len[tnode[now].nid] = nowdep - 1;
		return;
	}
	dfs(tnode[now].lc, nowdep + 1);
	dfs(tnode[now].rc, nowdep + 1);
}

void gao() {
	if(n == 1) {
		printf("%d\n", p[1]);
		return;
	}
	priority_queue<Node> q;
	for(int i = 1; i <= n; i++) {
		TreeNode &now = tnode[cnt++];
		now.nid = i;
		q.push(Node(cnt - 1, p[i]));
	}
	while(q.size() > 1) {
		Node max1, max2;
		max1 = q.top(); q.pop();
		max2 = q.top(); q.pop();
		TreeNode &newnode = tnode[cnt++];
		newnode.lc = max1.tid;
		newnode.rc = max2.tid;
		newnode.nid = -1;
		q.push(Node(cnt - 1, max1.W + max2.W));
	}
	Node root = q.top(); q.pop();
	dfs(root.tid, 1);
	LL ans = 0;
	for(int i = 1; i <= n; i++) ans += (LL)len[i] * p[i];
	cout << ans << endl;
}

int main() {
	freopen("huffman.in", "r", stdin);
//	freopen("huffman.out", "w", stdout);
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
		cnt = 0;
		gao();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

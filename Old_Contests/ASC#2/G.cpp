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
const int maxn = 1e3 + 10;
const double eps = 1e-9;
int N, M, Y, X[maxn];
int K[maxn], ans[maxn];

struct Node {
	int x, k;
	int id;
	bool operator < (const Node &p) const {
		double nowval = (double)x / Y - (double)k / M,
			pval = (double)p.x / Y - (double)p.k / M;
		double nowval1 = (double)x / Y - (double)(k + 1) / M,
			pval1 = (double)p.x / Y - (double)(p.k + 1) / M;
		return  (fabs(nowval1) - fabs(nowval)) > (fabs(pval1) - fabs(pval));
	}
};

Node node[maxn];
priority_queue<Node> q;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (scanf("%d%d%d", &N, &M, &Y) != EOF) {
		int n = N;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &X[i]);
			node[i].id = i;
			node[i].x = X[i];
		}
		int nowcnt = 0;
		for (int i = 1; i <= n; i++) {
			int nowk = (double)X[i] / Y * M;
			node[i].k = nowk;
			nowcnt += nowk;
			q.push(node[i]);
		}
		nowcnt = M - nowcnt;
		while (nowcnt--) {
			Node now = q.top(); q.pop();
			now.k++; q.push(now);
		}
		while(!q.empty()) {
			Node now = q.top(); q.pop();
			ans[now.id] = now.k;
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", ans[i]);
		}
		puts("");
	}
	return 0;
}

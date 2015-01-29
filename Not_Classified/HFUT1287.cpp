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

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

const int maxn = 4e4 + 10;

int lbd[maxn << 2], rbd[maxn << 2], cnt[maxn << 2];

void build(int rt, int l, int r) {
	lbd[rt] = rbd[rt] = cnt[rt] = 1;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}

void pushup(int rt, int l, int r) {
	int lc = rt << 1, rc = rt << 1 | 1;
	lbd[rt] = lbd[lc]; rbd[rt] = rbd[rc];
	cnt[rt] = cnt[lc] + cnt[rc];
	if(rbd[lc] && lbd[rc]) cnt[rt]--;
}

void update(int rt, int l, int r, int pos) {
	if(l == r) {
		lbd[rt] = rbd[rt] = cnt[rt] = 0;
	}
	else {
		int mid = (l + r) >> 1;
		if(pos <= mid) {
			update(lson, pos);
		}
		else {
			update(rson, pos);
		}
		pushup(rt, l, r);
	}
}

struct Node {
	int pos, height;
	bool operator < (const Node &x) const {
		return height < x.height;
	}
};

Node node[maxn], query[maxn];
int ans[maxn];

int main() {
	int n, q;
	scanf("%d", &n);
	build(1, 1, n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &node[i].height);
		node[i].pos = i;
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		scanf("%d", &query[i].height);
		query[i].pos = i;
	}
	int j = 1;
	sort(node + 1, node + 1 + n);
	sort(query + 1, query + 1 + q);
	for(int i = 1; i <= q; i++) {
		while(j <= n && node[j].height <= query[i].height) {
			update(1, 1, n, node[j].pos);
			j++;
		}
		ans[query[i].pos] = cnt[1];
	}
	for(int i = 1; i <= q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}

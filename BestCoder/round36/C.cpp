#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
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
const int maxn = 5e4 + 10;

//输入输出挂
inline bool scanf_(int &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0; //EOF
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}

inline void printf_(int x) {
    if (x>9) printf_(x / 10);
    putchar(x % 10 + '0');
}

//线段树部分
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

bool lbd[maxn << 2], rbd[maxn << 2];
int tcnt[maxn << 2];

inline void pushup(int rt) {
	int lc = rt << 1, rc = rt << 1 | 1;
	tcnt[rt] = tcnt[lc] + tcnt[rc];
	if(rbd[lc] && lbd[rc]) tcnt[rt]--;
	lbd[rt] = lbd[lc]; rbd[rt] = rbd[rc];
}

void build(int rt, int l, int r) {
	if(l == r) {
		lbd[rt] = rbd[rt] = false;
		tcnt[rt] = 0;
	}
	else {
		int mid = l + r >> 1;
		build(lson); build(rson);
		pushup(rt);
	}
}

void update(int rt, int l, int r, int pos) {
	if(l == r) {
		tcnt[rt] = 1;
		lbd[rt] = rbd[rt] = true;
	}
	else {
		int mid = l + r >> 1;
		if(pos <= mid) update(lson, pos);
		else update(rson, pos);
		pushup(rt);
	}
}

//离散化部分
int vnum[maxn << 1], vcnt;

inline int getid(int v) {
	return lower_bound(vnum, vnum + vcnt, v) - vnum + 1;
}

struct Node {
	int id, val;
	bool operator < (const Node &x) const {
		return val > x.val;
	}
};

Node tree[maxn], query[maxn];
int n, q, ans[maxn];


int main() {
	while(scanf("%d%d", &n, &q) != EOF) {
		vcnt = 0;
		for(int i = 1; i <= n; i++) {
			scanf_(tree[i].val);
			tree[i].id = i;
		}
		for(int i = 1; i <= q; i++) {
			scanf_(query[i].val);
			query[i].id = i;
		}
		sort(tree + 1, tree + 1 + n);
		sort(query + 1, query + 1 + q);
		build(1, 1, n);
		for(int i = 1, j = 1; i <= q; i++) {
			while(j <= n && tree[j].val > query[i].val) {
				update(1, 1, n, tree[j].id);
				j++;
			}
			ans[query[i].id] = tcnt[1];
		}
		for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	}
	return 0;
}

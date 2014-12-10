#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

const int maxn = 1e6 + 10;
int n, num[maxn], maxv[maxn << 2], minv[maxn << 2];
vector<int> ans;
map<int, int> mp;

void pushup(int rt) {
	maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
	minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]);
}

void build(int rt, int l, int r) {
	if (l == r) maxv[rt] = minv[rt] = num[l];
	else {
		int mid = (l + r) >> 1;
		build(lson); build(rson);
		pushup(rt);
	}
}

int query_min(int rt, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) return minv[rt];
	int mid = (l + r) >> 1, ret = 1e9 + 5;
	if (ql <= mid) ret = min(ret, query_min(lson, ql, qr));
	if (qr > mid) ret = min(ret, query_min(rson, ql, qr));
	return ret;
}

int query_max(int rt, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) return maxv[rt];
	int mid = (l + r) >> 1, ret = -1e9 - 5;
	if (ql <= mid) ret = max(ret, query_max(lson, ql, qr));
	if (qr > mid) ret = max(ret, query_max(rson, ql, qr));
	return ret;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		mp.clear(); ans.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &num[i]);
			mp[num[i]] = i;
		}
		build(1, 1, n);
		int npos = mp[query_max(1, 1, n, 1, n)];
		int flag = 1, pos = npos;
		while (pos >= 1) {
			ans.push_back(pos);
			if (pos == 1) break;
			if (flag == 1) {
				pos = query_min(1, 1, n, 1, pos - 1);
				flag = -1;
			}
			else {
				pos = query_max(1, 1, n, 1, pos - 1);
				flag = 1;
			}
			pos = mp[pos];
		}

		pos = npos; flag = 1;
		while (pos <= n) {
			ans.push_back(pos);
			if (pos == n) break;
			if (flag == 1) {
				flag = -1;
				pos = query_min(1, 1, n, pos + 1, n);
			}
			else {
				flag = 1;
				pos = query_max(1, 1, n, pos + 1, n);
			}
			pos = mp[pos];
		}
		sort(ans.begin(), ans.end());
		int ncnt = unique(ans.begin(), ans.end()) - ans.begin();
		printf("%d\n", ncnt);
		for (int i = 0; i < ncnt; i++) {
			if (i) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}

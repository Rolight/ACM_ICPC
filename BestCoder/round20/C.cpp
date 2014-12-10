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
const int maxn = 1005;

class BIT {
	int val[maxn << 2], n;
	inline int lowbit(int x) {
		return x & (-x);
	}

public:

	void init(int __n) {
		n = __n;
		memset(val, 0, sizeof(val));
	}
	void addv(int pos, int v) {
		while(pos <= n) {
			val[pos] = max(val[pos], v);
			pos += lowbit(pos);
		}
	}

	int GetMax(int pos) {
		int ret = 0;
		while(pos >= 1) {
			ret = max(ret, val[pos]);
			pos -= lowbit(pos);
		}
		return ret;
	}
};

BIT bit[maxn];
int a[maxn], b[maxn], f[maxn][maxn][2];
int n, m, num[maxn << 2], numcnt;

inline int GetID(int Val) {
	return lower_bound(num, num + numcnt, Val) - num + 1;
}

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		memset(f, 0, sizeof(f));
		scanf("%d%d", &n, &m);
		numcnt = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i], &b[i]);
			num[numcnt++] = a[i];
			num[numcnt++] = b[i];
		}
		sort(num, num + numcnt);
		numcnt = unique(num, num + numcnt) - num;
		for(int i = 1; i <= n; i++) {
			a[i] = GetID(a[i]);
			b[i] = GetID(b[i]);
		}
		for(int i = 0; i <= m; i++) bit[i].init(numcnt);
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = m; j >= 0; --j) {
				int prev_max = bit[j].GetMax(a[i] - 1);
				f[i][j][0] = prev_max + 1;
				bit[j].addv(a[i], f[i][j][0]);
				ans = max(ans, f[i][j][0]);
				if(j == 0) continue;
				prev_max = bit[j - 1].GetMax(b[i] - 1);
				f[i][j][1] = prev_max + 1;
				bit[j].addv(b[i], f[i][j][1]);
				ans = max(ans, f[i][j][1]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

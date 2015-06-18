#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
#include <cstdlib>

typedef long long LL;
const int maxn = 1e4 + 10;
int n, m, val[maxn], numv[maxn], ncnt;
int minv[maxn][15], maxv[maxn][15], cnt[maxn], nid[maxn];

void init_RMQ() {
    for (int i = 0; i < n; i++) minv[i][0] = maxv[i][0] = val[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) < n + 1; i++) {
            maxv[i][j] = std::max(maxv[i][j - 1], maxv[i + (1 << (j - 1))][j - 1]);
            minv[i][j] = std::min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
        }
    }
}

inline int query_min(int a, int b) {
	int k = 0;
	while((1 << (k + 1)) <= b - a + 1) k++;
	return std::min(minv[a][k], minv[b - (1 << k) + 1][k]);
}

inline int query_max(int a, int b) {
	int k = 0;
	while((1 << (k + 1)) <= b - a + 1) k++;
	return std::max(maxv[a][k], maxv[b - (1 << k) + 1][k]);
}

void gao(int k) {
	int ans = 0, l = 0, r = k - 1, nowcnt = 0;
	int nowmin, nowmax;
	for(int i = 0; i < k; ++i) {
		if(cnt[nid[i]] == 0) ++nowcnt;
		++cnt[nid[i]];
	}
	for(l = 0; l  < n; ++l, ++r) {
		if(r < n) {
			nowmin = query_min(l, r);
			nowmax = query_max(l, r);
			if(nowcnt == k && nowmax - nowmin + 1 == k) ++ans;
		}
		--cnt[nid[l]];
		if(cnt[nid[l]] == 0) --nowcnt;
		if(r + 1 < n) {
			if(cnt[nid[r + 1]] == 0) ++nowcnt;
			++cnt[nid[r + 1]];
		}
	}
	printf("%d\n", ans);
}

int main() {
	printf("Case #1:\n");
	scanf("%d%d", &n, &m);
	ncnt = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", val + i);
		numv[ncnt++] = val[i];
	}
	init_RMQ();
	std::sort(numv, numv + n);
	ncnt = std::unique(numv, numv + n) - numv;
	for(int i = 0; i < n; i++) {
		nid[i] = std::lower_bound(numv, numv + n, val[i]) - numv;
	}
	for(int i = 0; i < m; i++) {
		int k; scanf("%d", &k);
		gao(k);
	}
	return 0;
}

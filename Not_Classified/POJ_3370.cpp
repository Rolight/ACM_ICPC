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
const int maxn = 1e5 + 10;
typedef long long LL;
int num[maxn], n, pos[maxn], m;
LL sum[maxn];

void print(int l, int r) {
	for(int i = l; i <= r; i++) printf("%d ", i); puts("");
}

void solve() {
	for(int i = 1; i <= n; i++) if(sum[i] == 0) {
		print(1, i);
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(pos[sum[i]] == -1) {
			pos[sum[i]] = i;
		}
		else {
			print(pos[sum[i]] + 1, i);
			return;
		}
	}
}

int main() {
	while(scanf("%d%d", &m, &n) != EOF) {
		if(n == 0 && m == 0) break;
		for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
		for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + num[i];
		for(int i = 1; i <= n; i++) sum[i] %= m;
		memset(pos, -1, sizeof(pos));
		solve();
	}
	return 0;
}

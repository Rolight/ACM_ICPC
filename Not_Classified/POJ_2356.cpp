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
const int maxn = 1e4 + 10;
typedef long long LL;
int num[maxn], n, pos[maxn];
LL sum[maxn];

void print(int l, int r) {
	for(int i = l; i <= r; i++) printf("%d\n", num[i]);
}

void solve() {
	for(int i = 1; i <= n; i++) if(sum[i] == 0) {
		printf("%d\n", i);
		print(1, i);
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(pos[sum[i]] == -1) {
			pos[sum[i]] = i;
		}
		else {
			printf("%d\n", i - pos[sum[i]]);
			print(pos[sum[i]] + 1, i);
			return;
		}
	}
	puts("0");
}

int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
		for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + num[i];
		for(int i = 1; i <= n; i++) sum[i] %= n;
		memset(pos, -1, sizeof(pos));
		solve();
	}
	return 0;
}

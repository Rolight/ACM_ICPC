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
const int maxn = 5e4 + 10;
const LL mod = 998244353;
int n;
LL a[maxn];

inline LL lowbit(LL x) {
	return x & -x;
}

LL gao() {
	LL ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			ans = (ans + lowbit(a[i] ^ a[j])) % mod;
		}
	}
	return ans;
}

bool cmp(int a, int b) {
	return lowbit(a) < lowbit(b);
}

int calc(LL t) {
	int ret = 0;
	while(t) {
		ret++; 
		t >>= 1;
	}
	return ret;
}

LL pwe(int i) {
	if(i == 0) return 0;
	return (1LL << (i - 1));
}

LL solve(int l, int r, int g);

LL c1(int i, int j, int cnt[]) {
	return cnt[i] * cnt[j] % mod * lowbit(pwe(i) ^ pwe(j)) % mod;
}

LL solve(int l, int r, int g) {
	if(r == l) return 0;
	int cnt[31], gl[31], gr[31];
	memset(cnt, 0, sizeof(cnt));
	memset(gl, -1, sizeof(gl));
	for(int i = l; i <= r; i++) {
		a[i] &= ~((1 << g) - 1);
	}
	std::sort(a + l, a + r + 1, cmp);
	for(int i = l; i <= r; i++) {
		int t = calc(lowbit(a[i]));
		cnt[t]++;
		if(gl[t] == -1) gl[t] = i;
		gr[t] = i;
	}
	LL ans = 0;
	for(int i = 0; i <= 30; i++) if(cnt[i] > 0) {
		for(int j = 0; j <= 30; j++) if(cnt[j] > 0) {
			if(i != j) ans = ans + c1(i, j, cnt);
			else if(i != 0) ans = ans + solve(gl[i], gr[i], i);
			ans %= mod;
		}
	}
	return ans;
}

int main() {
	freopen("lala.in", "r", stdin);
	int T; 
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
		//printf("baoli is %I64d\n", gao());
		printf("Case #%d: %I64d\n", kase, solve(1, n, 0));
	}
	return 0;
}

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
const int maxn = 1e5 + 10;
const int maxm = 450;
const LL mod = 998244353;

int n, c, l, r, m;
LL f[maxn], g[maxn], t[maxn];

void init() {
	int mz = 1e5, mc = 450;
	f[0] = t[0] = 1;
	for(int i = 1; i <= mc; i++) {
		for(int j = 0; j < i; j++) g[j] = 0;
		for(int j = i; j <= mz; j++) {
			g[j] = g[j - i] + f[j - i];
			g[j] %= mod;
		}
		memcpy(f, g, sizeof(f));
		for(int j = 0; j <= mz; j++) {
			t[j] = (t[j] + f[j]) % mod;
		}
	}
	for(int i = 1; i <= mz; i++) {
		t[i] = (t[i] + t[i - 1]) % mod;
	}
}

int main() {
	int T; scanf("%d", &T);
	init();
	while(T--) {
		scanf("%d%d%d%d", &n, &c, &l, &r);
		l -= c; r -= c;
		LL ans;
		if(l == 0) ans = t[r];
		else ans = (t[r] - t[l - 1] + mod) % mod;
		std::cout << ans << std::endl;
	}
	return 0;
}

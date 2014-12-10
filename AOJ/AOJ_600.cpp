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
typedef long long LL;
const int maxn = 1005;
const double eps = 1e-8;
double f[maxn][maxn];
LL p[105];
int n;

void init() {
	p[0] = 1;
	for(int i = 1; i <= 50; i++) p[i] = p[i - 1] * 10;
}

LL getval(LL x) {
	if(x == 0) return 0;
	LL ret = 0;
	LL num = x, cnt = 0, ff;
	while(num) {
		cnt++; num /= 10;
	}
	for(int i = 0; i < cnt - 1; i++) ret += p[i];
	ff = x / p[cnt - 1];
	if(ff == 1) ret += x % p[cnt - 1] + 1;
	else ret += p[cnt - 1];
	return ret;
}

int main() {
	init();
	int T; cin >> T;
	for(int kase = 1; kase <= T; kase++) {
		cin >> n;
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for(int i = 1; i <= n; i++) {
			LL nowl, nowr; cin >> nowl >> nowr;
			LL nowval = getval(nowr) - getval(nowl - 1);
			double nowp = (double)(nowval) / (double)(nowr - nowl + 1);
			for(int j = 1; j <= i; j++) {
				f[i][j] = f[i - 1][j - 1] * nowp + f[i - 1][j] * (1 - nowp);
			}
		}
		double k; cin >> k;
		k /= 100;
		double ans = 0;
		for(int i = 0; i <= n; i++) {
			if((double)i / (double)n + eps >= k) {
				ans += f[n][i];
			}
		}
		printf("%.6f\n", ans);
	}
	return 0;
}

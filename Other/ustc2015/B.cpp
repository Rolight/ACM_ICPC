#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

const int mod = 10000007;
const int maxn = 1e5 + 10;
LL f[maxn][2];

int gao(int m) {
	int t = sqrt(m) + 0.5, cnt = 0;
	for(int i = 1; i <= t; i++) if(m % i == 0 && i <= m / i) {
		if(i < m / i) cnt += 2;
		else cnt++;
	}
	return (cnt % 2);
}

void solve(int n) {
	memset(f, 0, sizeof(f));
	f[1][0] = 1; f[1][1] = 1;
	for(int i = 2; i <= n; i++) {
		f[i][0] = (f[i - 1][1] + f[i - 1][0]) % mod;
		f[i][1] = f[i - 1][0] % mod;
	}
	cout << (f[n][0] + f[n][1] - 1 + mod) % mod << endl;
}

int main() {
	int n, m;
	while(scanf("%d%d", &m, &n)) {
		if(n == -1 || m == -1) break;
		if(gao(m) == 0) {
			puts("No girl");
		}
		else solve(n);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long LL;
const int maxn = 505;

LL n, m, b, mod;
LL f[maxn][maxn], a[maxn];

int main() {
	cin >> n >> m >> b >> mod;
	LL ans = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int k = a[i]; k <= b; k++) {
				f[j][k] += f[j - 1][k - a[i]];
				f[j][k] %= mod;
			}
		}
	}
	for(int i = 0; i <= b; i++) ans = (ans + f[m][i]) % mod;
	cout << ans << endl;
	return 0;
}


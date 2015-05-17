#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long LL;
const int maxn = 505;

LL n, m, b, mod;
LL f1[maxn][maxn], f2[maxn][maxn], a[maxn];

int main() {
	cin >> n >> m >> b >> mod;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 0; i <= m && i * a[1] <= b; i++) {
		f1[i * a[1]][i]++;
	}
	for(int i = 2; i <= n; i++) {
		memset(f2, 0, sizeof(f2));
		for(int j = 0; j <= m; j++) {
			for(int k = 0; k + j * a[i] <= b; k++) {
				for(int l = 0; l + j <= m; l++) {
					f2[k + j * a[i]][l + j] += f1[k][l];
					f2[k + j * a[i]][l + j] %= mod;
				}
			}
		}
		memcpy(f1, f2, sizeof(f1));
	}
	LL ans = 0;
	for(int i = 0; i <= b; i++) ans = (ans + f1[i][m]) % mod;
	cout << ans << endl;
	return 0;
}


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
const LL mod = 1e9 + 9;
LL f[30][maxn];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, k; scanf("%d%d", &k, &n);
		memset(f, 0, sizeof(f));
		for(int i = 0; i <= k && i <= n; i++) f[0][i] = 1;
		for(int i = 0; i < 16; i++) {
			for(int j = 0; j <= n; j++) if(f[i][j]) {
				for(int t = 0; t <= k; t++) {
					LL nxt = ((LL)t << (i + 1)) + j;
					if(nxt > n) break;
					f[i + 1][nxt] = (f[i + 1][nxt] + f[i][j]) % mod;
				} 
			}
		}
		cout << f[16][n] << endl;
	}
	return 0;
}

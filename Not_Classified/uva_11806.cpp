#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1000007;
const int MAXK = 500;
int C[MAXK + 5][MAXK + 5];

int main() {
	int T;
	memset(C,0,sizeof(C));
	C[0][0] = 1;
	for(int i = 0;i <= MAXK;i++) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1;j < i;j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}

	scanf("%d",&T);
	for(int kase = 1;kase <= T;kase++) {
		int n,m,k; scanf("%d%d%d",&n,&m,&k);
		int a1 = C[(n - 1) * m][k],b1 = C[n * (m - 1)][k];
		int a2 = C[(n - 2) * m][k],b2 = C[n * (m - 2)][k],c2 = C[(n - 1) * (m - 1)][k];
		int a3 = C[(n - 1) * (m - 2)][k],b3 = C[(n - 2) * (m - 1)][k];
		int a4 = C[(n - 2) * (m - 2)][k];
		int ans = C[n * m][k];
		ans -= (a1 + b1) * 2;
		ans = (ans + a2 % MOD + b2 % MOD + (4 * c2) % MOD) % MOD;
		ans -= 2 * (a3 + b3);
		while(ans < 0) ans += MOD;
		ans += a4;
		printf("Case %d: %d\n",kase,ans % MOD);
	}
	return 0;
}

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 70;

int lim[maxn];
long long dp[maxn][2];

long long dfs(int i,int j,bool flag) {
	if(i == 1) return 1;
	if(!flag && dp[i][j] != -1) return dp[i][j];
	int bound = (flag ? lim[i - 1] : 9);
	long long ret = 0;
	for(int k = 0;k <= bound;k++) {
		if(j == 1 && k == 9) continue;
		ret += dfs(i - 1,k == 4,flag && (k == bound));
	}
	return flag ? ret : dp[i][j] = ret;
}

int main() {
	int t; long long n;
	scanf("%d",&t);
	while(t--) {
		scanf("%I64d",&n);
		long long sn = n;
		memset(dp,-1,sizeof(dp));
		int len = 0;
		while(n) {
			lim[++len] = n % 10;
			n /= 10;
		}
		printf("%I64d\n",sn + 1LL - dfs(len + 1,0,true));
	}
	return 0;
}

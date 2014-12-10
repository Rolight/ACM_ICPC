#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <climits>

using namespace std;

const int maxn = 105;
char str[maxn];
int len;
int dp[maxn][2];


//记忆化搜索
//	state == 0 default
//	state == 1 Caps Lock on
int dfs(int pos,int state) {
	char now = str[pos];
	if(~dp[pos][state]) return dp[pos][state];
	int ret = INT_MAX;
	if(pos == len) return dp[pos][state] = state;
	if(isupper(now)) {
		if(state == 0) {
			//using shift
			ret = min(ret,dfs(pos + 1,0) + 2);
			//using Caps Lock
			ret = min(ret,dfs(pos + 1,1) + 2);
		} else {
			ret = dfs(pos + 1,1) + 1;
		}
	} else {
		if(state == 0) {
			ret = dfs(pos + 1,0) + 1;
		} else {
			//using shift
			ret = min(ret,dfs(pos + 1,1) + 2);
			//using Caps Lock
			ret = min(ret,dfs(pos + 1,0) + 2);
		}
	}
	return dp[pos][state] = ret;
}


//递推动态规划
int solve() {
	dp[0][0] = 0; dp[0][1] = INT_MAX / 2;
	for(int i = 1;i <= len;i++) {
		if(isupper(str[i - 1])) {
			dp[i][0] = min(dp[i - 1][0] + 2,dp[i - 1][1] + 2);
			dp[i][1] = min(dp[i - 1][0] + 2,dp[i - 1][1] + 1);
		} else {
			dp[i][0] = min(dp[i - 1][0] + 1,dp[i - 1][1] + 2);
			dp[i][1] = min(dp[i - 1][0] + 2,dp[i - 1][1] + 2);
		}
	}
	return min(dp[len][0],dp[len][1] + 1);
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%s",str);
		len = strlen(str);
		printf("%d\n",solve());
	}
	return 0;
}

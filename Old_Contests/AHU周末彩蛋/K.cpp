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
const int maxn = 25;
int dp[maxn][maxn][maxn][maxn];

int dfs(int n, int a, int b, int c) {
	if(n == 1) return c - a;
	if(dp[n][a][b][c] != -1) return dp[n][a][b][c];
	int ret = 0;
	if(c - a == 1) {
		ret += dfs(n - 1, a, c ,b);
		ret += 1;
		ret += dfs(n - 1, b, a, c);
	}
	else {
		ret += dfs(n - 1, a, b, c);
		ret += 1;
		ret += dfs(n - 1, c, b, a);
		ret += 1;
		ret += dfs(n - 1, a, b, c);
	}
	return dp[n][a][b][c] = ret;
}

int main() {
	int T; cin >> T;
	memset(dp, -1, sizeof(dp));
	while(T--) {
		int n; cin >> n;
		cout << dfs(n, 1, 2, 3) << endl;
	}
	return 0;
}

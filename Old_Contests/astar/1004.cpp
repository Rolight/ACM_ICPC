#include <cstdio>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <ctime>
#include <set>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <string>
#include <list>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

int max(int a,int b,int c) {
	return max(a,max(b,c));
}

const int maxn = 105;

int n,m;
int mm[maxn][maxn];
int dp[maxn][maxn][3];

int main() {
	int T,kase = 1; scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				scanf("%d",&mm[i][j]);
			}
		}
		for(int i = 0;i <= n;i++) {
			for(int j = 0;j <= m;j++) {
				dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -INF;
			}
		}
		dp[0][1][1] = 0;
		dp[1][1][0] = mm[1][1];
		for(int i = 1;i <= n;i++) {
			dp[i][1][1] = dp[i-1][1][1] + mm[i][1];
		}
		for(int j = 2;j <= m;j++) {
			for(int i = 1;i <= n;i++) {
				dp[i][j][0] = 
					max(dp[i][j-1][0],dp[i][j-1][1],dp[i][j-1][2]) + mm[i][j];
			}
			dp[1][j][1] = dp[1][j][0];
			for(int i = 2;i <= n;i++) {
				dp[i][j][1] = max(dp[i-1][j][0],dp[i-1][j][1]) + mm[i][j];
			}
			dp[n][j][2] = dp[n][j][0];
			for(int i = n - 1;i >= 1;i--) {
				dp[i][j][2] = max(dp[i+1][j][2],dp[i+1][j][0]) + mm[i][j];
			}
			/*
			for(int i = 1;i <= n;i++) {
				printf("%d %d %d %d %d\n",i,j,dp[i][j][0],dp[i][j][1],dp[i][j][2]);
			}
			*/
		}
		printf("Case #%d:\n%d\n",kase++,max(dp[1][m][0],dp[1][m][2]));
	}
	return 0;
}



#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

#define sq(x) ((x)*(x))

using namespace std;

const int maxn = 2005;
const int INF = INT_MAX / 2;
int w[maxn];
int dp[maxn][maxn];


int main() {
	int n,k;
	while(~scanf("%d%d",&n,&k)) {
		for(int i = 1;i <= n;i++) scanf("%d",&w[i]);
		sort(w + 1,w + n + 1);
		memset(dp,0,sizeof(dp));
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= i / 2;j++) {
				if(i == j * 2) 
					dp[i][j] = dp[i - 2][j - 1] + sq(w[i] - w[i - 1]);
				else 
					dp[i][j] = min(dp[i - 1][j],
							dp[i - 2][j - 1] + sq(w[i] - w[i - 1]));
			}
		}
		printf("%d\n",dp[n][k]);
	}
	return 0;
}

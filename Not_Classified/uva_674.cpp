#include <cstdio>
#include <cstring>

using namespace std;

int v[5] = {50,25,10,5,1};
long long dp[8001][5];

int main() {
	int x;
	dp[0][0] = 1;
	for(int i = 0;i < 7490;i++) {
		for(int prev = 0;prev < 5;prev++) {
			for(int j = prev;j < 5;j++) if(i >= v[j]) {
				dp[i][j] += dp[i - v[j]][prev];
			}
		}
	}
	while(~scanf("%d",&x)) {
		long long sum = 0;
		for(int i = 0;i < 5;i++) sum += dp[x][i];
		printf("%lld\n",sum);
	}
	return 0;
}

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

#define min_t(a,b) (((a)<(b))?(a):(b))

LL min(LL a,LL b,LL c,LL d) {
	return min_t(min_t(a,b),min_t(c,d));
} 

LL dp[6000];

void init() {
	int l1 = 1,l2 = 1,l3 = 1,l4 = 1;
	dp[1] = 1;
	for(int i = 2;i <= 5842;i++) {
		dp[i] = min(dp[l1] * 2,dp[l2] * 3,dp[l3] * 5,dp[l4] * 7);
		if(dp[i] == dp[l1] * 2) l1++;
		if(dp[i] == dp[l2] * 3) l2++;
		if(dp[i] == dp[l3] * 5) l3++;
		if(dp[i] == dp[l4] * 7) l4++;
	}
}

int main() {
	int n;
	init();
	while(scanf("%d",&n),n) {
		cout << "The " << n;
		if(n % 100 / 10 == 1) cout << "th";
		else if(n % 10 == 1) cout << "st";
		else if(n % 10 == 2) cout << "nd";
		else if(n % 10 == 3) cout << "rd";
		else cout << "th";
		cout << " humble number is " << dp[n] << "." << endl;
	}
	return 0;
}

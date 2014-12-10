#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int sum[100010];

int main() {
	int n, a, key;
	scanf("%d", &n);
	sum[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a);
		sum[i] = sum[i-1] + a;
	}
	key = sum[n] / 2;
	int l = 1, r = n, ans = 0;
	while(l != r) {
		int m = (l+r) >> 1;
		if(key >= sum[m]) {
			ans = m;
			l = m + 1;
		}
		else
			r = m;
	}
	if(sum[ans] <= sum[n] - sum[ans+1])	ans++;
	printf("%d %d\n", ans, n - ans);
	return 0;
}

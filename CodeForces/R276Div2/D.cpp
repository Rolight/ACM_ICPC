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
const int maxn = 2e5 + 10;
const int maxv = 3e6 + 10;
int num[maxv], a[maxn];

int main() {
	int n, tmp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		num[a[i]] = a[i];
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	for(int i = 1; i <= 2e6; i++) {
		if(!num[i]) num[i] = num[i - 1];
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int nowval = a[i];
		if(a[i] == 1) continue;
		for(int j = nowval * 2; j <= 2e6; j += nowval) {
			ans = max(ans, num[j - 1] % nowval);
		}
	}
	printf("%d\n", ans);
	return 0;
}

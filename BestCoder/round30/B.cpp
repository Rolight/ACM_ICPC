#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int tp = 3e5;
vector<LL> ans, g, prime;
LL n;

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}

void calc(LL num) {
	int m = sqrt(num + 0.5);
	g.clear();
	for(int i = 1; i <= m; i++) if(num % i == 0 && i <= num / i) {
		g.push_back(i);
		if(i != num / i)
			g.push_back(num / i);
	}
	for(int i = 0; i < g.size(); i++) {
		LL nval = g[i] ^ n;
		if(nval < n && gcd(nval, n) == (nval ^ n) && nval > 0) {
			ans.push_back(nval);
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	int kase = 0;
	while(scanf("%I64d", &n) != EOF) {
		ans.clear();
		calc(n);
		printf("Case #%d:\n", ++kase);
		printf("%d\n", (int)ans.size());
		sort(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); i++) {
			if(i) putchar(' ');
			printf("%I64d", ans[i]);
		}
		puts("");
	}
	return 0;
}

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
const int maxn = 205;
LL val[maxn], n, ans;
map<LL, LL> cnt;

int main() {
	int kase = 0;
	while(scanf("%d", &n) != EOF) {
		cnt.clear();
		ans = 0;
		for(int i = 0; i < n; i++) {
			scanf("%I64d", &val[i]);
			cnt[val[i]]++;
		}
		if(cnt.size() <= 1) {
			printf("Case #%d: -1\n", ++kase);
			continue;
		}
		int j = 0;
		for(map<LL, LL>::iterator i = cnt.begin(); 
				i != cnt.end(); i++) {
			val[j++] = i->first;
		}
		for(int i = 0; i < j; i++) {
			LL ret = val[i] + val[(i - 1 + j) % j];
			if(ret % INT_MAX == val[(i + 1) % j]) {
				ans += cnt[val[i]];
			}
		}
		printf("Case #%d: %I64d\n", ++kase, ans);
	}
	return 0;
}

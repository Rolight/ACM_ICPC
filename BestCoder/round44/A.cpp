#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
#include <cstdlib>

typedef long long LL;
const int maxn = 16;
int sc[maxn], msc[maxn], cnt[maxn];

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		int ans = 0;
		for(int i = 1; i <= 4; i++) {
			scanf("%d%d", &sc[i], &cnt[i]);
			msc[i] = (500 + i * 500) * 4 / 10;
			sc[i] = (500 + i * 500) / 250 * (250 - sc[i]);
			sc[i] -= cnt[i] * 50;
			ans += std::max(sc[i], msc[i]);
		}
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}

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
typedef long long LL;
const int maxn = 1005;
int num[maxn], n, f[maxn];
LL t[maxn];

void solve() {
	int maxlen = 0;
	memset(f, 0, sizeof(f));
	memset(t, 0, sizeof(t));
	for(int i = 1; i <= n; i++) {
		f[i] = 1; t[i] = 1;
		for(int j = 1; j < i; j++) if(num[j] < num[i]) {
			if(f[j] + 1 > f[i]) t[i] = 0;
			if(f[j] + 1 >= f[i]) {
				f[i] = f[j] + 1;
				t[i] += t[j];
			}
		}
		maxlen = max(maxlen, f[i]);
	}
	LL cnt = 0;
	for(int i = 1; i <= n; i++) if(f[i] == maxlen) cnt += t[i];
	if(cnt > 1) printf("%d\n", maxlen);
	else printf("%d\n", maxlen - 1);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
		solve();
	}
	return 0;
}

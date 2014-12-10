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
const LL mod = 1e9 + 9;

int bits[64], k, n;
LL f[64][10000 + 10];

void getbits(int num) {
	memset(bits, 0, sizeof(bits));
	for(int i = 0; i <= 30; i++) bits[i] = (bool)(num & (1 << i));
}

LL dfs(int now, int over, LL nownum) {
	if(now == 30) return over == 0;
	if(nownum > n) return 0;
	if(f[now][over] != -1) return f[now][over];
	LL ret = 0;
	for(int i = 0; i <= k; i++) {
		if(nownum + (i << now) > n) break;
		if((over + i) % 2 == bits[now]) {
			ret += dfs(now + 1, (over + i - bits[now]) >> 1, 
					nownum + (i << (now)));
			ret %= mod;
		}
	}
	if(f[now][over] == -1) f[now][over] = ret % mod;
	return ret % mod;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &k, &n);
		memset(f, -1, sizeof(f));
		getbits(n);
		cout << dfs(0, 0, 0) << endl;
	}
	return 0;
}

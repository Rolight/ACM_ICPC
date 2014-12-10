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
typedef long double LD;
const LL mod = 1e9 + 7;
vector<LL> vec;
LD maxval;
LL ans;
int n, k;

LD ppow(LD a, int k) {
	LD ret = 1;
	while(k--) ret *= a;
	return ret;
}

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}

void dfs(int nownum, int nowcnt, LL nowmodval, LD nowrealval) {
	int rest = k - nowcnt;
	if(nowrealval > maxval) {
		maxval = nowrealval;
		ans = nowmodval;
	}
	if(n - nownum > 30 || ppow(nownum, rest) * nowrealval < maxval) return;
	if(nowcnt == k) return;
	for(int i = nownum - 1; i >= 1 && i >= n - 30; i--) {
		int m = vec.size();
		bool ok = true;
		for(int j = 0; j < m; j++) if(gcd(i, vec[j]) != 1) {
			ok = false; break;
		}
		if(ok) {
			vec.push_back(i);
			dfs(i, nowcnt + 1, (nowmodval * i) % mod, nowrealval * i);
			vec.pop_back();
		}
	}
}

int main() {
	while(scanf("%d%d", &n, &k) != EOF) {
		vec.clear();
		maxval = 1; ans = 1;
		dfs(n + 1, 0, 1, 1);
		cout << ans << endl;
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <cmath>
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
const int maxk = 1e4 + 10;
const int maxn = 12;

int num[maxn], f[maxn][maxn * 9][maxn * 9], len, k;

void gao(int n) {
	len = 0;
	while(n) {
		num[len++] = n % 10; n /= 10;
	}
}

//数位DP
//当前位数， 当前数对k的余数， 位和对n的余数
int dfs(int now, int rn, int rbit, int bound) {
	if(now == 0) return rn == 0 && rbit == 0;
	int &note = f[now][rbit][rn];
	if(note != -1 && !bound) return note;
	int ret = 0, m = bound ? num[now - 1] : 9;
	for(int i = 0; i <= m; i++) {
		ret += dfs(now - 1, (rn * 10 + i) % k, (rbit + i) % k, bound && i == m);
	}
	if(!bound) note = ret;
	return ret;
}

int work(int n) {
	gao(n);
	if(n == 0 || k > len * 9) return 1;
	memset(f, -1, sizeof(f));
	return dfs(len, 0, 0, 1);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int a, b; 
		scanf("%d%d%d", &a, &b, &k);
		printf("%d\n", work(b) - work(a - 1));
	}
	return 0;
}

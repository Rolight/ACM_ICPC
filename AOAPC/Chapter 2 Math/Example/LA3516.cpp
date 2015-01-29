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
const int maxn = 512;
const LL mod = 1e9;
char buf[maxn];
int f[maxn][maxn];

int dfs(int i, int j) {
	int &ret = f[i][j];
	if(ret != -1) return ret;
	ret = 0;
	if(buf[i] != buf[j]) return ret;
	if(i == j) return ret = 1;
	for(int k = i + 2; k <= j; k++) {
		ret += (LL)dfs(i + 1, k - 1) * (LL)dfs(k, j) % mod;
		ret %= mod;
	}
	return ret;
}

int main() {
	while(scanf("%s", buf + 1) != EOF) {
		int len = strlen(buf + 1);
		memset(f, -1, sizeof(f));
		int ans = dfs(1, len);
		printf("%d\n", ans);
	}
	return 0;
}

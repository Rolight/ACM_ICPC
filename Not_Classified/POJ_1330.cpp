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
const int maxn = 1e4 + 10;
int fa[maxn], n;
bool vis[maxn];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		memset(fa, -1, sizeof(fa));
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i < n; i++) {
			int a, b; scanf("%d%d", &a, &b);
			fa[b] = a;
		}
		int qa, qb; scanf("%d%d", &qa, &qb);
		int ans = -1;
		for(int pos = qa; ~pos; pos = fa[pos]) vis[pos] = true;
		for(int pos = qb; ~pos; pos = fa[pos]) {
			if(vis[pos]) {
				ans = pos; break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

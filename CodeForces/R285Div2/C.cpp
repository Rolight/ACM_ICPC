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
const int maxn = 1 << 17;
int n, xsum[maxn], cnt[maxn];
bool vis[maxn];

set< pair<int, int> > ans;

int main() {
	scanf("%d", &n);
	queue<int> q;
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &cnt[i], &xsum[i]);
		if(cnt[i] == 1) {
			q.push(i);
			vis[i] = true;
		}
	}
	while(!q.empty()) {
		int now = q.front(); q.pop();
		if(cnt[now] == 0) continue;
		int u = now, v = xsum[now];
		if(u > v) swap(u, v);
		ans.insert(make_pair(u, v));
		xsum[xsum[now]] ^= now; 
		cnt[xsum[now]]--;
		if(cnt[xsum[now]] == 1 && !vis[xsum[now]]) {
			q.push(xsum[now]); 
			vis[xsum[now]] = true;
		}
	}
	printf("%d\n", (int)ans.size());
	for(auto it = ans.begin(); it != ans.end(); ++it) {
		printf("%d %d\n", it->first, it->second);
	}
	return 0;
}

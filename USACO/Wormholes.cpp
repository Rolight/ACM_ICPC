/*
ID: flsnnx1
LANG: C++
TASK: wormhole
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 16;
int x[maxn], y[maxn], n, ans, p[maxn], p1[maxn];
bool vis[maxn], vis1[maxn], flag;

void dfs1(int now, bool state) {

	if(state == true) {
		vis1[now] = true;
		dfs1(p[now], !state);
	}
	else {
		if(p1[now] != 0) {
			if(!vis1[p1[now]]) {
				dfs1(p1[now], !state);
			}
			else flag = true;
		}
	}
}

void dfs(int now, int cnt) {
	vis[now] = true;
	for(int i = 1; i <= n; i++) if(!vis[i]) {
		p[now] = i; p[i] = now;
		vis[i] = true;
		for(int j = 1; j <= n; j++) if(!vis[j]) {
			dfs(j, cnt + 2); break;
		}
		if(cnt + 2 == n) {
			flag = false;
			for(int i = 1; i <= n && !flag; i++) {
				memset(vis1, 0, sizeof(vis1));
				dfs1(i, true);
			}
			ans += (int)flag;
			c++;
		}
		vis[i] = false;
	}
	vis[now] = false;
}

int main() {
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	scanf("%d", &n);
	c = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) if(y[i] == y[j] && x[i] < x[j]) {
			if(p1[i] == 0) p1[i] = j;
			else if(x[j] < x[p1[i]]) p1[i] = j;
		}
	}
	dfs(1, 0);
	printf("%d\n", ans);
	//system("pause");
	return 0;
}

/*
6
1 15
20 15
17 11
22 21
25 11
20 17
*/

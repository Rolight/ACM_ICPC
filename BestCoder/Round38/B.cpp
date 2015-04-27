#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 10;

bool vis[maxn];
vector<int> vec[maxn];

void pre() {
	int m;
	for(int i = 1; i <= 1e5; i++) {
		m = sqrt(i + 0.5);
		for(int j = 1; j <= m; j++) if(i % j == 0) {
			vec[i].push_back(j);
			vec[i].push_back(i / j);
		}
	}
}

int main() {
	pre();
	int T, n, m, ans, num;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d", &n);
		memset(vis, 0, sizeof(vis));
		ans = 1;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &num);
			m = vec[num].size();
			for(int j = 0; j < m; j++) {
				if(vis[vec[num][j]]) {
					ans = max(ans, vec[num][j]);
				}
				vis[vec[num][j]] = true;
			}
		}
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}


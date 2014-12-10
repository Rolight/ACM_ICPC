#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
const int mod = 1000000007;
int col[maxn], n;
bool vis[maxn];

vector<int> edge[maxn];
vector<bool> cha[maxn];

bool dfs(int now) {
	int m = edge[now].size();
	if (m == 0) return col[now];
	bool ret = false;
	for (int i = 0; i < m; i++) {
		int nc = edge[now][i];
		bool nret = dfs(nc);
		ret |= nret;
		cha[now].push_back(nret);
	}
	return ret | col[now];
}

LL dfs1(int now) {
	int m = edge[now].size();
	if (col[now] == 0) {
		LL ret = 1, ret1 = 1;
		int cnt_one = 0;
		for (int i = 0; i < m; i++) if (cha[now][i]) {
			cnt_one++; ret1 *= dfs1(edge[now][i]);
		}
		if (!cnt_one) return 1;
		for (int i = 0; i < cnt_one; i++) ret = (ret * ret1) % mod;
		for (int i = 0; i < m; i++) {
			int nc = edge[now][i], tmp = col[nc];
			col[nc] = 1; ret *= dfs1(nc); ret %= mod;
			col[nc] = tmp;
		}
	}
	else {

	}
}

int main() {
	int root = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		edge[tmp].push_back(i);
		//edge[i].push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &col[i]);
	}
	dfs(0);
	return 0;
}
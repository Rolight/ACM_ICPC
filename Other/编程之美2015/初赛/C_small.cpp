#include <cstdio>
#include <cstring>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1000;
const int maxm = 500000;
typedef bitset<maxn> bit_val;
vector<int> pnum;
bool vis[maxm + 1];
int pc[maxn + 1][30], pcnt[maxn + 1];
int num[maxn + 1], n, pos[maxm + 1];
bit_val bz[maxn + 1];
bool gg[maxn][maxn];

void pre() {
	for(int i = 2; i <= maxm; i++) if(vis[i] == false) {
		pnum.push_back(i);
		for(int j = i + i; j <= maxm; j += i) {
			vis[j] = true;
		}
	}
}

int gao() {
	memset(pcnt, 0, sizeof(pcnt));
	memset(pos, -1, sizeof(pos));
	memset(gg, 0, sizeof(gg));
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		pos[num[i]] = i;
		//bz[i].reset(); bz[i].flip();
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < pnum.size() && pnum[j] <= num[i]; j++) {
			if(num[i] % pnum[j] == 0 && pos[num[i] / pnum[j]] != -1) {
				gg[i][pos[num[i] / pnum[j]]] = 1;
				gg[pos[num[i] / pnum[j]]][i] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i < (1 << n); i++) {
		int cnt = 0, ok = 1;
		for(int j = 0; j < n; j++) if(i & (1 << j)) cnt++;
		for(int j = 0; j < n && ok; j++) if(i & (1 << j)) {
			for(int k = j + 1; k < n && ok; k++) if(i & (1 << k)) {
				if(gg[j][k]) ok = 0;
			}
		}
		if(ok) ans = max(ans, cnt);
	}
	return ans;
}

int main() {
	pre();
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		int ret = gao();
		printf("Case #%d: %d\n", kase, ret);
	}
	return 0;
}

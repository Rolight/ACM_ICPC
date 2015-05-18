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
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		pos[num[i]] = i;
		bz[i].reset(); bz[i].flip();
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < pnum.size() && pnum[j] <= num[i]; j++) {
			if(num[i] % pnum[j] == 0 && pos[num[i] / pnum[j]] != -1) {
				bz[i][pos[num[i] / pnum[j]]] = 0;
			}
		}
	}
	
}

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		printf("Case %d: %d", kase, gao());
	}
	return 0;
}

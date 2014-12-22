#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 10;
const int maxv = 10000000;
const LL mod = 1e9 + 7;

struct Node {
	int id, n;
	bool operator < (const Node &x) const {
		return n < x.n;
	}
};

Node query[maxn];
int ans[maxn], maxval;

int main() {
	int tmp, cnt = 0;
	while(scanf("%d", &tmp) != EOF) {
		query[cnt].n = tmp;
		query[cnt].id = cnt;
		maxval = max(maxval, tmp);
		cnt++;
	}
	LL fc = 1, nv = 1;
	int nid = 0;
	sort(query, query + cnt);
	for(int i = 1; i <= maxval; i++) {
		fc = (fc * i) % mod;
		nv = (nv * fc) % mod;
		while(query[nid].n == i) {
			ans[query[nid].id] = nv;
			nid++;
		}
	}
	for(int i = 0; i < cnt; i++) {
		printf("%d\n", ans[i]);
	} 
	return 0;
}

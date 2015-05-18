#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 5005;

struct Node {
	vector<int> ch;
	int c;
};

Node node[maxn];
int n, q;

int gao() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		node[i].c = 0; node[i].ch.clear();
	}
	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		node[u].ch.push_back(v);
		node[v].ch.push_back(u);
	}
	scanf("%d", &q);
	int cmd, x, y, ans = 1;
	while(q--) {
		scanf("%d", &cmd);
		if(cmd == 1) printf("%d\n", ans);
		else {
			scanf("%d%d", &x, &y);
			if(node[x].c == y) continue;
			int g1 = 0, g2 = 0;
			for(int i = 0; i < node[x].ch.size(); i++) {
				Node &now = node[node[x].ch[i]];
				if(now.c == y) g2++;
				if(now.c == node[x].c) g1++;
			}
			node[x].c = y;
			ans = ans + g1 - g2;
		}
	}
}

int main() {
	//freopen("out.txt", "w", stdout);
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		printf("Case #%d:\n", kase);
		gao();
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 512;

struct Node {
	int a, b, id;
	bool operator < (const Node &x) const {
		int t0 = a - b, t1 = x.a - x.b;
		if(t0 == t1) {
			if(b == x.b) return id < x.id;
			else return b < x.b;
		}
		return t0 > t1;
	}
};

Node node[maxn];

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &node[i].a, &node[i].b);
			node[i].id = i;
		}
		sort(node + 1, node + 1 + n);
		for(int i = 1; i <= n; i++) {
			if(i > 1) putchar(' ');
			printf("%d", node[i].id - 1);
		}
		puts("");
	}
	return 0;
}

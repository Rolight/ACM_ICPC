#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 256;

int ans[maxn], h[maxn], rank[maxn];

bool cmp(int a, int b) {
	return h[a] > h[b];
}

void gao() {
	int n; scanf("%d", &n);
	int a, b, c;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		ans[i] = i;
		h[i] = max(a, max(b, c));
	}
	sort(ans + 1, ans + n + 1, cmp);
	for(int i = 1; i <= n; i++)  {
		rank[ans[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		if(i > 1) putchar(' ');
		printf("%d", rank[i]);
	}
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		gao();
	}
	return 0;
}

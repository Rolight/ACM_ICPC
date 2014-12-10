#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 10;
bool vis[maxn];

int main() {
	int n, T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(vis, false, sizeof(vis));
		int num = abs(n), nowmod = 1, nowval;
		vis[1] = true; vis[0] = true;
		if (num == 1) {
			puts("1"); continue;
		}
		if (n < 0) putchar('-');
		printf("0.");
		while (1) {
			nowval = (nowmod * 10) / num;
			nowmod = (nowmod * 10) % num;
			printf("%d", nowval);
			if (vis[nowmod]) break;
			vis[nowmod] = true;
		}
		putchar('\n');
	}
	return 0;
}


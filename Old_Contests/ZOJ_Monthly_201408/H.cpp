#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 10;
int ch[maxn][2], ccnt[maxn], n, fa[maxn];
int f[maxn];

int main() {
	while (scanf("%d", &n) != EOF) {
		memset(ccnt, 0, sizeof(ccnt));
		memset(ch, 0, sizeof(ch));
		memset(f, 0, sizeof(f));
		for (int i = 2; i <= n; i++) {
			scanf("%d", &fa[i]);
			ch[fa[i]][ccnt[fa[i]]++] = i;
		}
		for (int i = n; i >= 1; i--) {
			if (ccnt[i] == 0) f[i] = 1;
			else if (ccnt[i] == 1) f[i] = f[ch[i][0]];
			else {
				f[i] = min(max(f[ch[i][0]] + 1, f[ch[i][1]]),
					max(f[ch[i][1]] + 1, f[ch[i][0]]));
			}
		}
		printf("%d\n", f[1]);
	}
}
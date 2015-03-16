#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 10;
int h[maxn], n, stk[maxn], cnt[maxn], stop, ctop;
bool vis[maxn];

int main() {
	int T; 
	scanf("%d", &T);
	while (T--) {
		memset(vis, 0, sizeof(vis));
		int maxpos = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &h[i]);
			if(h[i] > h[maxpos]) {
				maxpos = i;
			}
		}

		stop = ctop = 0;
		stk[stop++] = h[maxpos];
		cnt[ctop++] = 1;
		LL ans = 0;

		for (int i = (maxpos + 1) % n, j = h[i]; i != maxpos; i = (i + 1) % n) {
			while (stop && stk[stop - 1] < h[i]) {
				stop--; ans += cnt[--ctop];
			}
			if(stop && stk[stop - 1] == h[i]) {
				ans += cnt[ctop - 1];
				cnt[ctop - 1]++;
				if(ctop > 1) ans++;
			}
			else {
				ans++;
				stk[stop++] = h[i];
				cnt[ctop++] = 1;
			}
			if(h[i] >= j) vis[i] = true;
			j = max(h[i], j);
		}
		
		for(int i = (maxpos - 1 + n) % n, j = h[i]; i != maxpos; i = (i - 1 + n) % n) {
			if(h[i] >= j && !vis[i]) ans++;
			j = max(h[i], j);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

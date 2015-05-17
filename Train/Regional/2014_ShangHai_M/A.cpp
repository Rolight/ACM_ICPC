#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 505;
int n, k, arr[maxn], gg[maxn];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}
		bool ok = false;
		for(int i = 0; i * k <= n; i++) {
			for(int j = 1; j <= n; j++) {
				gg[j] = arr[j] + i * k;
			}
			sort(gg + 1, gg + 1 + n);
			bool flag = true;
			for(int j = 1; j <= n; j++) {
				if(gg[j] != j) flag = false;
			}
			if(flag) ok = true;
			if(ok) break;
		}
		if(ok) puts("Jerry");
		else puts("Tom");
	}
	return 0;
}

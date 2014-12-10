#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 3000;
int high[maxn],f[maxn];

int main() {
	int n;
	while(~scanf("%d",&n)) {
		int ans = 0;
		f[0] = 0;
		for(int i = 1;i <= n;i++) {
			scanf("%d",&high[i]);
			f[i] = 1;
			for(int j = i - 1;j >= 1;j--) {
				if(high[j] < high[i]) {
					f[i] = max(f[j] + 1,f[i]);
				}
			}
			if(f[i] > ans) ans = f[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20001;
int power[maxn],r[maxn];

int main() {
	int n,m;
	while(scanf("%d%d",&n,&m),n || m) {
		for(int i = 0;i < n;i++) scanf("%d",&r[i]);
		for(int i = 0;i < m;i++) scanf("%d",&power[i]);
		sort(r,r + n);
		sort(power,power + m);
		int cur = 0,ans = 0;
		for(int i = 0;i < n;i++) {
			while(power[cur] < r[i] && cur < m) cur++;
			if(cur == m) {
				ans = -1; break;
			}
			ans += power[cur++];
		}
		if(~ans) printf("%d\n",ans);
		else printf("Loowater is doomed!\n");
	}
	return 0;
}

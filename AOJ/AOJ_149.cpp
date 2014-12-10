#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10001;
int a[maxn];

int main() {
	int t,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i = 0;i < n;i++) scanf("%d",&a[i]);
		sort(a,a + n);
		int maxl = 0,now = 0;
		for(int i = 0;i < n;i++) {
			if(i > 0 && a[i] != a[i - 1]) {
				maxl = max(now,maxl);
				now = 0;
			}
			now++;
		}
		maxl = max(now,maxl);
		printf("%d\n",maxl);
	}
	return 0;
}

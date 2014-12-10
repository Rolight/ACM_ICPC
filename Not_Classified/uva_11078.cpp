#include <cstdio>
#include <algorithm>
#include <climits>

const int INF = INT_MAX;
using namespace std;

int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		int ans = -INF,maxv,x;
		scanf("%d%d",&maxv,&x);
		for(int i = 2;i < n;i++) {
			ans = max(ans,maxv - x);
			maxv = max(x,maxv);
			scanf("%d",&x);
		}
		ans = max(ans,maxv - x);
		printf("%d\n",ans);
	}
	return 0;
}

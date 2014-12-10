#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100001;
int height[maxn],left_bound[maxn],right_bound[maxn];

#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int n;
	while(scanf("%d",&n),n) {
		for(int i = 1;i <= n;i++) {
			scanf("%d",&height[i]);
			left_bound[i] = right_bound[i] = i;
		}
		height[0] = height[n + 1] = -1;
		for(int i = 1;i <= n;i++) {
			while(height[left_bound[i] - 1] >= height[i]) {
				left_bound[i] = left_bound[left_bound[i] - 1];
			}
			int j = n - i + 1;
			while(height[right_bound[j] + 1] >= height[j]) {
				right_bound[j] = right_bound[right_bound[j] + 1];
			}
		}
		long long ans = 0;
		for(int i = 1;i <= n;i++) {
//			printf("%d %d\n",left_bound[i],right_bound[i]);
			ans = max(ans,height[i] * (right_bound[i] - left_bound[i] + 1LL));
		}
		printf("%lld\n",ans);
	}
	return 0;
}

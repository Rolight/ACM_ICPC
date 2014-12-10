#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 100000 + 5;
int h[maxn],n;

int main() {
	int ans = 0, now = 0;
	scanf("%d",&n);
	h[0] = 0;
	for(int i = 1;i <= n;i++) {
		scanf("%d",&h[i]);
	}
	for(int i = 0;i < n;i++) {
		now += h[i] - h[i + 1];
		if(now < 0) {
			ans += -now;
			now = 0;
		}
	}
	printf("%d\n",ans);
	return 0;
}

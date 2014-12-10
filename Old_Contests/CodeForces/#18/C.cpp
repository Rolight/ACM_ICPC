#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 5;

int val[maxn],sum[maxn],cnt[maxn];

inline int getsum(int l,int r) {
	return sum[r] - sum[l - 1];
}

inline int getval(int l,int r) {
	return 1;
}

int main() {
	int n; scanf("%d",&n);
	for(int i = 1;i <= n;i++) {
		scanf("%d",&val[i]);
		sum[i] = sum[i - 1] + val[i];
		if(val[i] > 0) {
			cnt[i] = cnt[i - 1] + 1;
		} else {
			cnt[i] = cnt[i - 1];
		}
	}
	int ans = 0;
	for(int i = 1;i < n;i++) {
		if(getsum(1,i) == getsum(i + 1,n) 
			&& getval(1,i) != 0 && getval(i + 1,n) != 0) {
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

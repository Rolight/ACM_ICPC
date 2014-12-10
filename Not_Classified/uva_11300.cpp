#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
using namespace std;
const int maxn = 1000001;
int A[maxn];
LL C[maxn];

int main() {
	int n;
	while(~scanf("%d",&n)) {
		LL sum = 0,ans = 0,std;
		for(int i = 0;i < n;i++) {
			scanf("%d",&A[i]);
			sum += A[i];
		}
		sum /= n; C[0] = A[0] - sum;
		for(int i = 1;i < n;i++) C[i] = A[i] - sum + C[i - 1];
		sort(C,C + n);
		if(n & 1) std = C[n / 2];
		else std = (C[n / 2] + C[n / 2 - 1]) / 2;
		for(int i = 0;i < n;i++) ans += abs(std - C[i]);
		printf("%lld\n",ans);
	}
	return 0;
}

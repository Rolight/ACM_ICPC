#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100001;
int A[maxn],B[maxn];

int main() {
	int n,S;
	while(~scanf("%d%d",&n,&S)) {
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			scanf("%d",&A[i]);
			B[i] = B[i - 1] + A[i];
			int str = 1,end = i;
			while(str < end) {
				int mid = str + (end - str + 1) / 2;
				if(B[i] - B[mid - 1] < S) {
					end = mid - 1;
				} else {
					str = mid;
				}
			}
			if(B[i] - B[str - 1] >= S) {
				if(ans == 0) ans = i - str + 1;
				else ans = min(ans,i - str + 1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

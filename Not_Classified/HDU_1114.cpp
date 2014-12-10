#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

const int maxn = 10001;

int f[maxn];

int main() {
	int T,E,F,N,P,W;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&E,&F,&N);
		for(int i = 0;i <= F - E;i++) {
			f[i] = INT_MAX / 2;
		}
		f[0] = 0;
		for(int i = 0;i < N;i++) {
			scanf("%d%d",&P,&W);
			for(int j = W;j <= F - E;j++) {
				f[j] = min(f[j - W] + P,f[j]);
			}
		}
		if(f[F - E] == INT_MAX / 2) {
			puts("This is impossible.");
		} else {
			printf("The minimum amount of money in the piggy-bank is %d.\n",f[F - E]);
		}
	}
	return 0;
}

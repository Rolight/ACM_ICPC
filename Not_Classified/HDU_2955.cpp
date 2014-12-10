#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
double f[10001],p[150],P;
int m[150];

int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		int sum = 0;
		memset(f,0,sizeof(f));
		scanf("%lf%d",&P,&n);
		for(int i = 1;i <= n;i++) {
			scanf("%d%lf",&m[i],&p[i]);
			sum += m[i];
		}
		for(int i = 1;i <= sum;i++) f[i] = 0;
		f[0] = 1;
		for(int i = 1;i <= n;i++) {
			for(int j = sum;j >= m[i];j--) {
				f[j] = max(f[j],f[j - m[i]] * (1 - p[i]));
			}
		}
		for(int i = sum;i >= 0;i--) if(f[i] >= (1 - P)) {
			printf("%d\n",i); break;
		}
	}
	return 0;
}

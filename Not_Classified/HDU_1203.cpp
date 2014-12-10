#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10001;
int cost[maxn];
double p[maxn],f[maxn];

int main() {
	int money,n;
	while(scanf("%d%d",&money,&n),money || n) {
		double ans;
		for(int i = 0;i <= money;i++) f[i] = 1;
		for(int i = 1;i <= n;i++) {
			scanf("%d%lf",&cost[i],&p[i]);
			for(int j = money;j >= cost[i];j--)
				f[j] = min(f[j],f[j - cost[i]] * (1 - p[i]));
		}
		printf("%.1f%%\n",(1 - f[money]) * 100);
	}
	return 0;
}

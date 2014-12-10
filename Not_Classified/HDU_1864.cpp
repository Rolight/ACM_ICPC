#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 31;

double f[maxn],val[400];

int main() {
	int N; double Q;
	while(scanf("%lf%d",&Q,&N),N) {
		memset(f,0,sizeof(f));
		double ans = 0;
		for(int i = 0;i < N;i++) {
			int n,pos = 0; scanf("%d",&n);
			double sum[3] = {0,0,0};
			for(int j = 0;j < n;j++) {
				char kind; double _val;
				scanf(" %c:%lf",&kind,&_val);
				if(kind < 'A' || kind > 'C') sum[0] = 1005;
				else {
					sum[kind - 'A'] += _val;
					if(sum[kind - 'A'] > 600) sum[0] = 1005;
				}
				if(sum[0] + sum[1] + sum[2] > 1000) continue;
				val[pos++] = _val;
			}
			if(sum[0] + sum[1] +sum[2] > 1000) continue;
			for(int j = N;j >= 1;j--) {
				f[j] = max(f[j],f[j - 1] + sum[0] + sum[1] + sum[2]);
				if(f[j] > ans && f[j] <= Q) ans = f[j];
			}
		}
		printf("%.2f\n",ans);
	}
	return 0;
}

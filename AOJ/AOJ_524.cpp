#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

double f[100001];

int main() {
	int n; double m;
	while(~scanf("%d%lf",&n,&m)) {
		memset(f,0,sizeof(f));
		double l,p;
		for(int i = 0;i < n;i++) {
			scanf("%lf%lf",&p,&l);
			for(int j = (int)(m * 100);j >= (int)(p * 100);j--) {
				f[j] = max(f[j],f[j - (int)(p * 100)] + l);
			}
		}
		printf("%.1f\n",f[(int)(m * 100)]);
	}
	return 0;
}

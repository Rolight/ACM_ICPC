#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		double ans = 0;
		for(int i = 1;i < n;i++) {
			double pos = (double)i * (m + n) / n;
			ans += min(pos - (int)pos,(int)(pos + 1) - pos);
		}
		printf("%.4lf\n",ans * 10000 / (m + n));
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int maxn = 10001;
int f[maxn],s[maxn],e[maxn];

int main() {
	int n;
	while(scanf("%d",&n),n) {
		int ans = 0;
		f[0] = -INT_MAX / 2;
		for(int i = 1;i <= n;i++) {
			int tmp; scanf("%d",&tmp);
			if(f[i - 1] + tmp > tmp) {
				f[i] = f[i - 1] + tmp; s[i] = s[i - 1];
			} else {
				f[i] = tmp; s[i] = tmp;
			}
			if(f[i] > f[ans]) ans = i;
			e[i] = tmp;
		}
		if(f[ans] < 0) printf("0 %d %d\n",e[1],e[n]);
		else printf("%d %d %d\n",f[ans],s[ans],e[ans]);
	}
	return 0;
}

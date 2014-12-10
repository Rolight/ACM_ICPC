#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100001;
int f[maxn],s[maxn];

int main() {
	bool first = true;
	int T,N;
	scanf("%d",&T);
	for(int k = 1;k <= T;k++) {
		if(first) {
			first = false;
		} else putchar('\n');
		printf("Case %d:\n",k);
		int sum = 0,ans = 1;
		scanf("%d",&N);
		memset(f,0,sizeof(f));
		s[0] = 1;
		for(int i = 1;i <= N;i++) {
			int tmp; scanf("%d",&tmp);
			if(f[i - 1] + tmp >= tmp) {
				s[i] = s[i - 1];
				f[i] = f[i - 1] + tmp;
			} else {
				s[i] = i;
				f[i] = tmp;
			}
			if(f[i] > f[ans]) ans = i;
		}
		printf("%d %d %d\n",f[ans],s[ans],ans);
	}
	return 0;
}

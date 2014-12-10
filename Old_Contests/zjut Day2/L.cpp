#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		long long max = -1,sum = 0;
		int tmp;
		for(int i = 0;i < n;i++) {
			scanf("%d",&tmp);
			sum += tmp;
			if(tmp > max) max = tmp;
		}
		if(max <= sum - max + 1) puts("Yes");
		else puts("No");
	}
	return 0;
}

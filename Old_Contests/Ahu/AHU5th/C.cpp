#include <cstdio>
#include <cstring>

const int maxn = 32;

int bin[maxn],len;

inline int ck(int num) {
	int tk = 0;
	for(int i = 0;i < maxn;i++) {
		if(num & (1 << i)) {
			tk++;
		}
	}
	return tk;
}

int main() {
	int T,n; scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		int k0 = ck(n);
		for(int i = n + 1;i <= 2100000000;i++) {
			if(ck(i) == k0) {
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}

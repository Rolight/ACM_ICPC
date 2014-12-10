#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000005;

char str[maxn];
int f[maxn];

inline void getfail() {
	int m = strlen(str);
	f[0] = f[1] = 0;
	for(int i = 2;i <= m;i++) {
		int j = f[i - 1];
		while(j && str[i - 1] != str[j]) j = f[j];
		if(str[i - 1] == str[j]) f[i] = j + 1;
		else f[i] = 0;
	}
}

int main() {
	int n,kase = 0;
	while(scanf("%d",&n),n) {
		printf("Test case #%d\n",++kase);
		scanf("%s",str); getfail();
		for(int i = 1;i <= n;i++) {
			if(f[i] > 0 && i % (i - f[i]) == 0) {
				printf("%d %d\n",i,i / (i - f[i]));
			}
		}
		putchar('\n');
	}
	return 0;
}


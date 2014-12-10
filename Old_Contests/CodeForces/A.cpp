#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1001;

int main() {
	int n;
	while(~scanf("%d",&n)) {
		printf("%d\n",(n / 2 + n % 2) * (n / 2 + n % 2) + (n / 2) * (n / 2));
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				if(i % 2 == 0) {
					if(j % 2 == 0) putchar('C');
					else putchar('.');
				} else {
					if(j % 2 == 0) putchar('.');
					else putchar('C');
				}
			}
			putchar('\n');
		}
	}
	return 0;
}

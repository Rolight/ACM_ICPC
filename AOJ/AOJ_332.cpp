#include <cstdio>
using namespace std;
char note[10001],b;
int main() {
	int n;
	while(scanf("%d",&n) != EOF) {
		if(!note[n]) {
			if(b) putchar(' ');
			printf("%d",n);
			note[n] = b = 1;
		}
	}
	putchar('\n');
	return 0;
}

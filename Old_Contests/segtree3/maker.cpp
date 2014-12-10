#include <cstdio>
#include <cstdlib>

using namespace std;

const int max = 10000;

int main() {
	printf("%d %d\n",max,max + 600);
	for(int i = 1;i <= max + 600;i++) {
		if(i & 1) printf("D "); else printf("Q ");
		printf("%d\n",rand() % max + 1);
	}
	return 0;
}

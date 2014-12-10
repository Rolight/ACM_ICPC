#include <cstdio>

using namespace std;

int f(int n) {
	return n == 1 ? 1 : f(n >> 1) + 1;
}

int main() {
	int n;
	while(~scanf("%d",&n)) {
		printf("%d\n",f(n));
	}
	return 0;
}

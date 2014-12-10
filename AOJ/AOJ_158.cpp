#include <cstdio>

using namespace std;

int solve(int n) {
	if(n == 1) return 0;
	if(n == 2 || n == 3) return 1;
	if(n % 3 == 0) return solve(n / 3) + 1;
	return solve(n / 3 + 1) + 1;
}	

int main() {
	int n;
	while(scanf("%d",&n),n) printf("%d\n",solve(n));
	return 0;
}

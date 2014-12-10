#include <stdio.h>

void sum(int n) {
	int i,term = 1;
	double ans = 0;
	for(i = 1;i <= n;i++) {
		ans += 1.0f / i * term;
		term *= -1;
	}
	printf("%.2f\n",ans);
}

int main() {
	int n,i,t;
	scanf("%d",&n);
	for(i = 0;i < n;i++) {
		scanf("%d",&t);
		sum(t);
	}
	return 0;
}

#include <stdio.h>
#include <iostream>


const int range = 5000;
bool prime[range];
int cprime,primers[range],N;
long long ans[60];

void maker() {
	prime[1] = true;
	for(int i = 2;i < range;i++) if(!prime[i]) {
		for(int j = (i << 1);j < range;j += i) prime[j] = true;
		primers[cprime++] = i;
	}
}

void readin() {
	scanf("%d",&N);
}


void work() {
	int pp = 0;
	for(int i = 0;i < N;i++) ans[i] = primers[pp++];
	for(int i = 1;i < N;i++) ans[i] *= primers[pp];
	pp++;
	for(int i = 0;i < N - 1;i++) ans[i] *= primers[pp];
	ans[0] *= primers[++pp];
	ans[N - 1] *= primers[pp];
	for(int i = 0;i < N;i++) printf("%I64d\n",ans[i]);
}

int main() {
	maker();
	readin();
	if(N == 2) printf("-1\n");
	else work();
	return 0;
}

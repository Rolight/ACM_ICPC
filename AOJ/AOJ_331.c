#include <stdio.h>

int work(int p,int n)
{
	if(n == 0) return 1;
	int temp = work((p * p) % 9973,n / 2);
	if(n % 2 == 1) temp = (temp * p) % 9973;
	return temp;
}

int main()
{
	int n,i;
	while(scanf("%d",&n) && n != 0)
	{
		if(n < 0) continue;
		printf("%d\n",work(2,n) - 1);
	}
	return 0;
}

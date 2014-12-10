#include <stdio.h>
#include <math.h>

#define isprime(num) (!a[num])

char a[900001]; 

void init()
{
	int i,j;
	a[1] = 1;
	for(i = 2;i <= 900000;i++)
	{
		if(a[i] == 0)
			for(j = (i << 1);j <= 900000;j += i) a[j] = 1;
	}
}

int countprime(int str,int end)
{
	int i,sum = 0;
	for(i = str;i <= end;i++) if(isprime(i)) sum++;
	return sum;	
}

int main()
{
	int a,b;
	init();
	while(scanf("%d %d",&a,&b) == 2)
		printf("%d\n",countprime(a,b));
	return 0;
}

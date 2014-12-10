#include <stdio.h>
#include <math.h>

int main()
{
	int n,i,j;
	while(scanf("%d",&n) && n != 0)
	{
		int t = n / 2 + 1;
		for(i = 1;i <= n;i++)
		{
			for(j = 0;j < abs(i - t);j++) printf(" ");
			for(j = 0;j < 2 * (-abs(i - t) + t) - 1;j++) printf("*");
			printf("\n");
		}
	}
	return 0;
}

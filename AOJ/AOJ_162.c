#include <stdio.h>
#include <string.h>

unsigned int n,m,a[100];

int main()
{
	while(scanf("%d",&m) && m != 0)
	{
		memset(a,0,sizeof(a));
		int i,j;
		a[1] = 1;
		for(i = 1;i <= m;i++)
		{
			for(j = i;j >= 1;j--) a[j] = a[j] + a[j - 1];
			for(j = 1;j <= i;j++) printf("%d%c",a[j],(j == i)?'\n':' ');
		}
		printf("\n");
	}
	return 0;
}

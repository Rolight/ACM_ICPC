#include <stdio.h>

int main()
{
	char t,max = 0;
	while(scanf("%c",&t) != EOF)
	{
		if(t == '\n')
		{
			putchar(max);
			max = 0;
			printf("\n");
		}
		else if(t > max) max = t;
	}
	return 0;
}

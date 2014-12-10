#include <stdio.h>

int main()
{
	int deep = 0,max = 0;
	char c;
	while(scanf("%c",&c) != EOF)
	{
		if(c == '(')
		{
			deep++;
			if(deep > max) max = deep;
		}
		if(c == ')')
		{
			deep--;
			if(deep < 0) deep = -2100000000;
		}
		if(c == '\n')
		{
			if(deep == 0) printf("%d\n",max);
			else printf("Error\n");
			max = 0;
			deep = 0;
		}
	}
	return 0;
}

#include <stdio.h>

int main()
{
	int g;
	while(scanf("%d",&g) != EOF)
	{
		if(g > 100 || g < 0)
		{
			puts("Score is error!");
			continue;
		}
		g /= 10;
		char t;
		switch(g)
		{
			case 10:
			case 9: t = 'A'; break;
			case 8: t = 'B'; break;
			case 7: t = 'C'; break;
			case 6: t = 'D'; break;
			default: t = 'E';
		}
		printf("%c\n",t);
	}
	return 0;
}

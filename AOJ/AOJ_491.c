#include <stdio.h>

char con(char c)
{
	switch(c)
	{
		case 'A': return 14; break;
		case 'J': return 11; break;
		case 'Q': return 12; break;
		case 'K': return 13; break;
		case '2': return 15; break;
		default: return c - '0';
	}
}

int main()
{
	int T,i;
	scanf("%d",&T);
	getchar();
	for(i = 0;i < T;i++)
	{
		char a,b,t;
		scanf("%c%c%c",&a,&t,&b);
		if(t == '0')
		{
			a = '0' + 10;
			scanf("%c",&b);
		}
		scanf("%c",&t);
		if(t != '\n')
		{
			b = '0' + 10;
			getchar();
		}
		a = con(a);
		b = con(b);
		if(a == b) puts("=");
		else if(a < b) puts("<");
		else puts(">");
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

char number[2000];

int main() 
{
	int T,i,j;
	scanf("%d",&T);
	for(i = 0;i < T;i++)
	{
		scanf("%s",number);
		int len = strlen(number);
		for(j = 0;j < len;j++)
		{
			if(number[j] == '.')
			{
				if(number[j - 1] != '9' && number[j + 1] - '0' >= 5) number[j - 1]++;
				number[j] = 0;
				break;
			}
		}
		len = strlen(number);
		int flag = 0;
		for(j = 0;j < len && number[j] != '.';j++) if(number[j] != '0') 
		{
			flag = 1;
			break;
		}
		if(flag == 0) puts("0");
		else printf("%s\n",number + j);
	}
	return 0;
}

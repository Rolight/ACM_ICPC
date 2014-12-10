#include <stdio.h>
#include <string.h>

char num[800];

int main()
{
	while(scanf("%s",num))
	{
		int len = strlen(num),sum = 0,i;
		if(len == 1 && num[0] == '0') break;
		
		for(i = 0;i < len;i++) sum += num[i] - '0';
		printf("%d\n",sum);
	}
	return 0;
}

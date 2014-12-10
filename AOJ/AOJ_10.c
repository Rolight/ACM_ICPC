#include <stdio.h>
#include <string.h>

int main()
{
	char str[2000];
	while(gets(str + 1))
	{
		int len = strlen(str + 1),i,j,k;
		for(i = len;i >= 1;i--)
		{
			//奇数逆时针 偶数顺时针 
			if(i & 1)	//奇数 逆时针 后面的放到前面 
			{
				//把第一个存起来然后后面几个往前移位然后把第一个放到最后
				char first = str[i];
				for(j = i;j + i <= len;j += i) str[j] = str[j + i];
				str[j] = first;
			}
			else //偶数 顺时针
			{
				//把最后一个存起来放到第一个，然后其他的往后移
				char last;
				for(j = len;j >= 1;j--) if(j % i == 0) break;
				last = str[j];
				for(;j - i >= 1;j -= i) str[j] = str[j - i];
				str[j] = last;
			} 
		}
		puts(str + 1);
	}
	return 0;
}

#include <stdio.h>

int mlim[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int isr(int year)
{
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return 1;
	else return 0;
}

int main()
{
	int year,month,day;
	while(scanf("%d-%d-%d",&year,&month,&day) != EOF)
	{
		int count = 0,i;
		if(isr(year)) mlim[2] = 29;
		else mlim[2] = 28;
		for(i = 1;i < month;i++) count += mlim[i];
		count += day;
		printf("%d\n",count);
	}
	return 0;
}

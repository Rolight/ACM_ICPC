/*
ID: flsnnx1
LANG: C
TASK: friday
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define year(x) ((x)->year)
#define month(x) ((x)->month)
#define day(x) ((x)->day)
#define dayinweek(x) ((x)->dayinweek)


unsigned int month_lim[13] = {
	0,31,28,31,30,31,30,31,31,30,31,30,31
};

struct Timect
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int dayinweek;	
};

typedef struct Timect time;

inline void add_day(time *t)
{
	day(t)++;
	if(day(t) > month_lim[month(t)])
	{
		month(t)++;
		day(t) = 1;
	}
	dayinweek(t) = (dayinweek(t) + 1) % 7;
	if(month(t) > 12)
	{
		year(t)++;
		month(t) = 1;
		int leap = 0;
		if(year(t) % 4 == 0 && year(t) % 100 != 0) leap = 1;
		if(year(t) % 400 == 0) leap = 1;
		if(leap) month_lim[2] = 29;
		else month_lim[2] = 28;
	}
}

int main()
{
	time *t = (time *)malloc(sizeof(t));
	year(t) = 1900;
	day(t) = 1;
	month(t) = 1;
	dayinweek(t) = 2;
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	int span,i,f[7];
	scanf("%d",&span);
	memset(f,0,sizeof(f));
	while(year(t) < 1900 + span)
	{
		if(day(t) == 13) f[dayinweek(t)]++;
		add_day(t);
	}
	for(i = 0;i < 7;i++)
	{
		printf("%d",f[i]);
		if(i != 6) printf(" ");
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

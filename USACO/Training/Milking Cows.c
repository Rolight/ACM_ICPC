/*
ID: flsnnx1
LANG: C
TASK: milk2
*/

#include <stdio.h>
#include <memory.h>

int main()
{
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	char span[1000001];
	memset(span,0,sizeof(span));
	unsigned int n,i,start,end,last = 0,empty = 0,resempty = 0,reslast = 0,mend = 0,mstart = 1000001;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d%d",&start,&end);
		memset(span + start,1,sizeof(char) * (end - start));
		if(end > mend)	mend = end;
		if(start < mstart)	mstart = start;
	}
	for(i = mstart;i < mend;i++)
	{
		if(span[i] == 0)
		{
			if(last > reslast)	reslast = last;
			last = 0;
			empty++;
		}
		else
		{
			if(empty > resempty) resempty = empty;
			empty = 0;
			last++;
		}
	}
	if(last > reslast) reslast = last;
	if(empty > resempty) resempty = empty;
	printf("%d %d\n",reslast,resempty);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

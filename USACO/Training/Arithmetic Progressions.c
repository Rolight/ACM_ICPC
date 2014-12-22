/*
ID: flsnnx1
LANG: C
TASK: ariprog
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXM 250 * 250 * 2

struct anst
{
	int a;
	int b;
}ans[100000];

int cmp(struct anst *a,struct anst *b)
{
	if(a->b == b->b)
		return a->a - b->a;
	else return a->b - b->b;
}

void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;	
}

void myqsort(int str,int end)
{
	if(str >= end) return;
	int mid = (str + end) / 2,i = str,j = end;
	struct anst std = ans[mid];
	while(1)
	{
		while(cmp(&ans[i],&std) < 0) i++;
		while(cmp(&ans[j],&std) > 0) j--;
		if(i < j)
		{
			swap(&ans[i].a,&ans[j].a);
			swap(&ans[i].b,&ans[j].b);
		}
		else break;
		i++;
		j--;
	}
	myqsort(str,i - 1);
	myqsort(j + 1,end);
}


int main()
{
	FILE *in = fopen("ariprog.in","r"),*out = fopen("ariprog.out","w");
	int N,M,i,j,count = 0;
	fscanf(in,"%d%d",&N,&M);
	char *mask = (char *)calloc(M * M * 2 + 1,sizeof(char));
	for(i = 0;i <= M;i++)
		for(j = 0;j <= M;j++)
			mask[i * i + j * j] = 1;
	int n = N,a,b;
	for(a = 0;a <= M * M * 2;a++)
	{
		if(!mask[a]) continue;
		for(b = 1;(N - 1) * b + a <= M * M * 2;b++)
		{
			int found = 1;
			for(n = 1;n <= N - 1;n++)
			{
				if(!mask[a + n * b])
				{
					found = 0;
					break;
				}
			}
			if(found)
			{
				ans[count].a = a;
				ans[count].b = b;
				++count;
			}
		}
	}
	printf("FINISHED!");
	if(count == 0) fprintf(out,"NONE\n");
	else
	{
		myqsort(0,count - 1);
		for(i = 0;i < count;i++)
			fprintf(out,"%d %d\n",ans[i].a,ans[i].b);
	}
	return 0;
}

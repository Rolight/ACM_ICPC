/*
ID: flsnnx1
LANG: C
TASK: checker
*/

#include <stdio.h>
#include <math.h>
#include <memory.h>

#define MAX 14

int N,ans[MAX],list[MAX][MAX],count = 0;
FILE *in,*out;

void search(int row)
{
	if(row == 3 && N > 6)
	{
		list[ans[1]][ans[2]] = 1;
		list[ans[2]][ans[1]] = 1;
	}
	if(row == N + 1)
	{
		int i;
		count++;
		if(count > 3) return;
		for(i = 1;i <= N;i++)
		{
			fprintf(out,"%d",ans[i]);
			if(i != N) fprintf(out," ");
		}
		fprintf(out,"\n");
		return;
	}
	int i,mask[MAX];
	memset(mask,0,sizeof(mask));
	for(i = 1;i < row;i++)
	{
		mask[ans[i]] = 1;
		if(ans[i] - row + i > 0) mask[ans[i] - row + i] = 1;
		if(ans[i] + row - i <= N) mask[ans[i] + row - i] = 1;
	}
	for(i = 1;i <= N;i++)
	{
		int j,flag = 1;
		if(mask[i] == 0)
		{
			ans[row] = i;
			if(row == 2 && list[ans[1]][ans[2]] == 1) continue;
			search(row + 1);
		}
	}
}

int main()
{
	in = fopen("checker.in","r"),out = fopen("checker.out","w");
	fscanf(in,"%d",&N);
	search(1);
	fprintf(out,"%d\n",count + count * (N > 6));
	return 0;
}

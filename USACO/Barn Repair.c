/*
ID: flsnnx1
LANG: C
TASK: barn1 
*/

#include <stdio.h>
#include <memory.h>

#define oo 2100000000

void megresort(int str,int end,int *arr);

int main()
{
	FILE *in = fopen("barn1.in","r"),*out = fopen("barn1.out","w");
	int M,S,C,i,j,ans = 0,count = 0,str = oo,end = -oo;
	fscanf(in,"%d%d%d",&M,&S,&C);
	int stall[S + 1],blank[S];
	memset(stall,0,sizeof(stall));
	memset(blank,0,sizeof(blank));
	for(i = 0;i < C;i++)
	{
		fscanf(in,"%d",&j);
		if(j < str) str = j;
		if(j > end) end = j;
		stall[j] = 1;
	}
	debug_print(stall,S + 1);
	for(i = str;i <= end;i++)
	{
		if(stall[i] == 0)
		{
			j = i;
			while(stall[j] == 0)
				blank[count]++,j++;
			count++;
			i = j - 1;
		}
	}
	megresort(0,count - 1,blank);
	debug_print(blank,count);
	for(i = 0;i < M - 1 && i < count;i++) ans += blank[i];
	ans = end - str + 1 - ans;
	fprintf(out,"%d\n",ans);
	return 0;
}

void megresort(int str,int end,int *arr)
{
	if(str >= end) return;
	int mid = (str + end) / 2,L[mid - str + 2],R[end - mid + 1],i,j;
	megresort(str,mid,arr);
	megresort(mid + 1,end,arr);
	L[mid - str + 1] = R[end - mid] = -oo;
	for(i = 0;i < mid - str + 1;i++) L[i] = arr[str + i];
	for(i = 0;i < end - mid;i++) R[i] = arr[mid + i + 1];
	i = j = 0;
	while(!(L[i] == -oo && R[j] == -oo))
	{
		if(L[i] > R[j]) arr[str + i + j] = L[i],i++;
		else arr[str + i + j] = R[j],j++;
	}
}

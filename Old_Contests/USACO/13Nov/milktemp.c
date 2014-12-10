/*
ID: roll
LANG: C
TASK: combo
*/

#include <stdio.h>
#define maxn 20001

int N,X,Y,Z,l[maxn],r[maxn];

void readin()
{
	FILE *in = fopen("milktemp.in","r");
	fscanf(in,"%d%d%d%d",&N,&X,&Y,&Z);
	int i;
	for(i = 1;i <= N;i++) fscanf(in,"%d%d",&l[i],&r[i]);
}

int cmp(int la,int lb,int ra,int rb)
{
	if(lb != rb) return lb - rb;
	else return la - ra;
}

void sort(int str,int end)
{
	if(str >= end) return;
	int i = str,j = end,mid = (i + j) / 2,lstd = l[mid],rstd = r[mid];
	while(1)
	{
		while(cmp(l[i],r[i],lstd,rstd) < 0) i++;
		while(cmp(l[j],r[j],lstd,rstd) > 0) j--;
		if(i < j)
		{
			int tl = l[i],tr = r[i];
			l[i] = l[j]; r[i] = r[j];
			l[j] = tl; r[j] = tr;
			i++; j--;
		}
		else break;
	}
	sort(str,i - 1);
	sort(j + 1,end);
}

void check(int *L,int *R,int *IN,int pos)
{
	int i;
	*L = *R = *IN = 0;
	for(i = 1;i <= N;i++)
	{
		if(pos < l[i]) (*L)++;
		else if(pos > r[i]) (*R)++;
		else (*IN)++;
	}
}

void work()
{
	FILE *out = fopen("milktemp.out","w");
	int i,L,R,IN,ans = 0;
	for(i = 1;i <= N;i++)
	{
		check(&L,&R,&IN,r[i]);
		int t = L * X + IN * Y + R * Z;
		if(t > ans) ans = t;
	}
	fprintf(out,"%d\n",ans);
}

int main()
{
	readin();
	sort(1,N);
	work();
	return 0;
}

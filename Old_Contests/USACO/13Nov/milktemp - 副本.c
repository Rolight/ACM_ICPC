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
	for(i = 1;i <= 100;i++)
	{
		check(&L,&R,&IN,i);
		int t = L * X + IN * Y + R * Z;
		if(t > ans) ans = t;
	}
	fprintf(out,"%d\n",ans);
}

int main()
{
	readin();
	work();
	return 0;
}

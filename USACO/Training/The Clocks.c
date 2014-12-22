/*
ID: flsnnx1
LANG: C
TASK: clocks 
*/

#include <stdio.h>

int mask[10]= 
{
	0,
	(1 << 24) | (1 << 21) | (1 << 15) | (1 << 12),
	(1 << 24) | (1 << 21) | (1 << 18),
	(1 << 21) | (1 << 18) | (1 << 12) | (1 << 9),
	(1 << 24) | (1 << 15) | (1 << 6),
	(1 << 21) | (1 << 15) | (1 << 12) | (1 << 9) | (1 << 3),
	(1 << 18) | (1 << 9) | (1 << 0),
	(1 << 15) | (1 << 12) | (1 << 6) | (1 << 3),
	(1 << 6) | (1 << 3) | (1 << 0),
	(1 << 12) | (1 << 9) | (1 << 3) | (1 << 0)
};

int modmask,rmask;

int clock,s[28],flen,found = 0,times[10],oriclock;

int max(int a,int b)
{
	return (a > b) ? a : b;
}

void dfs(int step,int maxs)
{
	if(!clock)
	{
		found = 1;
		flen = step - 1;
		return;
	}
	if(found) return;
	if(step > maxs) return;
	int i;
	for(i = max(s[step - 1],1);i <= 9;i++)
	{
		if(times[i] + 1 > 3) continue;
		times[i]++;
		int tclock = clock;
		clock = (clock + mask[i]) & modmask;	
		s[step] = i;
		dfs(step + 1,maxs);
		if(found) return;
		times[i]--;
		clock = tclock;
	}
}

int main()
{
	FILE *in = fopen("clocks.in","r"),*out = fopen("clocks.out","w");
	int i,len = 10;
	for(i = 1;i <= 9;i++)
	{
		int t;
		fscanf(in,"%d",&t);
		t = (t / 3) & 3;
		clock |= (t << (9 - i) * 3);
		modmask |= (3 << (9 - i) * 3);
	}
	oriclock = clock;
	dfs(1,27);
	for(i = 1;i <= flen;i++) 
	{
		fprintf(out,"%d",s[i]);
		if(i != flen) fprintf(out," ");
	}
	fprintf(out,"\n");
	return 0;
}

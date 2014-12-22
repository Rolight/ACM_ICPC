/*
ID: flsnnx1
LANG: C
TASK: crypt1
*/

#include <stdio.h>
#include <math.h>

char mask[10];
int total,buf[5];

int inmask(int num,int n)
{
	int a,b,c,d;
	a = num % 1000 / 100;
	b = num % 100 / 10;
	c = num % 10;
	d = num / 1000;
	if(n == 3)
		return mask[a] & mask[b] & mask[c];
	else return mask[a] & mask[b] & mask[c] & mask[d];
}

int megreint(int n)
{
	if(n == 1)
		return buf[0] * 100 + buf[1] * 10 + buf[2];
	else return buf[3] * 10 + buf[4];
}

void dfs(int n)
{
	if(n > 4)
	{
		int num1 = megreint(1),num2 = megreint(2);
		if(num1 * num2 < 10000 && inmask(num1 * num2,4))
			total++;
		return;
	}
	int i;
	for(i = 1;i <= 9;i++)
	{
		if(mask[i] == 0) continue;
		buf[n] = i;
		if(n == 3 || n == 4)
		{
			int num1 = megreint(1),num2 = buf[n];
			if(!(num1 * num2 < 1000 && inmask(num1 * num2,3)))
				continue;
		}
		dfs(n + 1);
	}
}

int main()
{
	FILE *fin = fopen("crypt1.in","r"),*fout = fopen("crypt1.out","w");
	int n,i;
	fscanf(fin,"%d",&n);
	for(i = 0;i < n;i++)
	{
		int t;
		fscanf(fin,"%d",&t);
		mask[t] = 1;
	}
	dfs(0);
	fprintf(fout,"%d\n",total);
	return 0;
}

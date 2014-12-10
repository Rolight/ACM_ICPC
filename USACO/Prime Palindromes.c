/*
ID: flsnnx1
LANG: C
TASK: pprime
*/

#include <stdio.h>
#include <math.h>
#include <memory.h>

int num[10],a,b,flag = 0;
FILE *in,*out;

int combine(int n)
{
	int i,ans = 0;
	for(i = 1;i < n;i++)
	{
		ans += num[i];
		ans *= 10;
	}
	ans += num[n];
	if(ans > b) flag = 1;
	return ans;
}

int ifprime(int n)
{
	int i;
	for(i = 2;i <= sqrt(n);i++)
		if(n % i == 0)
			return 0;
	return 1;
}

int ifin(int n)
{
	if(n <= b && n >= a) return 1;
	else return 0;
}

void nummaker(int now,int n)
{
	if(flag) return;
	if(((n & 1) == 1) && (now == n / 2 + 2))
	{
		int ans = combine(n);
		if(ifprime(ans) && ifin(ans))
			fprintf(out,"%d\n",ans);
		return;
	}
	if(((n & 1) == 0) && (now == n / 2 + 1))
	{
		int ans = combine(n);
		if(ifprime(ans) && ifin(ans))
			fprintf(out,"%d\n",ans);
		return;
	}
	int i;
	for(i = 0;i <= 9;i++)
	{
		if(now == 1)
			if(i == 0 || ((i & 1) == 0))
				continue;
		num[now] = i;
		num[n - now + 1] = i;
		nummaker(now + 1,n);
	}
}

int main()
{
	in = fopen("pprime.in","r");
	out = fopen("pprime.out","w");
	fscanf(in,"%d%d",&a,&b);
	int min = log10(a) + 1,max = log10(b) + 1;
	int i;
	for(i = min;i <= max;i++)
	{
		nummaker(1,i);
		memset(num,0,sizeof(num));
	}
	return 0;
}

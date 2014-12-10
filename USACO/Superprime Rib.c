/*
ID: flsnnx1
LANG: C
TASK: sprime
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#define LOG(a)  (log10(a) + 1)
#define LIST 1000000

char *prime,N,num[10];
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
	return ans;
}

int ifprime(int n)
{
	if(LOG(n) <= 6) return prime[n];
	int i;
	for(i = 2;i <= sqrt(n);i++)
		if(n % i == 0)
			return 0;
	return 1;
}

void makeplist()
{
	int i,j;
	prime[1] = 0;
	for(i = 2;i <= sqrt(LIST);i++)
		for(j = i * 2;j <= (LIST);j += i)
			prime[j] = 0;
}


void makenum(int s)
{
	if(s == N + 1)
	{
		int ans = combine(s - 1);
		if(ifprime(ans))
			fprintf(out,"%d\n",ans);
		return;
	}
	int i;
	for(i = 1;i <= 9;i ++)
	{
		if(s == 1 && ifprime(i) == 0) continue;
		num[s] = i;
		if(s < N && ifprime(combine(s)) == 0) continue;
		makenum(s + 1);
	}
}

int main()
{
	
	prime = (char *)malloc(LIST * sizeof(char));
	memset(prime,1,LIST);
	makeplist();
	in = fopen("sprime.in","r"),out = fopen("sprime.out","w");
	int i;
	fscanf(in,"%d",&N);
	makenum(1);
	return 0;
}

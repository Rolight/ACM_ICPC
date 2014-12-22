/*
ID: flsnnx1
LANG: C
TASK: sort3
*/

#include <stdio.h>
#include <memory.h>

#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int c[4],f[n + 1][n + 1],data[n],swap = 0;
	memset(f,0,sizeof(f));
	memset(c,0,sizeof(c));
	for(i = 0;i < n;i++)
	{
		scanf("%d",&data[i]);
		c[data[i]]++;
	}

	for(i = 0;i < c[0];i++)
		f[0][data[i]]++;
	for(i = c[0];i < c[0] + c[1];i++)
		f[1][data[i]]++;
	for(i = c[0] + c[1];i < c[0] + c[1] + c[2];i++)
		f[2][data[i]]++;

	if(f[0][0] < c[0])
	{
		if(f[1][0] > 0 && f[0][1] > 0)
		{
			int t = MIN(f[1][0],f[0][1]);
			swap += t;
			f[1][0] -= t;
			f[0][1] -= t;
			f[1][1] += t;
			f[0][0] += t;
		}
		
	}

}

/*
ID: roll
LANG: C
TASK: combo
*/

#include <stdio.h>

int master[3],john[3],n,count = 0;

void readin()
{
	int i;
	FILE *in = fopen("combo.in","r");
	fscanf(in,"%d",&n);
	for(i = 0;i < 3;i++) fscanf(in,"%d",&master[i]);
	for(i = 0;i < 3;i++) fscanf(in,"%d",&john[i]);
}

int ifok(int a[3],int tar[3])
{
	int i,j,ok;
	for(i = 0;i < 3;i++)
	{
		ok = 0;
		for(j = -2;j <= 2 && !ok;j++)
		{
			int t = a[i];
			t += j;
			if(t < 1) t += n;
			if(t > n) t = t % n;
			if(t == tar[i]) ok = 1;
		}
		if(!ok) return 0;
	}
	return 1;
}

void work()
{
	FILE *out = fopen("combo.out","w");
	int a[3];
	for(a[0] = 1;a[0] <= n;a[0]++)
		for(a[1] = 1;a[1] <= n;a[1]++)
			for(a[2] = 1;a[2] <= n;a[2]++)
				if(ifok(a,master) || ifok(a,john))
					count++;
	fprintf(out,"%d\n",count);
}

int main()
{
	readin();
	work();
	return 0;
}

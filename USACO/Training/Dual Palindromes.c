/*
ID: flsnnx1
LANG: C
TASK: dualpal
*/

#include <stdio.h>

#include <stdlib.h>

struct mutil_base_number
{
	int data[300];
	int length;
	int base;
};

typedef struct mutil_base_number bnumber;

void setdata(int n,bnumber *bn)
{
	int length = 0,base = bn->base;
	while(n > 0)
	{
		bn->data[length++] = n % base;
		n = n / base;
	}
	bn->length = length;
}

int is_prlindormic(int num[],int length)
{
	int i;
	for(i = 0;i <= length / 2;i++)
		if(num[i] != num[length - i - 1])
			return 0;
	return 1;
}

void printnum(int num[],int length)
{
	int i;
	for(i = length - 1;i >= 0;i--)
	{
		if(num[i] < 10) printf("%d",num[i]);
		else printf("%c",num[i] - 10 + 'A');
	}
}

int main()
{
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);

	int count,std;
	scanf("%d%d",&count,&std);
	while(count > 0)
	{
		std++;
		int i,flag = 0;
		for(i = 2;i <= 10;i++)
		{
			if(flag == 2) break;
			bnumber *bn = (bnumber *)calloc(1,sizeof(bnumber));
			bn->base = i;
			setdata(std,bn);
			if(is_prlindormic(bn->data,bn->length))
				flag++;
			free(bn);
		}
		if(flag == 2)
		{
			printf("%d\n",std);
			count--;
		}
	}
	fclose(stdin);
	fclose(stdout);
}


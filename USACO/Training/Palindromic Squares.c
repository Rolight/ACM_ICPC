/*
ID: flsnnx1
LANG: C
TASK: palsquare
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
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	bnumber *bn = (bnumber *)calloc(1,sizeof(bnumber));
	bnumber *bp = (bnumber *)calloc(1,sizeof(bnumber));
	int base,i;
	scanf("%d",&base);
	bn->base = bp->base = base;
	for(i = 1;i <= 300;i++)
	{
		setdata(i * i,bp);
		if(is_prlindormic(bp->data,bp->length))
		{
			setdata(i,bn);
			printnum(bn->data,bn->length);
			printf(" ");
			printnum(bp->data,bp->length);
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

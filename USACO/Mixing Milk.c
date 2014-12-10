/*
ID: flsnnx1
LANG: C
TASK: milk
*/

#include <stdio.h>

#define SWAP(t,a,b) (t) = (a),(a) = (b),(b) = (t)

struct PAIR
{
	int val;
	int amount;
};

typedef struct PAIR pair;

void quicksort(int str,int end,pair *list);
void debug_printlist(pair *list,int len);
void swap(pair *a,pair *b);

int main()
{
	FILE *in = fopen("milk.in","r"),*out = fopen("milk.out","w");
	int need,people,i,ans = 0;
	fscanf(in,"%d%d",&need,&people);
	pair list[people];
	for(i = 0;i < people;i++) fscanf(in,"%d%d",&list[i].val,&list[i].amount);
	quicksort(0,people - 1,list);
	debug_printlist(list,people);
	i = 0;
	while(need > 0)
	{
		if(need > list[i].amount)
		{
			ans += list[i].amount * list[i].val;
			need -= list[i].amount;
		}
		else
		{
			ans += list[i].val * need;
			need = 0;
		}
		i++;
	}
	fprintf(out,"%d\n",ans);
	return 0;
}

void quicksort(int str,int end,pair *list)
{
	if(str >= end) return;
	int mid = (str + end) / 2,std = list[mid].val,i = str,j = end;
	while(1)
	{
		while(list[i].val < std) i++;
		while(list[j].val > std) j--;
		if(i < j)
		{
			swap(&list[i],&list[j]);
			i++;
			j--;
		}
		else break;
	}
	quicksort(str,i - 1,list);
	quicksort(j + 1,end,list);
}

void swap(pair *a,pair *b)
{
	int temp;
	SWAP(temp,a->val,b->val);
	SWAP(temp,a->amount,b->amount);
}

void debug_printlist(pair *list,int len)
{
	int i;
	for(i = 0;i < len;i++)
		printf("%d ",list[i].val);
	printf("\n");
}

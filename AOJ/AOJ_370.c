#include <stdio.h>

char have[21][21][21];

struct statect
{
	int bucket[3];
};

struct statect state[21 * 21 * 21];
int ans[21 * 21],limit[3],count = 0;

int pull(int *source,int *target,int lt)
{
	//printf("before %d %d\n",*source,*target);
	if(source == 0) return 0;
	int rem = lt - *target;
	int k = (*source < rem) ? *source : rem;
	*source -= k;
	*target += k;
	//printf("after %d %d \n",*source,*target);
	return 1;
}

void dfs(int bucket[3])
{
	int i,j;
	if(bucket[0] == 0) ans[count++] = bucket[2];
	if(have[bucket[0]][bucket[1]][bucket[2]] == 1) return;
	have[bucket[0]][bucket[1]][bucket[2]] = 1;
	for(i = 0;i < 3;i++)
		for(j = 0;j < 3;j++)
		{
			if(i == j) continue;
			int tbucket[3] = {bucket[0],bucket[1],bucket[2]};
			if(pull(&bucket[i],&bucket[j],limit[j]))
				dfs(bucket);
			int k;
			for(k = 0;k < 3;k++) bucket[k] = tbucket[k];
		}
}

void qsort(int str,int end)
{
	if(str >= end) return;
	int mid = (str + end) / 2,i = str,j = end;
	int key = ans[mid];
	while(1)	
	{
		while(ans[i] < key) i++;
		while(ans[j] > key) j--;
		if(i < j)
		{
			int t = ans[i];
			ans[i] = ans[j];
			ans[j] = t;
			i++;
			j--;
		}
		else break;
	}
	qsort(str,i - 1);
	qsort(j + 1,end);
}

int main()
{
	scanf("%d%d%d",&limit[0],&limit[1],&limit[2]);
	dfs((int[3]){0,0,limit[2]});
	int i;
	qsort(0,count - 1);
	int tans[21],j = 0;
	for(i = 0;i < count;i++)
		if (i == 0 || ans[i] != ans[i - 1]) 
			tans[j++] = ans[i];
	for(i = 0;i < j;i++)
	{
		printf("%d",tans[i]);
		if(i != j - 1) printf(" ");
	}
	printf("\n");
	return 0;
}

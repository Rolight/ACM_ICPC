/*
ID: flsnnx1
LANG: C
TASK: checker
*/

#include <stdio.h>

#define MAX 14

int N,b[MAX][MAX],ans[MAX],count = 0;

inline void set(int x,int y)
{
	b[x][y]++;
}

inline void unset(int x,int y)
{
	b[x][y]--;
}
inline int unput(int x,int y)
{
	unset(x,y);
	//rows
	int i,j;
	for(i = 1;i <= N;i++)
	{
		unset(x,i);
		unset(i,y);
	}
	set(x,y);
	//dig
	i = x - 1;
	j = y - 1;
	while(i >= 1 && j >= 1)
	{
		unset(i,j);
		i--;
		j--;
	}
	i = x - 1;
	j = y + 1;
	while(i >= 1 && j <= N)
	{
		unset(i,j);
		i--;
		j++;
	}
	i = x + 1;
	j = y + 1;
	while(i <= N && j <= N)
	{
		unset(i,j);
		i++;
		j++;
	}
	i = x + 1;
	j = y - 1;
	while(i <= N && j >= 0)
	{
		unset(i,j);
		i++;
		j--;
	}
	return 0;
}
inline int put(int x,int y)
{
	if(b[x][y] == 0) set(x,y);
	else return 0;
	//rows
	int i,j;
	for(i = 1;i <= N;i++)
	{
		set(x,i);
		set(i,y);
	}
	unset(x,y);
	//dig
	i = x - 1;
	j = y - 1;
	while(i >= 1 && j >= 1)
	{
		set(i,j);
		i--;
		j--;
	}
	i = x - 1;
	j = y + 1;
	while(i >= 1 && j <= N)
	{
		set(i,j);
		i--;
		j++;
	}
	i = x + 1;
	j = y + 1;
	while(i <= N && j <= N)
	{
		set(i,j);
		i++;
		j++;
	}
	i = x + 1;
	j = y - 1;
	while(i <= N && j >= 0)
	{
		set(i,j);
		i++;
		j--;
	}
	return 1;
}

void search(int row)
{
	if(row == N + 1)
	{
		int i;
		count++;
		if(count > 3) return;
		for(i = 1;i <= N;i++)
			printf("%d ",ans[i]);
		printf("\n");
		return;
	}
	
	int i;
	for(i = 1;i <= N;i++)
	{
		if(put(row,i))
		{
			ans[row] = i;
			search(row + 1);
			unput(row,i);
		}
	}
}

int main()
{
	scanf("%d",&N);
	search(1);
	printf("%d\n",count);
	return 0;
}

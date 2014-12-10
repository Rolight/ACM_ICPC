#include <iostream>
#include <cstdio>

using namespace std;

int find(int *a,int n,int tar)
{
	int str = 0,end = n;
	while(str <= end)
	{
		int mid = (str + end) / 2;
		if(a[mid] == tar) return 1;
		else if(a[mid] < tar) str = mid + 1;
		else end = mid - 1;
	}
	return 0;
}

void quicksort(int str,int end,int *a)
{
	if(str >= end) return;
	int mid = (str + end) / 2,i = str,j = end,std = a[mid];
	while(1)
	{
		while(a[i] < std) i++;
		while(a[j] > std) j--;
		if(i < j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
		else break;
	}
	quicksort(str,i - 1,a);
	quicksort(j + 1,end,a);
}

int main()
{
	char eg[1000];
	int n,a[500],count = 1,flag = 0;
	scanf("%d",&n);
	int min = 500;
	for(int i = 0;i < n;i++) cin >> a[i];
	quicksort(0,n - 1,a);
	for(int i = 0;i <= 100;i++) if(!find(a,n,i))
	{
		cout << i << endl;
		break;
	}
	return 0;
}

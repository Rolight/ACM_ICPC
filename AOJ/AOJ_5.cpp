#include <iostream>

using namespace std;

int my[1001],his[1001];

void qs(int str,int end,int *a)
{
	if(str >= end) return;
	int mid = (str + end) / 2,std = a[mid],i = str,j = end;
	while(i < j)
	{
		while(a[i] < std) i++;
		while(a[j] > std) j--;
		if(i < j)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	}
	qs(str,i - 1,a);
	qs(j + 1,end,a);
}

int main()
{
	int n;
	while(cin >> n && n != 0)
	{
		int count = 0,pos = 0;
		for(int i = 0;i < n;i++) cin >> my[i];
		for(int i = 0;i < n;i++) cin >> his[i];
		qs(0,n - 1,my);
		qs(0,n - 1,his);
		for(int i = 0;i < n;i++)
		{
			if(his[pos] < my[i])
			{
				count++;
				pos++;
			}
		}
		if(count > n / 2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

#include <iostream>

using namespace std;

void quicksort(int str,int end,int *a)
{
	if(str >= end) return;
	int std = a[(str + end) / 2],i = str,j = end;
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
		}else break;
	}
	quicksort(str,i - 1,a);
	quicksort(j + 1,end,a);
}

int main()
{
	int n,a[10001],count = 0;
	while(cin >> n && n != 0)
	{
		for(int i = 0;i < n;i++) cin >> a[i];
		quicksort(0,n - 1,a);
		int ans = 0;
		for(int i = 0,str = a[0];i < n;i++,str++)
			if(a[i] != str)
			{
				ans = 1;
				break;
			}
		cout << "Case " << ++count << ":" << endl;
		if(ans) cout << "M" << endl;
		else cout << "S" << endl;
	}
	return 0;
}

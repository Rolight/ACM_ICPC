#include <iostream>

using namespace std;

int main()
{
	int T,n,temp,a[10001];
	cin >> T;
	for(int i = 0;i < T;i++)
	{
		int count = 0;
		cin >> n;
		for(int j = 0;j < n;j++)
		{
			cin >> temp;
			a[j] = temp % 3;
		}
		for(int j = 0;j < n;j++)
			for(int k = j + 1;k < n;k++) if(a[k] >= 0 && a[j] >= 0) 
				if(a[j] + a[k] == 3 || a[j] + a[k] == 0)
				{
					count++;
					a[j] = a[k] = -1;
					break;
				}
		cout << count << endl;
	}
	return 0;
}

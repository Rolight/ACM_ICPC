#include <iostream>

using namespace std;

int T,n,a[10001];

int main()
{
	cin >> T;
	for(int i = 0;i < T;i++)
	{
		int odd = 0,nodd = 0,posodd,posnodd;
		cin >> n;
		for(int j = 0;j < n;j++)
		{
			cin >> a[j];
			if(a[j] % 2 == 0) 
			{
				nodd++;
				posnodd = j;
			}
			else
			{
				odd++;
				posodd = j;
			}
		}
		if(odd == 1) cout << posodd + 1 << endl;
		else cout << posnodd + 1 << endl;
	}
	return 0;
}

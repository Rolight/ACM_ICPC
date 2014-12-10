#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull a[100];

int main()
{
	int n;
	a[0] = 1;
	a[1] = 1;
	while(cin >> n && n != 0)
	{
		for(int i = 2;i <= n;i++) if(a[i] == 0)
		 	a[i] = a[i - 1] + a[i - 2];
		cout << a[n] << endl;
	}
	return 0;
}

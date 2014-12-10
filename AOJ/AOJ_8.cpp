#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main()
{
	int n;
	while(cin >> n && n != 0)
	{
		unsigned int a[n + 1];
		a[0] = 0;a[1] = 1;a[2] = 2;
		for(int i = 3;i <= n;i++) a[i] = a[i - 1] + a[i - 2];
		cout << a[n] << endl;
	}
	return 0;
}

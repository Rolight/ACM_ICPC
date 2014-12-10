#include <iostream>

using namespace std;

int main()
{
	long long a = 1,b = 1;
	int n;
	cin >> n;
	for(int i = 3;i <= n;i++)
	{
		a = a + b;
		b = (a - b);
	}
	cout << a << endl;
	return 0;
}

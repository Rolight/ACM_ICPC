#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main()
{
	ull ans,a1,n,d;
	cin >> a1 >> n >> d;
	cout << (a1 + (a1 + (n - 1) * d)) * n / 2 << endl;
	return 0;
}

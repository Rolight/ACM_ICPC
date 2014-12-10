#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n,m;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> m;
		printf("%.6f\n",2.0 / (double)m / (m - 1));
	}
	return 0;
}

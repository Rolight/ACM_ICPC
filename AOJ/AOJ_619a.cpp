#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	string eg;
	int n,a[500];
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i <= 100;i++) if(count(a,a + n,i) == 0)
	{
		cout << i << endl;
		break;
	}
	return 0;
}

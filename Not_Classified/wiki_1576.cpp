#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n],f[n],ans = -1;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		f[i] = 1;
	}
	for(int i = 1;i < n;i++)
	{
		for(int j = i - 1;j >= 0;j--) if(a[j] < a[i]) f[i] = (f[i] > f[j] + 1) ? f[i] : f[j] + 1;
		if(f[i] > ans) ans = f[i];
	}
	cout << ans << endl;
	return 0;
}

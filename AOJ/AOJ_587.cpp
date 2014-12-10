#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a,int b)
{
	return a < b;
}

int main()
{
	int T,n,m,a[10020];
	cin >> T;
	for(int i = 0;i < T;i++)
	{
		int ans = 0;
		cin >> n >> m;
		for(int j = 0;j < n;j++) cin >> a[j];
		sort(a,a + n,cmp);
		for(int j = 0;j < m;j++)
		{
			if(a[j] < 0) ans -= a[j];
			else break;
		}
		cout << ans << endl;
	}
	return 0;
}

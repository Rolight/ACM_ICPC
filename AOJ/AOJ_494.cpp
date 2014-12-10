#include <iostream>

using namespace std;

int main()
{
	int a[4];
	while(1)
	{
		int sum = 0,ans = 1;
		for(int i = 0;i < 4;i++)
		{
			cin >> a[i];
			sum += a[i];
			if(i && a[i - 1] == a[i] + 1 && ans == 1) ans = i + 1;
		}
		if(!sum) break;
		else cout << ans << endl;
	}
	return 0;
}

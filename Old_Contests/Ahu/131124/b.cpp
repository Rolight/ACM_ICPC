#include <iostream>
#include <algorithm>

using namespace std;

long long a[100002],n;

void readin()
{
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
}

void work()
{
	int ans = 2,front = 0,next = 1,count = 2;
	for(int i = 2;i < n;i++)
	{
		if(a[i] == a[i - 1] + a[i - 2]) count++;
		else count = 2;
		if(count > ans) ans = count;
	}
	if(n == 1) cout << 1 << endl;
	else cout << ans << endl;
}

int main()
{
	readin();
	work();
	return 0;
}

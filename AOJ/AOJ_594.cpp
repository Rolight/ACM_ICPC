#include <iostream>

using namespace std;

int main()
{
	int T,n,d[500],str,end;
	cin >> T;
	for(int i = 0;i < T;i++)
	{
		int ans = 0;
		cin >> n;
		for(int j = 1;j < n;j++) cin >> d[j];
		cin >> str >> end;
		for(int j = str;j < end;j++) ans += d[j];
		cout << ans << endl;
	}
	return 0;
}

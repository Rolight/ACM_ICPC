#include <iostream>

using namespace std;

int main()
{
	int n,u,d;
	while(cin >> n >> u >> d && n != 0)
	{
		int time = 0;
		while(n > 0)
		{
			if(time % 2 == 0) n -= u;
			else n += d;
			time++;
		}
		cout << time << endl;
	}
	return 0;
}

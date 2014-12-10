#include <iostream>

using namespace std;

int main()
{
	int m;
	cin >> m;
	for(int i = 0;i < m;i++)
	{
		int mhp,mdps,yhp,ydps;
		cin >> mhp >> mdps >> yhp >> ydps;
		while(mhp * yhp > 0)
		{
			mhp -= ydps;
			yhp -= mdps;
		}
		if(mhp <= 0) cout << "Run away!" << endl;
		else cout << "Kill him!" << endl;
	}
	return 0;
}

#include <iostream>

using namespace std;

int pt(int a)
{
return (a < 0) ? -a : a;
}

int main()
{
	int m;
	cin >> m;
	for(int i = 0;i < m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if(a < (b + c) && a > pt(b - c)) cout << a + b + c << endl;
		else cout << "Wrong" << endl;
	}
	return 0;
}

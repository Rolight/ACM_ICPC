#include <iostream>

using namespace std;

typedef unsigned int uint;

int main()
{
	long long head,feet;
	while(cin >> head >> feet && head != 0)
	{
		long long bird = 0,ribb = 0,n = head,m = feet;
		m = 4 * n - m;
		if(m < 0 || m % 2 != 0 || n - m / 2 < 0) cout << "Error" << endl;
		else cout << m / 2 << " " << n - m / 2 << endl;	
	}
	return 0;
}

#include <iostream>

#define dismove(n,a,b) (cout << n << " from " << (a) << " to " << (b) << endl)

using namespace std;

void hano(int n,char src,char mid,char tar)
{
	if(n == 1) dismove(n,src,tar);
	else
	{
		hano(n - 1,src,tar,mid);
		dismove(n,src,tar);
		hano(n - 1,mid,src,tar);
	}
}

int main()
{
	int n;
	cin >> n;
	cout << (1 << n) - 1 << endl;
	hano(n,'A','B','C');
	return 0;
}

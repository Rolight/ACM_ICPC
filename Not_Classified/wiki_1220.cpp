#include <iostream>

using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))

int n,b[102][102];

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= i;j++)
			cin >> b[i][j];
	for(int i = n - 1;i >= 1;i--)
		for(int j = 1;j <= i;j++) 
			b[i][j] += max(b[i + 1][j],b[i + 1][j + 1]);
	cout << b[1][1] << endl;
	return 0;
}

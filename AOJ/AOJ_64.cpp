#include <iostream>
#include <cstdio>

#define max(a,b) ((a > b) ? a : b)

using namespace std;

int a[200][200];

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		for(int j = 0;j <= i;j++)
			cin >> a[i][j];
	for(int i = n - 2;i >= 0;i--)
		for(int j = 0;j <= i;j++)
			a[i][j] += max(a[i + 1][j],a[i + 1][j + 1]);
	cout << a[0][0] << endl;
	return 0;
}

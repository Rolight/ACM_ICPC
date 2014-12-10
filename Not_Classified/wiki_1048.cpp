#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 105
#define min(a,b) ((a) < (b) ? (a) : (b))

int f[maxn][maxn],s[maxn][maxn],w[maxn],n;

void read()
{
	cin >> n;
	for(int i = 1;i <= n;i++) 
		cin >> w[i];
}

void dp()
{
	for(int i = 1;i <= n;i++) 
	{
		s[i][i]  = w[i];
		f[i][0] = 0;
	}
	for(int i = 1;i <= n;i++)
		for(int j = i + 1;j <= n;j++)
			s[i][j] = s[i][j - 1] + w[j];
	for(int i = 1;i < n;i++)
	{
		for(int j = 1;i + j <= n;j++)
		{
			// f(i,j)  表示从i开始往后j个
			f[j][i] = f[j][0] + f[j + 1][i - 1] + s[j][j] + s[j + 1][j + i];
			for(int k = 1;k < i;k++) 
				f[j][i] = min(f[j][i],f[j][k] + f[j + k + 1][i - k - 1] + s[j][j + k] + s[j + k + 1][i + j]);
		}
	}
}

void out()
{
	cout << f[1][n - 1] << endl;
}

int main()
{
	read();
	dp();
	out();
	return 0;
}

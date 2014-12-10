#include <iostream>

#define maxn 55
#define max2(a,b) ((a) > (b) ? (a) : (b))
#define max(a,b,c,d) max2((max2(a,b)),(max2(c,d)))

using namespace std;

int m,n,s[maxn][maxn],ans,now,f[maxn * 2][maxn][maxn];
bool vis[maxn][maxn];

void readin()
{
	cin >> m >> n;
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++)
			cin >> s[i][j];
}

void dp()
{
	for(int step = 1;step < m + n;step++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++) if(i != j)
				f[step][i][j] = 
					max(f[step - 1][i][j],f[step - 1][i - 1][j],f[step - 1][i][j - 1],f[step - 1][i - 1][j - 1])
						+ s[step - i + 1][i] + s[step - j + 1][j];
	f[m + n - 1][n][n] = max(0,f[m + n - 2][n - 1][n],
								f[m + n - 2][n][n - 1],
								f[m + n - 2][n - 1][n - 1]);
	cout << f[m + n - 1][n][n] << endl;
}


int main()
{
	readin();
	dp();
	return 0;
}

#include <iostream>
#include <cstdio>

#define maxn 30

using namespace std;

int b[maxn][maxn],n,m,X,Y;

void readin()
{
	cin >> n >> m >> X >> Y;
}

bool ifin(int sx,int sy)
{
	return (sx >= 0 && sx <= n && sy >= 0 && sy <= m);
}

void set()
{
	int py[9] = {0,1,2,2,1,-1,-2,-2,-1},px[9] = {0,2,1,-1,-2,-2,-1,1,2};
	int min = -2100000000;
	for(int i = 0;i < 9;i++) if(ifin(X + px[i],Y + py[i])) b[X + px[i]][Y + py[i]] = min;
}

void work()
{
	b[0][0] =  1;
	for(int i = 0;i <= n;i++)
		for(int j = 0;j <= m;j++)
		{
			if(ifin(i,j - 1) && b[i][j - 1] > 0) b[i][j] += b[i][j - 1];
			if(ifin(i - 1,j) && b[i - 1][j] > 0) b[i][j] += b[i - 1][j];
		}
	cout << b[n][m] << endl;
}

int main()
{
	readin();
	set();
	work();
	return 0;
}

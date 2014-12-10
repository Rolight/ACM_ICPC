#include <iostream>
#include <cstdio>

#define max(a,b) ((a > b) ? a : b)

using namespace std;

int a[200][200],d[200][200],n;

int dfs(int x,int y)
{
	if(d[x][y] != 0) return d[x][y];
	if(x == n - 1) return a[x][y];
	else return d[x][y] = max(dfs(x + 1,y),dfs(x + 1,y + 1)) + a[x][y];
}

int main()
{
	freopen("in.txt","r",stdin);
	cin >> n;
	for(int i = 0;i < n;i++)
		for(int j = 0;j <= i;j++)
			cin >> a[i][j];
	cout << dfs(0,0) << endl;
	return 0;
}

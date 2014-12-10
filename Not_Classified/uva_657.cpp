#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char graph[52][52];
bool vis[52][52],visx[52][52];
void dfsx(int x,int y)
{
	if(visx[x][y] || graph[x][y] != 'X') return;
	visx[x][y] = true;
	dfsx(x - 1,y);dfsx(x + 1,y);
	dfsx(x,y - 1);dfsx(x,y + 1);
}
void dfs(int x,int y,int& num)
{
	if(vis[x][y] || graph[x][y] == '.' || graph[x][y] == 0) return;
	if(graph[x][y] == 'X' && visx[x][y] == false) 
	{
		dfsx(x,y);
		num++;
	}
	vis[x][y] = true;
	dfs(x - 1,y,num);dfs(x + 1,y,num);
	dfs(x,y - 1,num);dfs(x,y + 1,num);
}

bool cmp(int a,int b)
{
	return (a < b);
}

int main()
{
	int w,h,now = 0;
	while((cin >> w >> h))
	{
		if(w == 0 || h == 0)
			break;
		memset(graph,0,sizeof(graph));
		for(int i = 1;i <= h;i++)
			for(int j = 1;j <= w;j++)
			{
				cin >> graph[i][j];
				vis[i][j] = false;
				visx[i][j] = false;
			}
		int number[52],numbercount = 0;
		memset(number,0,sizeof(number));
		for(int i = 1;i <= h;i++)
			for(int j = 1;j <= w;j++)
			{
				if(vis[i][j] == false && graph[i][j] != '.')
				{
					dfs(i,j,number[numbercount]);
					numbercount++;
				}
			}
		sort(number,number + numbercount,cmp);
		cout << "Throw " << ++now << endl;
		for(int i = 0;i < numbercount;i++)
		{
		   	cout << number[i];
			if(i != numbercount - 1) cout << " ";
		}
		cout << endl << endl;
	}
}

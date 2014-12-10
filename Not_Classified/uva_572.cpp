#include <iostream>
#include <cstring>

using namespace std;

int graph[102][102];
char vis[102][102];

void dfs(int x,int y)
{
	if(graph[x][y] == 0 || vis[x][y]) return;
	vis[x][y] = 1;
	dfs(x - 1,y); dfs(x + 1,y); 
	dfs(x,y - 1); dfs(x,y + 1);
	dfs(x + 1,y + 1); dfs(x - 1,y - 1); 
	dfs(x + 1,y - 1); dfs(x - 1,y + 1);
}

int main()
{
	int m,n;
	while((cin >> m >> n) && m && n)
	{
		memset(graph,0,sizeof(graph));
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= m;i++)
			for(int j = 1;j <= n;j++)
			{
				char t;
				cin >> t;
				graph[i][j] = (t == '@');
			}
		int count = 0;
		for(int i = 1;i <= m;i++)
			for(int j = 1;j <= n;j++)
			{
				if(!vis[i][j] && graph[i][j])
				{
					dfs(i,j);
					count++;
				}	
			}
		cout << count << endl;
	}
	return 0;
}

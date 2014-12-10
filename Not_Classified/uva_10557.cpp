#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

bool canwin = false;
int n;

struct gt
{
	int power,degree,edge[200];
}g[200];

void dfs(int now,int power)
{
	if(now == n && power > 0) canwin = true;
	if(power > n * 100) canwin = true;
	for(int i = 1;i <= g[now].degree;i++) if(!canwin)
		if(power - g[g[now].edge[i]].power > 0)
			dfs(g[now].edge[i],power + g[g[now].edge[i]].power);
}

int main()
{
	freopen("in.txt","r",stdin);
	while(cin >> n && n != -1)
	{
		memset(g,0,sizeof(g));
		for(int i = 1;i <= n;i++)
		{
			cin >> g[i].power >> g[i].degree;
			for(int j = 1;j <= g[i].degree;j++)
				cin >> g[i].edge[j];
		}
		canwin = false;
		dfs(1,100);
		if(canwin) cout << "winnable" << endl;
		else cout << "hopeless" << endl;
	}
	return 0;
}


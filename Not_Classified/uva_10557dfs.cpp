#include <iostream>
#include <cstdio>
#include <cstring>

#define IMP (1<<30)

using namespace std;

struct gt
{
	int deg,edge[200],power,lastpower;
}room[200];

int n,ok,vis[200];

int dfs1(int r)
{
	if(r == n) return 1;
	else
	{
		int ans = 0;
		vis[r] = 1;
		for(int i = 0;i < room[r].deg;i++) 
			if(!vis[room[r].edge[i]]) 
			{
				ans = dfs1(room[r].edge[i]);
				if(ans) break;
			}
		return ans;
	}
}

void dfs(int r,int p)
{
	//cout << r << " " << p << endl;
	if(p < 0) return;
	if(p > 0 && r == n) ok = 1;
	if(room[r].lastpower != -IMP && p > room[r].lastpower) 
	{
		memset(vis,0,sizeof(vis));
		if(dfs1(r)) ok = 1;
		else room[r].lastpower = IMP;
	}
	if(room[r].lastpower != -IMP && p <= room[r].lastpower) return;
	if(ok == 1) return;
	if(room[r].lastpower == -IMP) room[r].lastpower = p;
	for(int i = 0;i < room[r].deg;i++) dfs(room[r].edge[i],p + room[room[r].edge[i]].power);
}

int main()
{
	freopen("in.txt","r",stdin);
	while(cin >> n && n != -1)
	{
		memset(room,0,sizeof(room));
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= n;i++)
		{
			cin >> room[i].power >> room[i].deg;
			for(int j = 0;j < room[i].deg;j++) 
				cin >> room[i].edge[j];
			room[i].lastpower = -IMP;
		}
		ok = dfs1(1);
		if(ok) 
		{
			ok = 0;
			dfs(1,100);
		}
		if(ok) cout << "winnable" << endl;
		else cout << "hopeless" << endl;
	}
	return 0;
}

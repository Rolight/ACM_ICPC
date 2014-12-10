#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int g[200][200],n,cost[200],note[400000],pnote[400000];

bool bfs()
{
	int front = 0,rear = 1;
	note[front] = 1;
	pnote[front] = 100;
	while(front < rear)
	{
		if(note[front % 400000] == n) return true;
		if(pnote[front % 400000] > n * 100)
		{
			front++;
			continue;
		}
		for(int i = 1;i <= n;i++) 
		{
			if(g[note[front % 400000]][i] && pnote[front % 400000] + cost[i] > 0)
			{
				note[rear % 400000] = i;
				pnote[rear % 400000] = pnote[front % 400000] + cost[i];
				rear++;
			}			
		}
		front++;
	}
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	while(cin >> n && n != -1)
	{
		memset(g,0,sizeof(g));
		int count,to;
		for(int i = 1;i <= n;i++)
		{
			cin >> cost[i];
			cin >> count;
			for(int j = 0;j < count;j++)
			{
				cin >> to;
				g[i][to] = 1;
			}
		}
		if(bfs()) cout << "winnable" << endl;
		else cout << "hopeless" << endl;
	}
	return 0;
}

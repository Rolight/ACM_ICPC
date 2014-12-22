/*
ID: flsnnx1
LANG: C++
TASK: castle 
*/

#include <iostream>
#include <cstring>
#include <cstdio>

#define pos(x,y) ((x-1)*col+y)

using namespace std;

struct room
{
	int nei[4];	//left up right down
};

int row,col,size,rsize[3000];
room r[3000];
int vis[3000];

void fill(int now,int val)
{
	if(rsize[now]) return;
	rsize[now] = val;
	for(int i = 0;i < 4;i++) if(r[now].nei[i]){
		fill(r[now].nei[i],val);
	}
}

void dfs(int now,int val)
{
	if(vis[now]) return;
	vis[now] = val;
	size++;
	for(int i = 0;i < 4;i++) if(r[now].nei[i]) {
		dfs(r[now].nei[i],val);
	}
}

void dis()
{
	for(int i = 0;i <= row + 1;i++)
	{
		for(int j = 0;j <= col + 1;j++)
		{
			cout << vis[pos(i,j)];
		}
		cout << endl;
	}
}

int main()
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	memset(r,0,sizeof(r));
	cin >> col >> row;
	for(int i = 1;i <= row;i++)
	{
		for(int j = 1;j <= col;j++)
		{
			int state;
			cin >> state;
			if(!(state & 1)) r[pos(i,j)].nei[0] = pos(i,j - 1);
			if(!(state & 2)) r[pos(i,j)].nei[1] = pos(i - 1,j);
			if(!(state & 4)) r[pos(i,j)].nei[2] = pos(i,j + 1);
			if(!(state & 8)) r[pos(i,j)].nei[3] = pos(i + 1,j);
		}
	}
	int count = 0,maxsize = 0,rx,ry;
	char rw;
	for(int i = 1;i <= row * col;i++) if(!vis[i])
	{
		size = 0;
		dfs(i,count + 1);
		count++;
		fill(i,size);
		if(size > maxsize)
		{
			maxsize = size;
		}
	}
	cout << count << endl << maxsize << endl;
	//dis();
	for(int j = 1;j <= col;j++)
	{
		for(int i = row;i > 0;i--)
		{
			int dx[4] = {0,-1,0,1},dy[4] = {-1,0,1,0};
			char cd[4] = {'W','N','E','S'};
			for(int k = 0;k < 4;k++) if(i + dx[k] > 0 && i + dx[k] <= row && j + dy[k] > 0 && j + dy[k] <= col && vis[pos(i,j)] != vis[pos(i + dx[k],j + dy[k])] && rsize[pos(i,j)] + rsize[pos(i + dx[k],j + dy[k])] > maxsize)
			{
				maxsize = rsize[pos(i,j)] + rsize[pos(i + dx[k],j + dy[k])];
				rx = i; ry = j;
				rw = cd[k];
			}
		}
	}
	cout << maxsize << endl << rx << " " << ry << " " << rw << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

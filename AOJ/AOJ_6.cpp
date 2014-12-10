#include <stdio.h>
#include <string.h>

#define SIZE 25
#define WALL -1
#define EMPTY 1000000

int maze[SIZE][SIZE],movex[4] = {
	1,-1,0,0
},movey[4] = {
	0,0,1,-1
};
int nx[10000],ny[10000];

void bfs(int sx,int sy)
{
	int front = 0,rear = 1;
	nx[0] = sx;
	ny[0] = sy;
	maze[sx][sy] = 0;
	while(front < rear)
	{
		int i;
		for(i = 0;i < 4;i++)
		{
			int newx = nx[front] + movex[i],newy = ny[front] + movey[i];
			if(maze[newx][newy] != WALL && maze[nx[front]][ny[front]] + 1 < maze[newx][newy])
			{
				maze[newx][newy] = maze[nx[front]][ny[front]] + 1;
				nx[rear] = newx;
				ny[rear] = newy;
				rear++;
			}
		}
		front++;
	}
}


int main()
{
	freopen("in.txt","r",stdin);
	int px,py,sx,sy,row,col,time,i,j;
	while(scanf("%d%d%d",&row,&col,&time) && row != 0)
	{
		getchar();
		memset(maze,WALL,sizeof(maze));
		for(i = 1;i <= row;i++)
		{
			for(j = 1;j <= col;j++)
			{
				char temp;
				scanf("%c",&temp);
				if(temp == '*') maze[i][j] = WALL;
				else maze[i][j] = EMPTY;
				if(temp == 'S') sx = i,sy = j;
				if(temp == 'P') px = i,py = j;
			}
			getchar();
		}
		bfs(sx,sy);
		int ans = maze[px][py];
		if(ans <= time) puts("YES");
		else puts("NO");
	}
	return 0;
}

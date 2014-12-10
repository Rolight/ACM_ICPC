#include <iostream>
#include <cstring>
#include <cstdio>

#define SIZE 40
#define NSIZE 40 * 40 * 40
#define WALL  -1
#define EMPTY NSIZE

using namespace std;

int dig[SIZE][SIZE][SIZE],level,row,col;
int nx[NSIZE],ny[NSIZE],nz[NSIZE];
int movex[6] = {-1,1,0,0,0,0},movey[6] = {0,0,-1,1,0,0},movez[6] = {0,0,0,0,1,-1};

void bfs(int startx,int starty,int startz)
{
	int front = 0,rear = 1;
	nx[0] = startx;
	ny[0] = starty;
	nz[0] = startz;
	dig[startx][starty][startz] = 0;
	while(front < rear)
	{
		for(int i = 0;i < 6;i++)
		{
			int newx = nx[front] + movex[i],newy = ny[front] + movey[i],newz = nz[front] + movez[i];
			if(dig[newx][newy][newz] != WALL && dig[newx][newy][newz] > dig[nx[front]][ny[front]][nz[front]] + 1)
			{
				dig[newx][newy][newz] = dig[nx[front]][ny[front]][nz[front]] + 1;
				nx[rear] = newx;
				ny[rear] = newy;
				nz[rear] = newz;
				rear++;
			}
		}
		front++;
	}
}

void printpic()
{
	/*
	for(int z = 1;z <= level;z++)
	{
		for(int x = 1;x <= row;x++)
		{
			for(int y  = 1;y <= col;y++)
			{
				if(dig[x][y][z] < 0) putchar('#');
				else if(dig[x][y][z] == NSIZE) putchar('?');
				else printf("%d",dig[x][y][z]);
			}
			printf("\n");
		}
		printf("\n");
	}
	*/
}

int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&level,&row,&col) && level != 0)
	{
		getchar();
		memset(dig,WALL,sizeof(dig));
		char t;
		int sx,sy,sz,ex,ey,ez;
		for(int z = 1;z <= level;z++)
		{
			for(int x = 1;x <= row;x++)
			{
				for(int y = 1;y <= col;y++)
				{
					scanf("%c",&t);
					if(t == '#') dig[x][y][z] = WALL;
					else dig[x][y][z] = EMPTY;
					if(t == 'S') 
					{
						sx = x;
						sy = y;
						sz = z;
					}
					if(t == 'E')
					{
						ex = x;
						ey = y;
						ez = z;
					}
				}
				getchar();
			}
			getchar();
		}
		printpic();
		bfs(sx,sy,sz);
		int ans = dig[ex][ey][ez];
		if(ans != NSIZE) printf("Escaped in %d minute(s).\n",ans);
		else printf("Trapped!\n");
	}
	return 0;
}

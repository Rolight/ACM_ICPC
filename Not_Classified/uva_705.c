#include <stdio.h>
#include <string.h>

#define LEFT 0
#define RIGHT 1
#define OUT -1
#define EMPTY 2
#define VIS 3
#define SIZE 200

int w,h,cyc,g[SIZE][SIZE],flag,num,max;

void ff(int x,int y)
{
	if(g[x][y] == OUT) flag = 0;
	if(g[x][y] != EMPTY) return;
	num++;
	g[x][y] = VIS;
	ff(x - 1,y); ff(x + 1,y); ff(x,y - 1);ff(x,y + 1);
	if((g[x - 1][y] == g[x + 1][y] && g[x + 1][y] == LEFT) || 
		(g[x][y - 1] == g[x][y + 1] && g[x][y + 1] == LEFT))
		{
			ff(x - 1,y - 1); ff(x + 1,y + 1);
		}
	if((g[x - 1][y] == g[x + 1][y] && g[x + 1][y] == RIGHT) || 
		(g[x][y - 1] == g[x][y + 1] && g[x][y + 1] == RIGHT))
		{
			ff(x + 1,y - 1); ff(x - 1,y + 1);
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int count = 0;
	while(scanf("%d%d",&w,&h),w != 0)
	{
		memset(g,OUT,sizeof(g));
		int i,j,t;
		cyc = max = 0;
		getchar();
		for(i = 1;i <= h * 2;i += 2)
		{
			for(j = 1;j <= 2 * w;j += 2)
			{
				t = getchar();
				g[i + 1][j] = g[i][j + 1] = (t == '\\') ? EMPTY : RIGHT;
				g[i][j] = g[i + 1][j + 1] = (t == '\\') ? LEFT : EMPTY;
			}
			getchar();
		}
		for(i = 1;i <= h * 2;i++)
			for(j = 1;j <= w * 2;j++) if(g[i][j] == EMPTY)
			{
				num = 0;
				flag = 1;
				ff(i,j);
				if(flag) cyc++;
				if(flag && num > max) max = num;
			}
		printf("Maze #%d:\n",++count);
		if(cyc == 0) printf("There are no cycles.\n\n");
		else printf("%d Cycles; the longest has length %d.\n\n",cyc,max);
	}
	return 0;
}

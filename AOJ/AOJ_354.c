#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int a[n + 4][n + 4],i,j,posx,posy,movex[4] = {1,0,-1,0},movey[4] = {0,1,0,-1};
		memset(a,-1,sizeof(a));
		for(i = 1;i <= n;i++)
			for(j = 1;j <= n;j++)
				a[i][j] = 0;
		int now = 1,nowd = 0;
		posx = posy = 1;
		while(now <= n * n)
		{
			a[posx][posy] = now;
			if(now == n * n) break;
			while(a[posx + movex[nowd]][posy + movey[nowd]] != 0) 
			{
				nowd = (nowd + 1) % 4;
			}
			posx += movex[nowd];
			posy += movey[nowd];
			now++;
		}
		for(i = 1;i <= n;i++)
		{
			for(j = 1;j <= n;j++)
			{
				printf("%-3d",a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

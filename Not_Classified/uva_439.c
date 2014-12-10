#include <stdio.h>
#include <string.h>
#include <math.h>

int b[10][10],ans[10][10],fx[50000],fy[50000],fs[50000];
int movex[8] = {-1,-2,-2,-1,1,2,2,1},movey[8] = {-2,-1,1,2,2,1,-1,-2};

void work(int nowx,int nowy,int ex,int ey,int step)
{
	/*
	int ans,i;
	if(b[nowx][nowy] >= step) b[nowx][nowy] = step;
	else return;
	if(nowx == ex && nowy == ey) return;
	for(i = 0;i < 8;i++)
	{
		int newx = nowx + movex[i],newy = nowy + movey[i];
		if(newx >= 1 && newx <= 8 && newy >= 1 && newy <= 8)
			work(newx,newy,ex,ey,step + 1);
	}*/
	int front = 0,rear = 1;
	fs[0] = 1;
	fx[0] = nowx;
	fy[0] = nowy;
	b[nowx][nowy] = 1;
	while(front < rear)
	{
		int i,j;
		/*
		for(i = 1;i <= 8;i++) 
		{
			for(j = 1;j <= 8;j++)
				if(b[i][j] > 100) printf("oo ");
				else printf("%2d ",b[i][j]);
			printf("\n");
		}
		printf("\n\n");*/
		for(i = 0;i < 8;i++)
		{
			int newx = fx[front] + movex[i],newy = fy[front] + movey[i],news = fs[front] + 1;
			if(b[newx][newy] > news && newx >= 1 && newx <= 8 && newy >= 1 && newy <= 8)
			{
				b[newx][newy] = news;
				//printf("%d %d\n",newx,newy);
				fx[rear] = newx;
				fy[rear] = newy;
				fs[rear] = news;
				rear++;
			}
		}
		front++;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	char r1,c1,r2,c2,i,j;
	while(scanf("%c%c %c%c",&c1,&r1,&c2,&r2) == 4)
	{
		memset(b,111,sizeof(b));
		work(r1 - '0',c1 - 'a' + 1,r2 -'0',c2 - 'a' + 1,1);
		printf("To get from %c%c to %c%c takes %d knight moves.\n",c1,r1,c2,r2,b[r2 - '0'][c2 - 'a' + 1] - 1);
		getchar();
	}
	return 0;
}

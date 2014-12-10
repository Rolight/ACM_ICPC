#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

struct Point
{
	int x, y;
	void set(int a,int b)
	{
		x = a;
		y = b;
	}
};

int dis(Point a,Point b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void work()
{
	int M,N;
	while(scanf("%d%d",&M,&N) == 2)
	{
		if(M == 0 && N == 0) break;
		int cc,ch;
		Point h[2000],c[2000];
		char map[50][50];
		int ans = INT_MAX,ansc,ansh;
		cc = ch = 0;
		for(int i = 0;i < M;i++) scanf("%s",map[i]);
		for(int i = 0;i < M;i++)
			for(int j = 0;j < N;j++)
				if(map[i][j] == 'C') c[cc++].set(i,j);
				else if(map[i][j] == 'H') h[ch++].set(i,j);
		for(int i = 0;i < ch;i++)
			for(int j = 0;j < cc;j++)
				if(dis(h[i],c[j]) < ans)
				{
					ans = dis(h[i],c[j]);
					ansc = j;
					ansh = i;
				}
		printf("%d %d %d %d\n",h[ansh].x,h[ansh].y,c[ansc].x,c[ansc].y);
	}
}

int main()
{
	work();
	return 0;
}

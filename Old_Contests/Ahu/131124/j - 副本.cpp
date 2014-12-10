#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

struct Pc
{
	int x1,y1,x2,y2,dis;
	Pc(){

	};
	Pc(int a,int b,int c,int d)
	{
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	};
};

#define swap(t,a,b) ((t)=(a),(a)=(b),(b)=(t))

int cx[50],cy[50],hx[50],hy[50],cc,ch,M,N;
char map[50][50];

void readin()
{
	char temp;
	cc = ch = 0;
	for(int i = 0;i < M;i++) scanf("%s",map[i]);
	for(int i = 0;i < M;i++)
	{
		for(int j = 0;j < N;j++)
		{
			char temp = map[i][j];
			if(temp == 'C')
			{
				cx[cc] = i;
				cy[cc] = j;
				cc++;
			}
			if(temp == 'H')
			{
				hx[ch] = i;
				hy[ch] = j;
				ch++;
			}
		}
	}
}

bool cmp(Pc a,Pc b)
{
	if(a.dis != b.dis) return a.dis < b.dis;
	else if(a.x1 != b.x1) return a.x1 < b.x1;
	else if(a.y1 != b.y1) return a.y1 < b.y1;
	else if(a.x2 != b.x2) return a.x2 < b.x2;
	else return a.y2 < b.y2;
}

Pc dis(int x1,int y1,int x2,int y2)
{
	Pc ans(x1,y1,x2,y2);
	ans.dis = abs(x1 - x2) + abs(y1- y2);
	return ans;
}

void work()
{
	while(scanf("%d%d",&M,&N) == 2 && M && N)
	{
		int ansc = 0;
		Pc ans,now;
		ans.dis = INT_MAX;
		Pc ansz[5000];
		memset(ansz,0,sizeof(ansz));
		readin();
		for(int i = 0;i < ch;i++)
			for(int j = 0;j < cc;j++)
				ansz[ansc++] = dis(hx[i],hy[i],cx[j],cy[j]);
		sort(ansz,ansz + ansc,cmp);
		Pc &end = ansz[0];
		printf("%d %d %d %d\n",end.x1,end.y1,end.x2,end.y2);
	}
}

int main()
{
	work();
	return 0;
}

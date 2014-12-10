#include <iostream>
#include <cstring>

using namespace std;

#define maxn 60

struct bigint
{
	int len,data[80];
	bigint():len(1)
	{
		memset(data,0,sizeof(data));
	};
	string tostring()
	{
		string a("");
		for(int i = len - 1;i >= 0;i--) a += data[i] + '0';
		return a;
	}
};

bigint operator+(bigint a,bigint b)
{
	int len = (a.len > b.len ? a.len : b.len);
	for(int i = 0;i < len;i++)
	{
		a.data[i] += b.data[i];
		a.data[i + 1] += a.data[i] / 10;
		a.data[i] %= 10;
	}
	if(a.data[len]) a.len = len + 1;
	else a.len = len;
	return a;
}

int m,n,x1,y1,x2,y2,v[maxn][maxn];
bigint b[maxn][maxn];

void readin()
{
	cin >> m >> n >> y1 >> x1 >> y2 >> x2;
}


void dp()
{
	int mx[4] = {-2,-1,1,2},my[4] = {-1,-2,-2,-1};
	b[x1][y1].data[0] = v[x1][y1] = 1;
	for(int j = y1 + 1;j <= y2;j++)
		for(int i = 1;i <= m;i++)
			for(int d = 0;d < 4;d++) 
				if(i + mx[d] >= 0 && j + my[d] >= 0 && v[i + mx[d]][j + my[d]])
				{
					b[i][j] = b[i + mx[d]][j + my[d]] + b[i][j];
					v[i][j] = 1;
				}
	cout << b[x2][y2].tostring() << endl;
}

int main()
{
	readin();
	dp();
	return 0;
}

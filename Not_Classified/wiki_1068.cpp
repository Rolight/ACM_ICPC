#include <iostream>
#include <cstdio>

#define maxn 360
#define maxm 40
#define max1(a,b) ((a) > (b) ? (a) : (b))
#define max(a,b,c,d) max1((a),max1((b),max1((c),(d))))

using namespace std;

int la,lb,lc,ld,N,M,s[maxn],f[maxm][maxm][maxm][maxm];

int work()
{
	int n,a,b,c,d,t1,t2,t3,t4;
	for(a = 0;a <= la;a++)
	{
		for(b = 0;b <= lb;b++)
		{
			for(c = 0;c <= lc;c++)
			{
				for(d = 0;d <= ld;d++)
				{
					n = a + 2 * b + 3 * c + 4 * d;
					if(n == 0) f[a][b][c][d] = s[0];
					else
					{
						if(n < 1 || !a) t1 = -1;
						else t1 = f[a - 1][b][c][d];
						if(n < 2 || !b) t2 = -1;
						else t2 = f[a][b - 1][c][d];
						if(n < 3 || !c) t3 = -1;
						else t3 = f[a][b][c - 1][d];
						if(n < 4 || !d) t4 = -1;
						else t4 = f[a][b][c][d - 1];
						f[a][b][c][d] = max(t1,t2,t3,t4) + s[n];
					}
				}
			}
		}
	}
	return f[la][lb][lc][ld];
}

int main()
{
	int a[5] = {
		0,0,0,0,0
	};
	cin >> N >> M;
	for(int i = 0;i < N;i++) cin >> s[i];
	for(int i = 1;i <= M;i++)
	{
		int t;
		cin >> t;
		a[t]++;
	}
	la = a[1];
	lb = a[2];
	lc = a[3];
	ld = a[4];
	cout << work() << endl;
	return 0;
}

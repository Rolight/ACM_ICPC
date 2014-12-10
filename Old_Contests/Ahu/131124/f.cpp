#include <iostream>
#include <cstdio>

using namespace std;

short list[1000][10001];
int N,Q;

void setfile()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}

int getnum()
{
	int n = 0;
	char c;
	while(c = getchar() != )
}

void readin()
{
	int len,tmp;
	cin >> N;
	for(int i = 0;i < N;i++)
	{
		cin >> len;
		for(int j = 0;j < len;j++)
		{
			cin >> tmp;
			list[i][tmp]++;
		}
	}
}

bool query(int a,int b)
{
	for(int i = 0;i < N;i++)
	{
		if(list[i][a] && list[i][b] && a != b) return true;
		else if(a == b && list[i][a] >= 2) return true;
	}
}

void work()
{
	readin();
	cin >> Q;
	for(int i = 0;i < Q;i++)
	{
		int a,b;
		cin >> a >> b;
		if(query(a,b)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

int main()
{
	setfile();
	work();
	return 0;
}

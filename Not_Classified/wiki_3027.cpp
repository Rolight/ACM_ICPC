#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxn 1001
#define max(a,b) ((a > b) ? a : b)
#define swap(t,a,b) ((t)=(a),(a)=(b),(b)=(t))

using namespace std;

int n,l[maxn],r[maxn],v[maxn],f[maxn];

void qs(int str,int end)
{
	if(str >= end) return;
	int i = str,j = end,std = l[(str + end) / 2],t;
	while(1)
	{
		while(l[i] < std) i++;
		while(l[j] > std) j--;
		if(i < j)
		{
			swap(t,l[i],l[j]);
			swap(t,r[i],r[j]);
			swap(t,v[i],v[j]);
			i++; j--;
		}
		else break;
	}
	qs(str,i - 1);
	qs(j + 1,end);
}

void read()
{
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> l[i] >> r[i] >> v[i];	
}

inline bool ifc(int a,int b)
{
	return (l[a] >= r[b] || l[b] >= r[a]);
}

int dp()
{
	int ans = -1;	
	for(int i = 0;i < n;i++)
	{
		f[i] = v[i];
		for(int j = i - 1;j >= 0;j--)
			if(ifc(i,j))
				f[i] = max(f[i],f[j] + v[i]);
		if(f[i] > ans) ans = f[i];
	}
	return ans;
}

int main()
{
	read();
	qs(0,n - 1);
	cout << dp() << endl;
	return 0;
}

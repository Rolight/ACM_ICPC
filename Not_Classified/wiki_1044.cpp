#include <iostream>
#include <cstdio>

#define maxn 30
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int high[30],n,f[30],fm[30],ans,ansm;

int dp()
{
	for(int i = 0;i < n;i++) f[i] = fm[i] = 1;
	for(int i = 1;i < n;i++)	
	{
		for(int j = i - 1;j >= 0;j--) if(high[j] >= high[i]) f[i] = max(f[i],f[j] + 1);
		for(int j = i - 1;j >= 0;j--) if(high[j] < high[i]) fm[i] = max(fm[i],fm[j] + 1);
		if(f[i] > ans) ans = f[i];
		if(fm[i] > ansm) ansm = fm[i];
	}
}

int main()
{
	while(scanf("%d",&high[n]) == 1) n++;
	dp();
	cout << ans << endl << ansm << endl;
	return 0;
}

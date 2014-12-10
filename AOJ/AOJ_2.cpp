#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct jt
{
	int time,val;
};

bool cmp(jt a,jt b)
{
	return (double)a.val / a.time > (double)b.val / b.time;
}

int main()
{
	int amount,time;
	double ans;
	while(cin >> amount >> time && amount != 0)
	{
		jt a[25];
		ans = 0;
		for(int i = 0;i < amount;i++) cin >> a[i].time >> a[i].val;
		sort(a,a + amount,cmp);
		for(int i = 0;i < amount;i++)
		{
			if(time - a[i].time > 0)
			{
				time -= a[i].time;
				ans += a[i].val;
			}
			else
			{
				ans += (double)a[i].val / a[i].time * time;
				break;
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}

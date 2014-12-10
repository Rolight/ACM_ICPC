#include <stdio.h>

int main()
{
	int n,a[60],count = 0;
	while(scanf("%d",&n) && n != 0)
	{
		int i,ans,sum = 0;
		for(i = 0,sum = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		sum = sum / n;
		for(i = 0,ans = 0;i < n;i++) if(a[i] > sum) ans += a[i] - sum;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",++count,ans);
	}
	return 0;
}

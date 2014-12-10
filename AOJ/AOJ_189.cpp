#include <stdio.h>
#include <string.h>

#define max(a,b) ((a > b) ? a : b)

int n,a[8000],f[8000];

int main()
{
	a[0] = -1;
	while(scanf("%d",&n) != EOF)
	{
		memset(f,0,sizeof(f));
		int i,j,ans = 0;
		for(i = 1;i <= n;i++) scanf("%d",&a[i]);
		for(i = 1;i <= n;i++)
		{	
			for(j = i - 1;j >= 0;j--) if(a[j] < a[i] && f[j] + 1 > f[i])
				f[i] = f[j] + 1;
			if(f[i] > ans) ans = f[i];
		}
		printf("%d\n",ans);	
	}
	return 0;
}

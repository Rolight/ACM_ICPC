#include <stdio.h>

int main()
{
	unsigned long long ans,n;
	while(scanf("%llu",&n) != EOF)
	{
		ans = 1;
		while(n > 0)
		{
			ans *= n;
			n--;
		}
		printf("%llu\n",ans);
	}
	return 0;
}

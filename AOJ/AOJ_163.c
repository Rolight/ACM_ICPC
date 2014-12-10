#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n) && n != 0)
	{
		unsigned int ans = 1;
		int i;
		for(i = 1;i < n;i++) ans = (ans + 1) * 2;
		printf("%u\n",ans);
	}
	return 0;
}

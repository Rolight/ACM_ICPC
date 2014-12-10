#include <stdio.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	if(n == 1) puts("1 frog has 1 mouth , 2 eyes and 4 legs , plop dives into the water .");
	else
	{
		printf("%d frogs have %d mouths , %d eyes and %d legs , ",n,n,n * 2,n * 4);
		for(i = 0;i < n;i++) printf("plop ");
		printf("dive into the water .\n");
	}
	return 0;
}

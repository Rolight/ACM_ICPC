#include <stdio.h>

int main()
{
//	freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
	double a[7];
	char name[1000];
	while(scanf("%lf",&a[0]) != EOF)
	{
		int i;
		double min = a[0],max = a[0],sum = a[0];
		for(i = 1;i < 7;i++)
		{
			scanf("%lf",a + i);
			if(a[i] < min) min = a[i];
			if(a[i] > max) max = a[i];
			sum += a[i];
		}
		i = 0;
		getchar();
		while((name[i] = getchar()) != '\n') i++;
		name[i] = 0;
		printf("%s %.2f\n",name,(double)(sum - min - max) / 5);
	}
	return 0;
}

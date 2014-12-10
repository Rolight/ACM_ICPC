#include <stdio.h>

int main()
{
	int n,xm,ym,x0,y0,k,i,j,mx,my;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d%d%d%d%d",&xm,&ym,&x0,&y0,&k);
		for(j = 0;j < k;j++)
		{
			scanf("%d%d",&mx,&my);
			x0 += mx; y0 += my;
			if(x0 < 0) x0 = 0;
			if(y0 < 0) y0 = 0;
			if(x0 >= xm) x0 = xm - 1;
			if(y0 >= ym) y0 = ym - 1;
		}
		printf("%d %d\n",x0,y0);
	}
	return 0;
}

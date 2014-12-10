#include <stdio.h>
#include <string.h>

int main()
{
	int month,day,list[63],i,n = 1;
	memset(list,0,sizeof(list));
	for(i = 1;i <= 62;i += (++n)) list[i] = 1;
	while(scanf("%d/%d",&month,&day),month != 0)
	{
		if(month < 7 || month > 8 || day > 31) printf("0\n");
		else
		{
			int ans = 0;
			for(i = (month - 7) * 31 + day;i <= 62;i++) if(list[i]) ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}

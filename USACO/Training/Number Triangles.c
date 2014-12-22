/*
ID: flsnnx1
LANG: C
TASK: numtri
*/

#include <stdio.h>
#include <memory.h>

#define MAX(a,b) (a > b ? a : b)

int main()
{
	FILE *in = fopen("numtri.in","r"),*out = fopen("numtri.out","w");
	int R;
	fscanf(in,"%d",&R);
	int i,j,tri[R + 1][R + 1];
	memset(tri,0,sizeof(tri));
	for(i = 1;i <= R;i++)
		for(j = 1;j <= i;j++)
			fscanf(in,"%d",&tri[i][j]);
	
	for(i = 1;i <= R;i++)
		for(j = 1;j <= i;j++)
			tri[i][j] += MAX(tri[i - 1][j - 1],tri[i - 1][j]);

	int ans = 0;
	for(i = 1;i <= R;i++)
		if(tri[R][i] > ans)
			ans = tri[R][i];

	fprintf(out,"%d\n",ans);

	return 0;
}

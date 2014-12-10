/*
ID: flsnnx1
LANG: C
TASK: ride
*/

#include <stdio.h>
#include <string.h>

int main()
{
	typedef unsigned int uint;
	uint a = 1,b = 1,i;
	int lena,lenb;
	char stra[7],strb[7];
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	gets(stra);
	gets(strb);
	lena = strlen(stra);
	lenb = strlen(strb);
	for(i = 0;i < lena;i++)
		a *= stra[i] - 'A' + 1;
	for(i = 0;i < lenb;i++)
		b *= strb[i] - 'A' + 1;
	if(a % 47 == b % 47) puts("GO");
	else puts("STAY");
	fclose(stdin);
	fclose(stdout);
}

/*
ID: flsnnx1
LANG: C
TASK: transform
*/

#include <stdio.h>

#define swap(x,y,t_t) (t_t) = (x),(x) = (y),(y) =(t_t); 
#define traversal(i,j,istr,jstr,iend,jend) for((i) = (istr);(i) <= (iend);(i)++)\
								  for((j) = (jstr);(j) <= (jend);(j)++)
char t;
void horizontall(int n,char a[n + 1][n + 1])
{
	int i,j;
	traversal(i,j,1,1,n,n / 2)
		swap(a[i][j],a[i][n - j + 1],t)
}

void clockwise(int n,char a[n + 1][n + 1])
{
	int i,j;
	traversal(i,j,1,i + 1,n,n)
		swap(a[i][j],a[j][i],t)
	horizontall(n,a);
}

int matcmp(int n,char a[n + 1][n + 1],char b[n + 1][n + 1])
{
	int i,j;
	traversal(i,j,1,1,n,n)
		if(a[i][j] != b[i][j]) return 1;
	return 0;
}

int work(int n,char a[n + 1][n + 1],char b[n + 1][n + 1])
{
	int res = 7;
#define cmp(x) if(matcmp(n,a,b) == 0 && (x) < res) res = (x)
	cmp(6);
	int i;
	for(i = 1;i <= 3;i++)
	{
		clockwise(n,a);
		cmp(i);
		horizontall(n,a);
		cmp(5);
		horizontall(n,a);
	}
	clockwise(n,a);
	horizontall(n,a);
	cmp(4);
	return res;
}

void eatline()
{
	char c;
	scanf("%c",&c);
	while(c != '\n') scanf("%c",&c);
}

int main()
{
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	int n,i,j;
	scanf("%d",&n);
	eatline();
	char a[n + 1][n + 1],b[n + 1][n + 1];
	traversal(i,j,1,1,n,n)
	{
		scanf("%c",&a[i][j]);
		if(j == n) eatline();
	}
	traversal(i,j,1,1,n,n)
	{
		scanf("%c",&b[i][j]);
		if(j == n) eatline();
	}
	printf("%d\n",work(n,a,b));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

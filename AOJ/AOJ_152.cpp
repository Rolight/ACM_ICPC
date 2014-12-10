#include <stdio.h>
#include <string.h>

struct bigint
{
	int data[1000];
	int len;
};

typedef struct bigint bign;

bign mulitply(bign a,bign b)
{
	int i,j;
	bign c;
	memset(&c,0,sizeof(c));
	for(i = 0;i < a.len;i++)
	{
		for(j = 0;j < b.len;j++)
		{
			c.data[i + j] += a.data[i] * b.data[j];
			if(c.data[i + j] >= 10)
			{
				c.data[i + j + 1] += c.data[i + j] / 10;
				c.data[i + j] %= 10;
			}
		}
	}
	c.len = a.len + b.len;
	i = 1;
	
	while(c.data[a.len + b.len - i] == 0) c.len--,i++;
	if(c.len == 0) c.len = 1;
	
	return c;
}

bign input(char *str)
{
	bign a;
	memset(&a,0,sizeof(a));
	int count = strlen(str),len = strlen(str),i;
	for(i = 0;i < len;i++)
		if(str[i] == '0') count--;
		else break;
	for(i = 0;i < count;i++) a.data[i] = str[len - i - 1] - '0';
	if(count == 0) a.len = 1;
	else a.len = count;
	return a;
}

void output(bign a)
{
	int i;
	for(i = 0;i < a.len;i++) printf("%d",a.data[a.len - i - 1]);
}

int main()
{
	char str1[1000],str2[1000];
	int n,i,count = 1;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%s%s",str1,str2);
		bign a = input(str1),b = input(str2);
		bign c = mulitply(a,b);
		printf("Case %d:\n",count++);
		printf("%s * %s = ",str1,str2); output(c); printf("\n");
		printf("\n");
	}
	return 0;
}

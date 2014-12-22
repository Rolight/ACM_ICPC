/*
ID: flsnnx1
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <string.h>

int len;
char str[351];
typedef int *(dtype(int));

int right(int now)
{
	now++;
	if(now == len) now = 0;
	return now;
}

int left(int now)
{
	now--;
	if(now == -1) now = len - 1;
	return now;
}

int workit(int (*direction)(int now),int *pos,char *ch,int *f)
{
	int res = 0;
	if(f[*pos] == 1) return 0;
	else if(str[*pos] == 'w') res = 1;
	else if((*ch) == 'w')
	{
		res = 1;
		(*ch) = str[*pos];
	}
	else if((*ch) == str[*pos]) res = 1;
	else return 0;
	if(res == 1) f[*pos] = 1;
	(*pos) = direction(*pos);
	return res;
}

int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	scanf("%d",&len);
	scanf("%c%s",&str[0],str);
	int i,max = 1,f[len + 1];
	for(i = 0;i < len;i++)
	{
		memset(f,0,sizeof(f));
		int lpos = left(i),rpos = i,total = 0;
		char lch = str[lpos],rch = str[rpos];
		while(1)
		{
			int mark = total;
			total += workit(left,&lpos,&lch,f);
			total += workit(right,&rpos,&rch,f);
			if(mark == total) break;
		}
		if(total > max) max = total;
	}
	printf("%d\n",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

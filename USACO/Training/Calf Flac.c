/*
ID: flsnnx1
LANG: C
TASK: calfflac
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20002
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int isch(char ch)
{
	if((ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a')) return 1;
	else return 0;	
}

char upper(char ch)
{
	if(ch <= 'z' && ch >= 'a') return ch - 'a' + 'A';
	else return ch;
}

int main()
{
	FILE *in = fopen("calfflac.in","r"),*out = fopen("calfflac.out","w");
	char text[LEN],ntext[LEN],ch;
	memset(text,0,sizeof(text));
	memset(ntext,0,sizeof(ntext));
	int i,j,k,count = 0,maxlen = 0,nowlen = 0,pos,epos = 0;
	while(fscanf(in,"%c",&ch) != EOF)
		text[count++] = ch;
	for(i = 0;i < count;i++)
	{
		if(!isch(text[i])) continue;
		int L = i,R = i + 1,len = 0;
		while(L >= 0 && R < count)
		{
			if(!isch(text[L])) 
			{
				L--;
				continue;
			}
			if(!isch(text[R]))
			{
				R++;
				continue;
			}
			if(upper(text[L]) == upper(text[R]))
			{
				len+=2;
				L--;
				R++;
			}
			else break;
		}
		if(len > maxlen)
		{
			maxlen = len;
			pos = L + 1;
		}
		L = i - 1;
		R = i + 1;
		len = 1;
		while(L >= 0 && R < count)
		{
			if(!isch(text[L])) 
			{
				L--;
				continue;
			}
			if(!isch(text[R]))
			{
				R++;
				continue;
			}
			if(upper(text[L]) == upper(text[R]))
			{
				len+=2;
				L--;
				R++;
			}
			else break;
		}
		if(len > maxlen)
		{
			maxlen = len;
			pos = L + 1;
		}
	}
	fprintf(out,"%d\n",maxlen);
	i = 0;
	while(!isch(text[pos])) pos++;
	while(maxlen > 0)
	{
		fprintf(out,"%c",text[pos + i]);
		if(isch(text[pos + i])) maxlen--;
		i++;
	}
	fprintf(out,"\n");
	return 0;
}

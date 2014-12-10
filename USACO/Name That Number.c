/*
ID: flsnnx1
LANG: C
TASK: namenum
*/

#include <stdio.h>
#include <string.h>

char mapping[10][3] = {0,0,0,0,0,0,'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','W','X','Y'},dict[5000][13],word[13];
int num[13],words,found = 0;
FILE *fdict,*fin,*fout;
int count = 0;

int search(int len)
{
	int i;
	for(i = 0;i < words;i++)
	{
		if(len == 0 && strcmp(word,dict[i]) == 0) return 1;
		else if(len != 0 && strncmp(word,dict[i],len) == 0)	return 1;
	}
	return 0;
}

void work(int len,int now)
{
	int i;
	if(now > 0 && search(now) == 0) return;
	if(now == len && search(0) == 1)
	{
		fprintf(fout,"%s\n",word);
		count++;
		return;
	}
	if(now < len)
		for(i = 0;i < 3;i++)
		{
			word[now] = mapping[num[now]][i];
			if(!found) work(len,now + 1);
		}
}

int main()
{
	int i = 0,tmp,len = 0;
	fdict = fopen("dict.txt","r");
	fin = fopen("namenum.in","r");
	fout = fopen("namenum.out","w");
	while(fscanf(fdict,"%s",dict[i]) != EOF) i++;
	words = i;
	char ch;
	while(fscanf(fin,"%c",&ch) != EOF && ch != '\n')
	{
		num[len] = ch - '0';
		len++;
	}
	work(len,0);
	if(count == 0) fprintf(fout,"NONE\n");
	fclose(fdict);
	fclose(fin);
	fclose(fout);
	return 0;
}

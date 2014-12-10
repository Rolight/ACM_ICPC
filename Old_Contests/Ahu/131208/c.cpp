#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int c,len1,len2,ns[10005];
char mod[10005],s[1000005];

int kmp(int pos)
{
    int i,j = 0,k;
	ns[1] = 0;
    for(i = 2;i <= len2;i++)
    {
        while(j > 0 && mod[j + 1] != mod[i]) j = ns[j];
        if(mod[j + 1] == mod[i]) j++;
        ns[i] = j;
    }
    i = pos,k = 0,j = 0;
    while(i <= len1)
    {
        while(j > 0 && mod[j + 1] != s[i]) j = ns[j];
        if(mod[j + 1] == s[i])
        {
            j++;
            if(j == len2) k++;
        }
        i++;
    }
    return k;
}

int main()
{
    scanf("%d",&c);
    mod[0] = 'Z', s[0] = 'H';
    while(c--)
    {
        scanf("%s%s",mod + 1,s + 1);
        len1 = strlen(s) - 1;
        len2 = strlen(mod) - 1;
        printf("%d\n",kmp(1));
    }
    return 0;
}


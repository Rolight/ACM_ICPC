#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n,k;
char a[120][10];

bool isgood(char *str)
{
	int len = strlen(str),nk =  0;
	sort(str,str + len);
	for(int i = 0;i < len;i++)
		if(str[i] - '0' == nk) nk++;
	if(nk >= k + 1) return true;
	else return false;
}

void readin()
{
	scanf("%d%d",&n,&k);
	getchar();
	for(int i = 0;i < n;i++) scanf("%s",a[i]);
}

void work()
{
	int count = 0;
	for(int i = 0;i < n;i++) if(isgood(a[i])) count++;
	cout << count << endl;
}

int main()
{
	readin();
	work();
	return 0;
}

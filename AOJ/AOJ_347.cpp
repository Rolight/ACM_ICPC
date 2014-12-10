#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int con(char ch)
{
	switch(ch)
	{
		case '.': return 0;
		case '+': return 1;
		case '%': return 2;
		case '*': return 3;
		case '&': return 4;
	}
	return -1;
}

char rcon(int val)
{
	switch(val)
	{
		case 0 : return '.';
		case 1 : return '+';
		case 2 : return '%';
		case 3 : return '*';
		case 4 : return '&';
	}
	return 0;
}

int main()
{
	int w,h,k,count = 0,val,i,j;
	char t[2049],ch;
	memset(t,0,sizeof(t));
	
	cin >> w >> h >> k;
	while(count < w * h)
	{
		ch = getchar();
		if(ch == '\n') continue;
		t[(count) % w] += con(ch);
		if((count + 1) % w == 0 && (count + 1) / w % k == 0)
		{
			for(i = 0;i < w / k;i++)
			{
				int sum = 0;
				for(j = i * k;j < i * k + k;j++) sum += t[j];
				putchar(rcon(sum / k / k));
			}
			puts("");
			memset(t,0,sizeof(t));
		}
		count++;
	}
	return 0;
}

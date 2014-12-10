#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct bign
{
	int data[40000];
	int len;
	bign()
	{
		len = 1;
		memset(data,0,sizeof(data));
	};
	
};

bign add(bign a,bign b)
{
	int len = (a.len > b.len) ? a.len : b.len;
	for(int i = 0;i < len;i++)
	{
		a.data[i] += b.data[i];
		a.data[i + 1] += a.data[i] / 10;
		a.data[i] %= 10;
	}
	if(a.data[len] != 0) a.len = len + 1;
	else a.len = len;
	return a;
}

int main()
{
	int T;
	cin >> T;
	for(int i = 0;i < T;i++)
	{
		bign ans;
		char a[300];
		while(scanf("%s",a) && !(strlen(a) == 1 && a[0] == '0'))
		{
			bign temp;
			for(int j = 0;j < strlen(a);j++) temp.data[strlen(a) - j - 1] = a[j] - '0';
			temp.len = strlen(a);
			ans = add(ans,temp);
		}
		int flag = 0;
		for(int i = ans.len - 1;i >= 0;i--)
		{
			if(flag == 0 && ans.data[i] != 0) flag = 1;
			if(flag || ans.len == 1)
				printf("%d",ans.data[i]);
		}
		if(!flag) printf("0") ;
		printf("\n");
	}
	return 0;
}

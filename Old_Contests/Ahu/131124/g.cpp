#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
long long dp[20][3];

void work(char *n)
{
	int len = strlen(n),last = 0,flag = 0;
	long long ans = 0;
	for(int i = 0;i < len;i++)
	{
		int nowlen = len - i,now = n[i] - '0';
		ans += now * dp[nowlen - 1][2];
		if(flag) ans += now * dp[nowlen - 1][0];
		if(!flag && now > 4) ans += dp[nowlen - 1][1];
		if(last == 4 && now == 9) flag = 1;
		last = now;
	}
	cout << ans << endl;
}

int main()
{
	char num[20];
	cin >> N;
	dp[0][0] = 1;
	for(int i = 1;i < 20;i++)
	{
		dp[i][0] = dp[i - 1][0] * 10 - dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1];
	}
	for(int i = 0;i < N;i++)
	{
		int j;
		long long temp;
		cin >> temp;
		temp++;
		for(j = 0;temp > 0;j++)
		{
			num[j] = temp % 10 + '0';
			temp /= 10;
		}
		num[j] = 0;
		for(j = 0;j < strlen(num) / 2;j++)
		{
			char t = num[j];
			num[j] = num[strlen(num) - j - 1];
			num[strlen(num) - j - 1] = t;
		}
		work(num);
	}
	return 0;
}

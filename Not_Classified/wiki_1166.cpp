#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#define maxn 81

struct bigint
{
	int len,data[70],base,basebit;
	bigint():len(1),base(10000),basebit(4)
	{
		memset(data,0,sizeof(data));
	};
	bigint(int n):base(10000),basebit(4)
	{
		memset(data,0,sizeof(data));
		len = 0;
		while(n > 0)
		{
			data[len] = n % base;
			n /= base;
			len++;
		}
		if(len == 0) len = 1;
	};
	void tostring()
	{
		printf("%d",data[len - 1]);
		for(int i = len - 2;i >= 0;i--) printf("%04d",data[i]);
		cout << endl;
	};
};

int val[maxn],m,n;
bigint f[maxn][maxn];

bool operator> (bigint a,bigint b)
{
	if(a.len > b.len) return true;
	if(b.len > a.len) return false;
	for(int i = a.len - 1;i >= 0;i--)
	{
		if(a.data[i] > b.data[i]) return true;
		if(a.data[i] < b.data[i]) return false;
	}
	return false;
}

bigint max(bigint a,bigint b)
{
	if(a > b) return a;
	else return b;
}

bigint operator+ (bigint a,bigint b)
{
	int len = ((a.len > b.len) ? a.len : b.len);
	for(int i = 0;i < len;i++)
	{
		a.data[i] += b.data[i];
		a.data[i + 1] += a.data[i] / a.base;
		a.data[i] %= a.base;
	}
	if(a.data[len] != 0) a.len = len + 1;
	else a.len = len;
	return a;
}

bigint operator* (bigint a,bigint b)
{
	bigint c(0);
	for(int i = 0;i < a.len;i++)
	{
		for(int j = 0;j < b.len;j++)
		{
			c.data[i + j] += a.data[i] * b.data[j];
			c.data[i + j + 1] += c.data[i + j] / c.base;
			c.data[i + j] %= c.base;
		}
	}
	c.len = a.len + b.len;
	for(int i = a.len + b.len - 1;c.data[i] == 0;i--) c.len--;
	return c;
}

bigint operator* (int b,bigint a)
{
	bigint tb(b);
	return a * tb;
}

bigint pow2(int n)
{
	bigint ans(1),base(2);
	while(n > 0)
	{
		if(n & 1) ans = ans * base;
		base = base * base;
		n >>= 1;
	}
	return ans;
}

void work()
{
	bigint ans;
	cin >> m >> n;
	for(int i = 0;i < m;i++)
	{
		bigint tans,last;
		for(int j = 0;j < n;j++)
			cin >> val[j];
		for(int j = n - 1;j >= 0;j--)
		{
			for(int s = 0;s + j < n;s++)
			{
				bigint t1,t2;
				if(s - 1 >= 0) t1 = f[s - 1][s + j] + val[s - 1] * pow2(n - j - 1);
				if(s + j + 1 < n) t2 = f[s][s + j + 1] + val[s + j + 1] * pow2(n - j - 1);
				f[s][s + j] = max(t1,t2);
				if(j == 0)
				{
					last = val[s] * pow2(n) + f[s][s];
					if(last > tans) tans = last;
				}
			}
		}
		ans = tans + ans;
	}
	ans.tostring();
}


int main()
{
	work();
	return 0;
}

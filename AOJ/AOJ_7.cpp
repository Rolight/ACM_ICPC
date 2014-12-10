#include <iostream>
#include <cstring>
#include <cstdio>

#define convert(a) ((a == 1) ? 2 : 2 * (a) - 1)

using namespace std;

char prime[5000001]; 

void count(int n)
{
	int limit = (n >> 1);
	for(int i = 2;i <= limit;i++) if(prime[i] != 0)
		for(int j = i + ((i << 1) - 1);j <= limit;j += ((i << 1) - 1)) 
			prime[j] = 0;
}

int main()
{
	int n;
	memset(prime,1,sizeof(prime));
	count(10000000);
	while(cin >> n && n != 0)
	{
		if(n == 1 || n == 0)
			cout << "0" << endl;
		else
		{
			int ans = 1;
			for(int i = 3;i <= n;i += 2) if(prime[(i + 1) >> 1]) ans++;
			cout << ans << endl;
		}
	}
	return 0;	
}

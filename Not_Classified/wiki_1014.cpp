#include <iostream>

#define maxn 40
#define maxv 30000
#define max(a,b) (((a) > (b)) ? (a) : (b))

using namespace std;

int V,n,v[maxn],f[maxv];

int work()
{
	for(int i = 1;i <= n;i++)
		for(int j = V;j >= 0;j--)
			if(j >= v[i]) f[j] = max(f[j - v[i]] + v[i],f[j]);
	return V - f[V];
}

int main()
{
	cin >> V >> n;
	for(int i = 1;i <= n;i++) cin >> v[i];
	cout << work() << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 60

string str[MAXN];

int cmp(string a,string b)
{
	return (a + b) < (b + a);
}

int main()
{
	int n;
	while((cin >> n) && n)
	{
		for(int i = 0;i < n;i++) cin >> str[i];
		sort(str,str + n,cmp);
		for(int i = 0;i < n;i++) cout << str[n - i - 1];
		cout << endl;
	}
	return 0;
}

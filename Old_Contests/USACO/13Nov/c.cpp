#include <iostream>
#include <string>

using namespace std;

long long count[40000],len,a,ans = 0,row[4001];
string str;

int main()
{
	cin >> a >> str;
	len = str.size();
	for(int i = 1;i <= len;i++) 
		row[i] = row[i - 1] + str[i - 1] - '0';
	for(int i = 1;i <= len;i++)
		for(int j = 1;j <= i;j++)
			count[row[i] - row[j - 1]]++;
	if(a){
		for(int i = 1;i <= row[len];i++)
			if((a % i == 0) && (a / i <= row[len]))
				ans += count[i] * count[a / i];
	} else {
		for(int i = 0;i <= row[len];i++)
			ans += (count[0] * count[i] * 2);
		ans += count[0] * count[0];
	}
	cout << ans << endl;
	return 0;
}

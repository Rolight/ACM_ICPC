#include <iostream>
#include <string>

using namespace std;

int main()
{
	string temp;
	int n;
	cin >> n;
	getline(cin,temp);
	for(int i = 0;i < n;i++)
	{
		string str;
		getline(cin,str);
		for(int j = str.size() - 1;j >= 0;j--) cout << str[j];
		cout << endl;
	}
	return 0;
}

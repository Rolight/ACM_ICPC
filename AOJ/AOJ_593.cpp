#include <iostream>

using namespace std;

int n,k,color[10];

int main() 
{
	int temp;
	cin >> n >> k;
	for(int i = 0;i < n;i++)
	{
		cin >> temp;
		color[temp]++;
	}
	if(n % k != 0)
	{
		cout << "No" << endl;
		return 0;
	}
	for(int i = 0;i < 9;i++)
	
	{
		if(color[i] != 0 && color[i] % k != 0)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}

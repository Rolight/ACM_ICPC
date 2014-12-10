#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int N = 1000,C = 10000,Q = 200000;
	freopen("in.txt","w",stdout);
	cout << N << endl;
	for(int i = 0;i < N;i++)
	{
		cout << C << " ";
		for(int j = 0;j < C;j++) cout << rand() % 10000 << " ";
		cout << endl;
	}
	cout << Q << endl;
	for(int i = 0;i < Q;i++) cout << rand() % 10000 << " " << rand() % 10000 << endl;
	return 0;
}

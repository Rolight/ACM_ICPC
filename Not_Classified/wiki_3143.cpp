#include <iostream>

using namespace std;

int L[1000],R[1000],n;

void readin()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> L[i] >> R[i];
}

void midforeach(int root)
{
	if(L[root] != 0) midforeach(L[root]);
	cout << root << " ";
	if(R[root] != 0) midforeach(R[root]);
}

void frontforeach(int root)
{
	cout << root << " ";
	if(L[root] != 0) frontforeach(L[root]);
	if(R[root] != 0) frontforeach(R[root]);
}

void endforeach(int root)
{
	if(L[root] != 0) endforeach(L[root]);
	if(R[root] != 0) endforeach(R[root]);
	cout << root << " ";
}

int main()
{
	readin();
	frontforeach(1);
	cout << endl;
	midforeach(1);
	cout << endl;
	endforeach(1);
	cout << endl;
	return 0;
}

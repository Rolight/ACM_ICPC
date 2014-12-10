#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int n = 10000;
	cout << 1 << " " << n << endl;
	for(int i = 0;i < n;i++) {
		int pos = (rand() * 10000 + rand()) % 10000000 + 1,x = pos * (double)(rand() / 10000) + 1;
		if(pos + x > 10000000) x = 10000000;
		else x = pos + x;
		cout << pos << " " << x << endl;
	}
	return 0;
}

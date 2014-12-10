#include <iostream>
#include <algorithm>

using namespace std;

long long f[1000],f1[1000];

int main() {
	for(int i = 4;i <= 100;i++) {
		f[i] = f[i - 1] + ((i - 1) * (i - 2) / 2 - (i - 1) / 2) / 2;
		f1[i] = f1[i - 1] + (i - 1) * (i - 2) / 2 - (i * (i - 1) / 2 - i / 2) / 2;
		cout << f[i] << " " << f1[i] << endl;
	}
	return 0;
}

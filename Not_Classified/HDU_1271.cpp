#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

int p10[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int solve(int n) {
	int len = log10(n) + 1;
	set<int> note;
	//c不进位
	for(int b = 0;b <= 9;b++) {
		for(int k = 1;k <= len;k++) {
			int n1 = n / p10[k - 1];
			if((n1 - b) % 11 == 0 && n % p10[k - 1] % 2 == 0) {
				int c = n % p10[k - 1] / 2,a = (n1 - b) / 11;
				note.insert(a * p10[k] + b * p10[k - 1] + c);
			}
		}
	}
	//c进位
	for(int b = 0;b <= 9;b++) {
		for(int k = 2;k <= len;k++) {
			int n1 = n / p10[k - 1] - 1;
			if(n1 != 0 && (n1 - b) % 11 == 0 && n % p10[k - 1] % 2 == 0) {
				int c = (n % p10[k - 1] + p10[k - 1]) / 2,a = (n1 - b) / 11;
				int num = p10[k - 1] * (11 * a + b) + 2 * c;
				note.insert(a * p10[k] + b * p10[k - 1] + c);
			}
		}
	}
	if(note.empty()) {
		printf("No solution.");
	} else {
		printf("%d",*note.begin()); note.erase(note.begin());
		while(!note.empty()) {
			printf(" %d",*note.begin());
			note.erase(note.begin());
		}
	}
	printf("\n");
}

int main() {
	int n;
	while(scanf("%d",&n),n) {
		solve(n);
	}
	return 0;
}

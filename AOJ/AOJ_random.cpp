#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
	printf("1000\n");
	for(int i = 0;i < 1000;i++) {
		int len = rand() % 250;
		for(int j = 0;j <= len;j++) {
			putchar(rand() % 26 + 'a');
		}
		putchar('\n');
	}
}

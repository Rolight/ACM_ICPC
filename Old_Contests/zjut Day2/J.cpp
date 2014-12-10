#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int f,m[5][5],x,y;
	while(~scanf("%d",&f)) {
		for(int i = 0;i < 5;i++) {
			for(int j = 0;j < 5;j++) {
				if(i == 0 && j == 0) m[i][j] = f;
				else scanf("%d",&m[i][j]);
				if(m[i][j]) {
					x = i; y = j;
				}
			}
		}
		printf("%d\n",abs(x - 2) + abs(y - 2));
	}
	return 0;
}

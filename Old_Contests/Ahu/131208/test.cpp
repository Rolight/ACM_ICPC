#include <stdio.h>

int main() {
	freopen("in.txt","w",stdout);
	for(int i = 1;i <= 100;i++) 
		for(int j = 1;j <= i;j++) printf("%d %d\n",i,j);
	return 0;
}

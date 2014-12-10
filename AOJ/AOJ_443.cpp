#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int T,R,X,Y;
	scanf("%d",&T);
	while(T--) {
		scanf("%x,%d,%d",&R,&X,&Y);
		R &= ~(1 << X); 
		R |= (1 << Y) + (1 << (Y - 1));
		R &= ~(1 << (Y - 2));
		printf("%x\n",R);
	}
	return 0;
}

#include <cstdio>
#include <string>

using namespace std;

int main() {
	int y,mon,d,h,m,s,th,T;
	scanf("%d",&T);
	while(~scanf("%d/%d/%d-%d:%d:%d",&y,&mon,&d,&h,&m,&s)) {
		printf("%02d/%02d/%04d-",mon,d,y);
		th = h;
		if(h > 12) th = h - 12;
		if(h == 0) th = 12; 
		printf("%02d:%02d:%02d",th,m,s);
		if(h >= 12) printf("pm\n");
		else printf("am\n");
	}
	return 0;
}

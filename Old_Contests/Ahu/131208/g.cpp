#include <stdio.h>
#include <string.h>
#define INF 2100000000

int cake[40][40],now,max = 0,ex[101],ey[101],ce = 0;
int r,c;

int main() {
	scanf("%d%d",&r,&c);
	for(int i = 1;i <= r;i++) {
		for(int j = 1;j <= c;j++) {
			char tmp = 0;
			scanf(" %c",&tmp);
			if(tmp == 'S'){
				cake[i][j] = 1; 
				ex[ce] = i;
				ey[ce] = j;
				ce++;
			}
		}
	}
	for(int i = 0;i < ce;i++) {
		int tmp = 0,x = ex[i],y = ey[i],can = 0;
		for(int j = 1;j <= c;j++) if(j != y) {
			if(cake[x][j] == 1) {
				can -= INF; break;
			}
			if(cake[x][j] == 0) can++;
		}
		if(can > 0) {
			now += can;
			for(int j = 1;j <= c;j++) if(j != y) cake[x][j] = -1;
		}
		can = 0;
		for(int j = 1;j <= r;j++) if(j != x) {
			if(cake[j][y] == 1) {
				can -= INF; break;
			}
			if(cake[j][y] == 0) can++;
		}
		if(can > 0) {
			now += can;
			for(int j = 1;j <= r;j++) if(j != x) cake[j][y] = -1;
		}
	}
	printf("%d\n",now);
	return 0;
}

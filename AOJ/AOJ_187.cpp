#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>

const int INF = INT_MAX / 2 - 1;

using namespace std;

int f[11];

void print(int num) {
	if(num == 1) printf("1 ");
	else {
		print(f[num]);
		printf("%d",num);
		if(num != 10) printf(" ");
	}
}

int main() {
	int w[11][11],d[11],v[11];
	memset(v,0,sizeof(v));
	for(int i = 1;i <= 10;i++)
		for(int j = 1;j <= 10;j++) {
			scanf("%d",&w[i][j]);
			if(w[i][j] == -1) w[i][j] = INF;
		}
	d[1] = 0; d[0] = INF;
	for(int i = 2;i <= 10;i++) d[i] = INF;
	for(int i = 1;i <= 10;i++) {
		int min = 0;
		for(int j = 1;j <= 10;j++) {
			if(!v[j] && d[j] < d[min]) min = j;
		}
		v[min] = 1;
		for(int j = 1;j <= 10;j++) if(d[j] > d[min] + w[min][j]) {
			d[j] = d[min] + w[min][j];
			f[j] = min;
		}
	}
	print(10);
	printf("\n");
	return 0;
}
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char mat[55][55];
int main(){
	int n, m;
	int u, d, l, r;
	u = d = 0;
	l = 55;
	r = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%s", &mat[i][1]);
		for(int j = 1; j <= m; j++){
			if(mat[i][j] == '*'){
				if(!u)
					u = i;
				if(l > j)
					l = j;
			}
		}
	}
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			if(mat[i][j] == '*'){
				if(!d)
					d = i;
				if(r < j)
					r = j;
			}
		}
	}
	//printf("u%d d%d l%d r%d\n", u, d, l, r);
	for(int i = u; i <= d; i++){
		for(int j = l; j <= r; j++)
			putchar(mat[i][j]);
		putchar('\n');
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

struct Node{
	int x, y;
}run[105];
int cmp(const void* a, const void* b){
	return (*(Node *)a).x - (*(Node *)b).x;
}
int main(){
	int n, x0;
	int a, b, flag = 0;
	int ans_l = -1, ans_r = 1001;
	//ans_l = ans_r = ;
	scanf("%d%d", &n, &x0);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &a, &b);
		run[i].x = a < b ? a : b;
		run[i].y = a > b ? a : b;
		if(run[i].x > ans_l)
			ans_l = run[i].x;
		if(run[i].y < ans_r)
			ans_r = run[i].y;
	}
	if(ans_l > ans_r)
		puts("-1");
	else{
		int aa , bb;
		if(x0 >= ans_l && x0 <= ans_r)
			puts("0");
		else {
			aa = abs(x0 - ans_l);
			bb = abs(x0 - ans_r);
			printf("%d\n", aa < bb ? aa : bb);			
		}
	}
	return 0;
}

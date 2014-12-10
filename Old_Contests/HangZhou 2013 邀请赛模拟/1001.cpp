#include <cstdio>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <ctime>
#include <set>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <string>
#include <list>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

inline void scanf_(int &num){
    char in;
    //bool neg = false;
    while(((in = getchar()) > '9' || in < '0') && in != '-') ;
//    if(in == '-') {
//        neg = true;
//        while((in = getchar()) >'9'||in < '0') ;
//    }
    num = in - '0';
    while(in = getchar(), in >= '0' && in <= '9')  num *= 10, num += in - '0';
    //if(neg) num = 0 - num;
}

const int N = 205;
const int M = 1000000 + 5;
double F[2][N];
int t[N][N][105][2];

int work(int n,int m,int l,int r) {
	int w;
		memset(F,0,sizeof(F));
		int k = 0;
		F[k][0] = 1;
		for(int i = 1;i <= m;i++) {
			scanf_(w);
			k = 1 - k;
			for(int j = 0;j < n;j++) {
				F[k][j] = 0.5 * F[1-k][t[n][j][w][0]] + 0.5 * F[1-k][t[n][j][w][1]];
			}
		}
		return k;
}

int main() {
//	freopen("out.txt","r",stdin);
	int n,m,l,r,w;
	for(int i = 1;i < N;i++) {
		for(int j = 0;j < N;j++) {
			for(int k = 0;k < 105;k++) {
				t[i][j][k][0] = (j + k) % i;
				t[i][j][k][1] = ((j - k) % i + i) % i;
			}
		}
	}
	while(scanf("%d%d%d%d",&n,&m,&l,&r)) {
		if((n | m | l | r) == 0)break;
		int k = work(n,m,l,r);
		double sum = 0,sum1 = 0;
		for(int i = l - 1;i < r;i++)
			sum += F[k][i];
		printf("%.4f\n",sum);
	}
	return 0;
}



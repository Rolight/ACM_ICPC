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
#define OUTPUT_FILE "ac.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
    freopen(INPUT_FILE,"r",stdin);
    freopen(OUTPUT_FILE,"w",stdout);
}

const int maxn = 300;
const int sz = 9;

int k[maxn][sz][maxn][sz];
int val[maxn][maxn];
int n,m,q;

#define p2(x) (1<<(x))

int max(int a,int b,int c,int d) {
    return max(max(a,b),max(c,d));
}

void init_RMQ() {
    for(int px = 0;(1 << px) <= n;px++) {
        for(int py = 0;(1 << py) <= m;py++) {
            for(int i = 0;i+p2(px) < n+1;i++) {
                for(int j = 0;j+p2(py) < m+1;j++) {
                	int &now = k[i][px][j][py];
                	if(px == 0 && py == 0) {
                		now = val[i][j];
                	} else if(px == 0 && py != 0) {
                		now = max(k[i][px][j][py-1],k[i][px][j+p2(py-1)][py-1]);
                	} else if(px != 0 && py == 0) {
                		now = max(k[i][px-1][j][py],k[i+p2(px-1)][px-1][j][py]);
                	} else {
	                    k[i][px][j][py] = max(
	                        k[i][px-1][j][py-1],
	                        k[i+p2(px-1)][px-1][j][py-1],
	                        k[i][px-1][j+p2(py-1)][py-1],
	                        k[i+p2(px-1)][px-1][j+p2(py-1)][py-1]
	                        );
                    }
                }
            }
        }
    }
}

inline int query(int qx1,int qy1,int qx2,int qy2) {
    int kx = 0,ky = 0;
    while(p2(kx+1) <= qx2 - qx1 + 1) kx++;
    while(p2(ky+1) <= qy2 - qy1 + 1) ky++;
    return max(
        k[qx1][kx][qy1][ky],
        k[qx2-p2(kx)+1][kx][qy1][ky],
        k[qx1][kx][qy2-p2(ky)+1][ky],
        k[qx2-p2(kx)+1][kx][qy2-p2(ky)+1][ky]
            );
}

int main() {
	setfile();
    while(~scanf("%d%d",&n,&m)) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                scanf("%d",&val[i][j]);
            }
        }
        init_RMQ();
        scanf("%d",&q);
        while(q--) {
            int qx1,qy1,qx2,qy2;
            scanf("%d%d%d%d",&qx1,&qy1,&qx2,&qy2);
            qx1--; qy1--; qx2--; qy2--;
            int ret = query(qx1,qy1,qx2,qy2);
            printf("%d ",ret);
            if(ret == val[qx1][qy1] || ret == val[qx1][qy2] ||
                ret == val[qx2][qy1] || ret == val[qx2][qy2]) 
                puts("yes");
            else puts("no");
        }
    }
    return 0;    
}


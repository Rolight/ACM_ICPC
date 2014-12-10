#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>


using namespace std;

const int maxn = 400;
char stra[maxn],strb[maxn];
int sa[maxn],sb[maxn];
int val[5][5] = {
    5,-1,-2,-1,-3,
    -1,5,-3,-2,-4,
    -2,-3,5,-2,-2,
    -1,-2,-2,5,-1,
    -3,-4,-2,-1,0,
};
int ret[maxn][maxn];

inline int mp(char c) {
    switch(c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        case '-': return 4;
    };
}

int max(int a,int b,int c) {
    return max(a,max(b,c));
}

int main() {
    int T; scanf("%d",&T);
    int lena,lenb;
    for(int kase = 1;kase <= T;kase++) {
        scanf("%d%s%d%s",&lena,stra,&lenb,strb);
        for(int i = 0;i < lena;i++) {
            sa[i + 1] = mp(stra[i]);
            ret[i + 1][0] = val[4][sa[i + 1]] + ret[i][0];
        }
        for(int i = 0;i < lenb;i++) {
            sb[i + 1] = mp(strb[i]);
            ret[0][i + 1] = val[4][sb[i + 1]] + ret[0][i];
        }
        for(int i = 1;i <= lena;i++) {
            for(int j = 1;j <= lenb;j++) {
                ret[i][j] = -2100000;
                ret[i][j] = max(val[sa[i]][4] + ret[i - 1][j],
                        val[sb[j]][4] + ret[i][j - 1],
                        val[sa[i]][sb[j]] + ret[i - 1][j - 1]);
            }
        }
        printf("%d\n",ret[lena][lenb]);
    }
    return 0;
}

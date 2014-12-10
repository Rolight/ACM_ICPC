#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 5005;
int n,m,f[maxn][maxn];
char str1[maxn], str2[maxn];
int scnt1[maxn][26], scnt2[maxn][26];

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%s%s",str1 + 1,str2 + 1);
        int len1 = strlen(str1 + 1), len2 = strlen(str2 + 1);
        memset(scnt1,0,sizeof(scnt1));
        memset(scnt2,0,sizeof(scnt2));
        for(int i = 1;i <= len1;i++) {
            int nc = str1[i] - 'A';
            for(int j = 0;j < 26;j++) {
                if(j == nc) scnt1[i][j] = scnt1[i - 1][j] + 1;
                else scnt1[i][j] = scnt1[i - 1][j];
            }
        }
        for(int i = 1;i <= len2;i++) {
            int nc = str2[i] - 'A';
            for(int j = 0;j < 26;j++) {
                if(j == nc) scnt2[i][j] = scnt2[i - 1][j] + 1;
                else scnt2[i][j] = scnt2[i - 1][j];
            }
        }
        for(int i = 0;i <= len1;i++) {
            for(int j = 0;j <= len2;j++) {
                f[i][j] = INF;
            }
        }
        f[0][0] = 0;
        for(int i = 0;i <= len1;i++) {
            for(int j = 0;j <= len2;j++) {
                int npos, nc, ccnt, zcnt;
                if(i < len1) {
                    npos = i + 1 + j, nc = str1[i + 1] - 'A',
                    ccnt = scnt1[i + 1][nc] + scnt2[j][nc],
                    zcnt = scnt1[len1][nc] + scnt2[len2][nc];
                    if(ccnt == 1) {
                        if(zcnt == 1) f[i + 1][j] = min(f[i + 1][j], f[i][j]);
                        else {
                            f[i + 1][j] = min(f[i + 1][j], f[i][j] - npos);
                        }
                    }
                    else if(ccnt == zcnt) {
                        f[i + 1][j] = min(f[i + 1][j], f[i][j] + npos);
                    }
                    else f[i + 1][j] = min(f[i + 1][j], f[i][j]);
                }
                if(j < len2) {
                    npos = i + 1 + j;
                    nc = str2[j + 1] - 'A';
                    ccnt = scnt1[i][nc] + scnt2[j + 1][nc];
                    zcnt = scnt1[len1][nc] + scnt2[len2][nc];
                    if(ccnt == 1) {
                        if(zcnt == 1) f[i][j + 1] = min(f[i][j + 1], f[i][j]);
                        else {
                            f[i][j + 1] = min(f[i][j + 1], f[i][j] - npos);
                        }
                    }
                    else if(ccnt == zcnt) {
                        f[i][j + 1] = min(f[i][j + 1], f[i][j] + npos);
                    }
                    else f[i][j + 1] = min(f[i][j + 1], f[i][j]);
                }
            }
        }
        printf("%d\n",f[len1][len2]);
    }
    return 0;
}

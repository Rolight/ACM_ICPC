#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

int lim[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int getcount(int y,int m,int d) {
    int ret = 0;
    for(int ny = 1900;ny < y;ny++) {
        if((ny % 4 == 0 && ny % 100 != 0) || (ny % 400 == 0)) lim[2] = 29;
        for(int nm = 1;nm <= 12;nm++) {
            for(int nd = 1;nd <= lim[nm];nd++) {
                ret++;
            }
        }
        lim[2] = 28;
    }
    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) lim[2] = 29;
    for(int nm = 1;nm < m;nm++) {
        for(int nd = 1;nd <= lim[nm];nd++) ret++;
    }
    lim[2] = 28;
    return ret + d;
}

int myabs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int y1,m1,d1;
    int y2,m2,d2;
    scanf("%d:%d:%d",&y1,&m1,&d1);
    scanf("%d:%d:%d",&y2,&m2,&d2);
    printf("%d\n",myabs(getcount(y2,m2,d2) - getcount(y1,m1,d1)));
    return 0;
}

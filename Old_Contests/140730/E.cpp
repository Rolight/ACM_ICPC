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
char sa[100],sb[100];
int lim[15];


LL lcp(int a,int b) {
    sprintf(sa,"%d",a);
    sprintf(sb,"%d",b);
    int lena = strlen(sa),lenb = strlen(sb);
    int len = min(lena,lenb);
    int ans = 0;
    for(int i = 0;i < len;i++) if(sa[i] == sb[i]) ans++;
    else break;
    if(lena > lenb) {
        return a / pow(10,lena - ans);
    } else return b / pow(10,lenb - ans);
}

int getans(int n) {
    LL ret = 0;
    for(int i = 1;i <= n;i++) ret += lcp(i,i - 1);
    cout << n << " " << ret << endl;
}

LL f(LL n,LL t) {
   return ((n - 1) / t + 1) * ((n - 1) / t) / 2;
}

int ccnt = 0;
LL mylcp(LL n) {
    LL mn = n - n % 10;
    LL ret = f(mn - 1,10) * 9;
    for(int i = mn + 1;i <= n;i++) {
        ret += lcp(i,i - 1);
        //printf("%d %d\n",i,i - 1);
    }
    return ret;
}

int main() {
    int n;
    while(scanf("%d",&n) != EOF) {
        LL tt =  n,myans = 0;
        ccnt = 0;
        while(tt) {
            myans += mylcp(tt);
            tt /= 10;
        }
        printf("%lld\n",myans);
    }
    return 0;
}

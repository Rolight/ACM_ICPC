#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 15;
int n,m,num[maxn];
int nowcnt,nowval;

int gcd(int a,int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int lcm(int a,int b) {
    return a / gcd(a,b) * b;
}

void calc(int st) {
    nowval = 1; nowcnt = 0;
    for(int i = 0;i < n;i++) if((1 << i) & st) {
        nowval = lcm(nowval,num[i]);
        nowcnt++;
    }
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        int ans = 0;
        for(int i = 0;i < n;i++) {
            scanf("%d",&num[i]);
        }
        sort(num,num + n);
        n = unique(num,num + n) - num;
        for(int i = 1;i < (1 << n);i++) {
            calc(i);
            if(nowcnt & 1) nowcnt = 1;
            else nowcnt = -1;
            ans += (m / nowval) * nowcnt;
        }
        printf("%d\n",ans);
    }
    return 0;
}

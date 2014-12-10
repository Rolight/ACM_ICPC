#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int w,h,x,y;
    while(~scanf("%d%d%d%d",&w,&h,&x,&y)) {
        int ans = 2100000000;
        ans = min(abs(w - x),abs(h - y));
        ans = min(ans,min(x,y));
        printf("%d\n",ans);
    }
    return 0;
}


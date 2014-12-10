#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100001;

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        int n; scanf("%d",&n);
        int a1,a2,a3; a1 = a2 = a3 = 0;
        int b1,b2,b3; b1 = b2 = b3 = 0;
        for(int i = 1;i <= n;i++) {
            int tmp; scanf("%d",&tmp);
            if(tmp == 1) a3++,b2++;
            if(tmp == 2) a1++,b3++;
            if(tmp == 3) a2++,b1++;
        }
        if(a1 > b1) printf("1\n");
        else if(a2 > b2) printf("2\n");
        else if(a3 > b3) printf("3\n");
        else printf("0\n");
    }
    return 0;

}


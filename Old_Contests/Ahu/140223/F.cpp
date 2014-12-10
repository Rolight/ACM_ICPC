#include <cstdio>

using namespace std;

int a,b,n;
int c[100001];

int main() {
    while(scanf("%d%d%d",&a,&b,&n) == 3) {
        int i = 0;
        for(i = 0;i <= 9;i++) {
            if((a * 10 + i) % b == 0) {
                a = a * 10 + i;
                break;
            }
        }
        if(i == 10) {
            printf("-1\n"); continue;
        }
        printf("%d",a);
        for(int i = 1;i < n;i++) putchar('0');
        putchar('\n');
    }
    return 0;
}

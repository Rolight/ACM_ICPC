#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int d[3][3];
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
            scanf("%d",&d[i][j]);
        }
    }
    for(int i = 1;i <= 100000;i++) {
        int sum = d[1][0] + i + d[1][2];
        int a = sum - d[0][1] - d[0][2];
        int b = sum - d[2][1] - d[2][0];
        if(a > 0 && b > 0) {
            d[0][0] = a; d[1][1] = i; d[2][2] = b;
            if(d[0][0] + d[1][0] + d[2][0] == sum && d[1][0] + d[1][1] + d[1][2] == sum &&
               sum == d[2][0] + d[2][1] + d[2][2] &&
               sum == d[0][0] + d[1][1] + d[2][2] && d[2][0] + d[1][1] + d[0][2] == sum )
               break;
        }
    }
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
            printf("%d ",d[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

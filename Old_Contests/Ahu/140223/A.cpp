#include <cstdio>

using namespace std;
char b[8][8];

int main() {
    bool ok = true;
    for(int i = 0;i < 8;i++) {
        for(int j = 0;j < 8;j++) {
            scanf(" %c",&b[i][j]);
            if(j > 0 && b[i][j] == b[i][j - 1]) ok = false;
        }
        if(b[i][0] == b[i][7]) ok = false;
    }
    if(ok) puts("YES");
    else puts("NO");
    return 0;
}

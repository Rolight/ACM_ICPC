#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char c;
    int ans = 0;
    for(int i = 0;i < 8;i++) {
        for(int j = 0;j < 8;j++) {
            scanf(" %c",&c);
            if((i + j) % 2 == 0 && c == 'F') ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}


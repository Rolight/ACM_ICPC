#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int m;
char s[1020];

int main() {
    scanf("%d",&m) ;
    while(m--) {
        scanf("%s",s);
        int len = strlen(s),c = 0;
        int ans = 0;
        for(int i = 0;i < len;i++) {
            if(i && s[i] != s[i - 1]) {
                ans += c * c;
                c = 0;
            }
            c++;
        }
        ans += c * c;
        printf("%d\n",ans);
    }
    return 0;
}

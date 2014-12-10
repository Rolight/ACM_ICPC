#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>


using namespace std;

const int maxn = 1024;
char buf[maxn];

int main() {
    int k;
    scanf("%s%d",buf + 1,&k);
    int len = strlen(buf + 1),str = 1;
    for(int l = (len + k) / 2 * 2;l >= 2;l -= 2) {
        bool ok;
        for(int str = 1;str + l - 1 <= len + k;str++) {
            ok = true;
            for(int i = str;i - str + 1 <= l / 2 && i + l / 2 <= len;i++) {
                if(buf[i] != buf[i + l / 2]) {
                    ok = false; break;
                }
            }
            if(ok) break;
        }
        if(ok) {
            printf("%d\n",l); break;
        }
    }
    return 0;
}

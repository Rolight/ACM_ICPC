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

const int maxn = 2048;
char buf[2048];
int cnt[26];

int main() {
    gets(buf);
    int sum = 0,len = strlen(buf);
    for(int i = 0;i < len;i++) {
        if(buf[i] >= 'a' && buf[i] <= 'z') {
            cnt[buf[i] - 'a'] = 1;
        }
    }
    for(int i = 0;i < 26;i++) {
        sum += cnt[i];
    }
    printf("%d\n",sum);
    return 0;
}

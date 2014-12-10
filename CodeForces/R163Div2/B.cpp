#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int maxn = 60;

void swap(char &a,char &b) {
    char tmp = a; a = b; b = tmp;
}

int main() {
    int n,t;
    char buf[maxn];
    scanf("%d%d%s",&n,&t,buf + 1);
    for(int i = 1;i <= t;i++) {
        for(int j = 1;j < n;j++) {
            if(buf[j] == 'B' && buf[j + 1] == 'G') {
                buf[j] = 'G'; buf[j + 1] = 'B'; j++;
            }
        }
    }
    printf("%s\n",buf + 1);
    return 0;
}

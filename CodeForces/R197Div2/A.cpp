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
const int maxn = 1024;
char buf[maxn];
vector<int> p;

int main() {
    scanf("%s",buf);
    int len = strlen(buf);
    for(int i = 0;i < len;i++) if(buf[i] != '+') {
        p.push_back(buf[i] - '0');
    }
    sort(p.begin(),p.end());
    for(int i = 0;i < p.size();i++) {
        if(i) putchar('+');
        printf("%d",p[i]);
    }
    puts("");
    return 0;
}

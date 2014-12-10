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

int main() {
    int a = 5,sum = 0;
    switch(a) {
        case 5: for(int i = 1;i <= 15;i++) sum += a; break;
    }
    printf("100\n");
    for(int i = 1;i <= 100;i++) {
        for(int j = 1;j <= 20000;j++) printf("%c",'a' + rand() % 26);
        puts("");
    }
    return 0;
}

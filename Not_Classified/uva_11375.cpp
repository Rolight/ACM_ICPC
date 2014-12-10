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
const int maxn = 2000 + 5;
const int c[10] = {6,2,5,5,4,5,6,3,7,6};

struct bigint {
    int data[maxn];
    int len;
    bigint(int num = 0) {
        len = 0;
        memset(data,0,sizeof(data));
        while(num) {
            data[len++] = num % 10;
            num /= 10;
        }
    }
    void print() {
        if(len == 0) {
            puts("0"); return;
        }
        while(len--) printf("%d",data[len]);
        puts("");
    }
};

bigint operator+(bigint a,bigint b) {
    int len = max(a.len,b.len);
    for(int i = 0;i < len;i++) {
        a.data[i] += b.data[i];
        a.data[i + 1] += a.data[i] / 10;
        a.data[i] %= 10;
    }
    if(a.data[len] != 0) a.len = len + 1;
    else a.len = len;
    return a;
}

bigint f[maxn];

int main() {
    f[0] = 1;
    for(int i = 0;i <= 2000;i++) {
        for(int j = 0;j <= 9;j++) if(i + c[j] <= 2000) {
            if(i == 0 && j == 0) continue;
            f[i + c[j]] = f[i + c[j]] + f[i];
        }
    }
    for(int i = 2;i <= 2000;i++) f[i] = f[i - 1] + f[i];
    int n;
    while(cin >> n) f[n].print();
    return 0;
}

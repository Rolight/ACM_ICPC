#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long cxlove;
const int maxn = 500;

char str[maxn];

void tostr(cxlove n) {
    int pos = 0;
    while(n) {
        str[pos++] = n % 2 + '0';
        n /= 2;
    }
    str[pos] = 0;
}

cxlove todec() {
    int len = strlen(str);
    cxlove out = 0;
    for(int i = 0;i < len;i++) {
        if(str[i] != '0') out += (1LL << (len - i - 1));
    }
    return out;
}

int main() {
    int T; 
    cin >> T;
    while(T--) {
        memset(str,0,sizeof(str));
        cxlove n; cin >> n;
        tostr(n);
        cout << todec() << endl;
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 50000 + 5;
int str[maxn],end[maxn];

void swap(int &a,int &b) {
    int t = a; a = b; b = t;
}

int main() {
    long long n,m;
    while(cin >> n >> m,n != -1) {
        long long k;
        int sz = 0;
        if(n == 1) {
            printf("1\n"); continue;
        }
        for(k = 1;k * (k + 1LL) / 2LL < m;k++);
        for(int i = 1;i <= n - k - 1;i++) str[++sz] = i;
        for(int i = n;i > n - k - 1;i--) str[++sz] = i;
        long long t = k * (k + 1LL) / 2LL - m;
        if(t > 0) {
            int tmp = str[n - k + t];
            for(int i = n - k + t;i > n - k;i--) str[i] = str[i - 1];
            str[n - k] = tmp;
        }
        for(int i = 1;i <= sz;i++) {
            if(i > 1) putchar(' ');
            printf("%d",str[i]);
        }
        putchar('\n');
    }
    return 0;
}


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
int n,m,a,b,c,p;

void swap(int &a,int &b) {
    int tmp = a; a = b; b = tmp;
}

void hr(int &x,int &y,int &n,int &m) {
    y = m - y + 1;
}

void c90(int &x,int &y,int &n,int &m) {
    swap(x,y); swap(n,m);
    hr(x,y,n,m);
}

void rc90(int &x,int &y,int &n,int &m) {
    hr(x,y,n,m);
    swap(x,y); swap(n,m);
}

void work(int x,int y,int n,int m) {
    for(int i = 0;i < a % 4;i++) c90(x,y,n,m);
    for(int i = 0;i < b % 2;i++) hr(x,y,n,m);
    for(int i = 0;i < c % 4;i++) rc90(x,y,n,m);
    printf("%d %d\n",x,y);
}

int main() {
    scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&p);
    for(int i = 1;i <= p;i++) {
        int nx,ny; scanf("%d%d",&nx,&ny);
        work(nx,ny,n,m);
    }
    return 0;
}

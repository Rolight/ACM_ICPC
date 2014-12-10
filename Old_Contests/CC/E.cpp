#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;

LL gcd(LL a,LL b) {
    return b == 0 ? a : gcd(b,a % b);
}

LL lcm(LL a,LL b) {
    if(a == 0 || b == 0) return 0;
    return a / gcd(a,b) * b;
}

LL labs(LL x) {
    return x < 0 ? -x : x;
}

struct Fnum {
    LL s,x;
    Fnum(LL s = 0,LL x = 1):s(s),x(x) {}
    void print() {
        //if(x == 1) cout << s;
      cout << s << "/" << x;
    }
};

Fnum operator * (Fnum a,Fnum b) {
    if(a.s == 0 || b.s == 0) return Fnum(0,1);
    a.s *= b.s; a.x *= b.x;
    LL gg = gcd(labs(a.s),labs(a.x));
    a.s /= gg; a.x /= gg;
    return a;
}

Fnum operator + (Fnum a,Fnum b) {
    //a.print(); cout << "+"; b.print();
    LL lc = lcm(labs(a.x),labs(b.x));
    a.s = a.s * (lc / a.x);
    b.s = b.s * (lc / b.x);
    a.x = b.x = lc;
    a.s += b.s;
    LL gg = gcd(labs(a.x),labs(a.s));
    a.x /= gg; a.s /= gg;
    //cout << "="; a.print(); cout << endl;
    return a;
}

Fnum operator - (Fnum a,Fnum b) {
    b.s = -b.s;
    return a + b;
}


Fnum f[405][405];

int main() {
    f[0][1] = Fnum(1,1);
    for(int i = 1;i <= 400;i++) {
        f[i][1] = Fnum(1,1);
        for(int j = 2;j <= i + 1;j++) {
            f[i][j] = Fnum(i,j) * f[i - 1][j - 1];
            f[i][1] = f[i][1] - f[i][j];
            f[i][j].print(); cout << endl;
        }
        f[i][1].print(); cout << endl;
    }
    for(int i = 0;i <= 5;i++) {
        for(int j = 1;j <= i + 1;j++) {
            f[i][j].print(); cout << " ";
        }
        cout << endl;
    }
    return 0;
}

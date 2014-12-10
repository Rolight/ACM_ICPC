#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

LL gcd(LL a,LL b) {
    return b == 0 ? a : gcd(b,a % b);
}

LL pow10(LL a) {
    LL ret = 1;
    while(a--) ret *= 10;
    return ret;
}

void display(int a,int b) {
    int n = 0,m = 0,ta = a,tb = b;

    while(ta) {
        n++; ta /= 10;
    }

    while(tb) {
        m++; tb /= 10;
    }

    LL denominator,numerator,div;
    denominator = pow10(n) * (pow10(m) - 1);
    numerator = a * (pow10(m) - 1) + b;
    div = gcd(denominator,numerator);
    
    cout << numerator / div << "/" << denominator / div << endl;
}

int main() {
    int T; cin >>T;
    while(T--) {
        int a,b; cin >> a >> b;
        display(a,b);
    }
    return 0;
}

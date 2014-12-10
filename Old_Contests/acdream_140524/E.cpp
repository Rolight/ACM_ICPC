#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

struct Mat {
    int sz,data[9][9];
};

Mat operator * (Mat &a,Mat &b) {
    int sz = a.size;
    for(int i = 1;i <= sz;i++) {
        for(int j = 1;j <= sz;j++) {
            int ret = 0;
            for(int k = 1;k <= sz;k++) {
                
            }
        }
    }
}

template<class T>
T fastpow(T &a,int n) {
    if(n == 1) return a;
    if(n == 0) return T(1);
    if(n & 1) return fastpow(a * a,n / 2) * a;
    else return fastpow(a * a,n / 2);
}


int main() {
    
}

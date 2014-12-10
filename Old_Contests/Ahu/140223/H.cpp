#include <cstdio>
#include <cstring>
#include <cmath>


using namespace std;

const int maxn = 100001;
long long a[maxn],n,x;

int main() {
    long long ct = 0,out = 0,mini = 1;
    scanf("%lld%lld",&n,&x);
    for(int i = 1;i <= n;i++) {
        scanf("%lld",&a[i]);
        if(a[i] < a[mini]) mini = i;
        if(a[i] == a[mini]) {
            if(abs(i - x) < abs(mini - x)) mini = i;
        }
    }
    if(a[mini] == 0) {
        while(a[x] > 0) {
            a[x]--; out++;
            x--;
            if(x == 0) x = n;
        }
        mini = x;
    } else {
        for(int i = 1;i <= n;i++) if(i != mini) {
            if(mini < x) {
                if(i < mini || i > x) {
                    a[i] -= a[mini];
                    out += a[mini];
                } else {
                    a[i] -= a[mini] + 1;
                    out += a[mini] + 1;
                }
            }
            if(mini > x) {
                if(i < mini && i > x) {
                    a[i] -= a[mini];
                    out += a[mini];
                } else {
                    a[i] -= a[mini] + 1;
                    out += a[mini] + 1;
                }
            }
            if(mini == x) {
                a[i] -= a[mini]; out += a[mini];
            }
        }
    }
    a[mini] += out;
    for(int i = 1;i <= n;i++) printf("%lld ",a[i]);
    putchar('\n');
    return 0;
}

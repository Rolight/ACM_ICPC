#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <string>

using namespace std;
 
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;

int main() {
    int N, M, suma, sumb, T;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        suma = sumb = 0;
        for(int i = 0; i < N - 1; i++) {
            int tmp; cin >> tmp; suma += tmp;
        }
        for(int i = 0; i < M; i++) {
            int tmp; cin >> tmp; sumb += tmp;
        }
        int ql = -1, qr;
        for(int i = 0; i <= 100; i++) {
            double avga1 = (suma + i) / (double)N, avgb1 = (double)sumb / M;
            double avga2 = (double)suma / (N - 1), avgb2 = (double)(sumb + i) / (M + 1);
            if(avga2 > avga1 && avgb2 > avgb1) {
                if(ql == -1) ql = i;
                qr = i;
            }
        }
        cout << ql << " " << qr << endl;
    }
    return 0;
}

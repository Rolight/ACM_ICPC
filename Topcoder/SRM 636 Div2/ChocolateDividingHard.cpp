// BEGIN CUT HERE

// END CUT HERE
#line 5 "ChocolateDividingHard.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int maxn = 80;
int nsum[maxn], num[4][maxn];
int val[maxn][maxn], n, m, csum[maxn][maxn];

bool ok(int val) {
    int pcnt = 0, p0 = 0, p1 = 0, p2 = 0, p3 = 0;
    for(int i = 1; i <= m; i++) {
        p0 += num[0][i]; p1 += num[1][i]; p2 += num[2][i]; p3 += num[3][i];
        if(p0 >= val && p1 >= val && p2 >= val && p3 >= val) {
            pcnt++; p0 = p1 = p2 = p3 = 0;
        }
        if(pcnt >= 4) return true;
    }
    return pcnt >= 4;
}

int calc(int pos1, int pos2, int pos3) {
    for(int i = 1; i <= m; i++) {
        num[0][i] = csum[pos1][i];
        num[1][i] = csum[pos2][i] - csum[pos1][i];
        num[2][i] = csum[pos3][i] - csum[pos2][i];
        num[3][i] = csum[n][i] - csum[pos3][i];
    }
    int l = 0, r = 75 * 75 * 9 + 100, ret;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(ok(mid)) {
            ret = mid; l = mid + 1;
        }
        else r = mid - 1;
    }
    return ret;
}

int solve() {
    int ret = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                ret = max(ret, calc(i, j, k));
            }
        }
    }
    return ret;
}

class ChocolateDividingHard
{
    public:
        int findBest(vector <string> chocolate)
        {
            n = chocolate.size();
            m = chocolate[0].size();
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    val[i][j] = chocolate[i - 1][j - 1] - '0';
                    csum[i][j] = csum[i - 1][j] + val[i][j];
                }
            }
            return solve();
        }

        // BEGIN CUT HERE
    public:
        void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
    private:
        template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
        void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
        void test_case_0() { string Arr0[] = {
            "95998",
            "21945",
            "23451",
            "99798",
            "74083"
        }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, findBest(Arg0)); }
        void test_case_1() { string Arr0[] = {
            "12942",
            "23456",
            "99798",
            "98998",
            "67675"
        }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, findBest(Arg0)); }
        void test_case_2() { string Arr0[] = {
            "129420",
            "234560",
            "997980",
            "989980",
            "676760"
        }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, findBest(Arg0)); }
        void test_case_3() { string Arr0[] = {"987055360916669852598058396375563481229411099995156272011861439988222463", "765684319037260548602622644880358846578673519776658830295695853657506574", "827026882685707468963429171048633355035213903841967401541765520055750294", "514011327279425591275391078390771194237174318088437966083115184423068706", "359450413111939543073417924816671518750081376523840104908509168439216434", "774426703733345195321187318971658092862158592004836177800817292091509715", "586018414221933914736965317201989582625268361874448066899519617885269886"};
            vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 87; verify_case(3, Arg1, findBest(Arg0)); }

        // END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ChocolateDividingHard ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

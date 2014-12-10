#line 5 "ElectronicPetEasy.cpp"
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

class ElectronicPetEasy
{
        public:
        string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2)
        {
			set<int> st; st.insert(st1);
			int nowt = st1;
			for(int i = 0; i < t1 - 1; i++) {
				st.insert(nowt + p1);
				nowt += p1;
			}
			nowt = st2;
			if(st.count(nowt)) return "Difficult";
			for(int i = 0; i < t2 - 1; i++) {
				if(st.count(nowt + p2)) {
					return "Difficult";
				}
				nowt += p2;
			}
			return "Easy";
        }
        

};

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

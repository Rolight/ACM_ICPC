#include <cstdio>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <ctime>
#include <set>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <string>
#include <list>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}
const int N = 105;
int a[N];
int n,x,y,bv,pv;
double s(double x1,double x2,double y) {
	double len = sqrt((x1 - x2) * (x1 - x2) + y * y);
	return len / pv;
}
double dist(double x1,double x2,double y) {
	double len = sqrt((x1 - x2) * (x1 - x2) + y * y);
	return len;
}
inline bool fequ(double a,double b)
{
	if(fabs(a - b) < 1e-9)return true;
	return false;
}
int main() {
	scanf("%d%d%d",&n,&bv,&pv);
	for(int i = 0;i < n;i++) {
		scanf("%d",&a[i]);
	}
	double ans = 1e50,ansd = 1e50;
	int ansi = -1;
	scanf("%d%d",&x,&y);
	for(int i = 1;i < n;i++) {
		double tmp = s(a[i],x,y) + (double)a[i] / bv;
		if(fequ(tmp,ans)) {
			if(dist(a[i],x,y) < ansd) {
				ansi = i;
				ansd = dist(a[i],x,y);
			}
		}
		else if(tmp < ans) {
			ans = tmp;
			ansi = i;
			ansd = dist(a[i],x,y);
		}
	}
	printf("%d\n",ansi + 1);
	return 0;
}

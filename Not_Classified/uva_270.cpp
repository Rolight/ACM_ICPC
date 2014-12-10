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

const int maxn = 800;
const double eps = 1e-6;

char buf[2000];

struct Point {
	int x,y;
};

struct Line {
	double k,b;
	
	bool operator == (const Line &x) const {
		return (fabs(x.k - k) < eps && fabs(x.b - b) < eps);
	}

	bool operator < (const Line &x) const {
		if(k == x.k) return b < x.b;
		else return k < x.k;
	}

	bool operator > (const Line &x) const {
		if(k == x.k) return b > x.b;
		return k > x.k;
	}
};

inline Line getline(Point a,Point bb) {
	double k,b;
	double x1 = a.x,x2 = bb.x,y1 = a.y,y2 = bb.y;
	k = (y1 - y2) / (x1 - x2);
	b = y1 - k * x1;
	return (Line){k,b};
}

Point p[maxn];
Line l[maxn * maxn];
Line *pl[maxn * maxn],*tmp;


void quicksort(int l,int r) {
	if(l >= r) return;
	int i = l,j = r,mid = (l + r) >> 1;
	Line std = *pl[mid];
	while(1) {
		while(*pl[i] < std) i++;
		while(*pl[j] > std) j--;
		if(i < j) {
			tmp = pl[i]; pl[i] = pl[j]; pl[j] = tmp;
			i++; j--;
		} else break;
	}
	quicksort(l,i - 1);
	quicksort(j + 1,r);
}


int main() {
	//freopen("out.txt","r",stdin);
	int N,cnt,lcnt = 0;	
	scanf("%d",&N); getchar();
	gets(buf);
	for(int kase = 1;kase <= N;kase++) {
		cnt = lcnt = 0;
		while(gets(buf) && buf[0] != 0) {
			sscanf(buf,"%d%d",&p[cnt].x,&p[cnt].y);
			cnt++;
		}
		
		
		for(int i = 0;i < cnt;i++) {
			for(int j = i + 1;j < cnt;j++)  {
				pl[lcnt] = l + lcnt;
				l[lcnt++] = getline(p[i],p[j]);
			}
		}

		quicksort(0,lcnt - 1);
		
		int ans = -INF,nowans = 0;
		for(int i = 0;i < lcnt;i++) {
			if(i == 0 || *pl[i] == *pl[i - 1]) {
				nowans++;
			}
			if(i != 0 && !(*pl[i] == *pl[i - 1])) {
				ans = max(ans,nowans);
				nowans = 1;
			}
		}
		ans = max(nowans,ans);
		ans *= 2;

		for(int i = 1;i <= cnt;i++) if(i * (i - 1) == ans) {
			printf("%d\n",i);
			break;
		}
		if(kase != N) putchar('\n');
	}

	return 0;
} 



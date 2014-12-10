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
#define OUTPUT_FILE "wa.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

const int maxn = 301;
int val[maxn][maxn];
int N,M,Q,ql,qr,qx1,qy1,qx2,qy2;


struct segment_tree_node {
	int ch[4],maxv;
};

struct segment_tree {
	segment_tree_node node[(maxn * maxn) << 4];
	int sz,root;
	int qxl,qxr,qyl,qyr;
	void init() {
		sz = 1; root = 0;
	}
	
	void build(int u,int xl,int xr,int yl,int yr) {
		if(xr < xl|| yr < yl) return;
		if(xl == xr && yl == yr) {
			node[u].maxv = val[xl][yl];
			return;
		}
		int xm = (xl + xr) >> 1,ym = (yl + yr) >> 1;
		for(int i = 0;i < 4;i++) node[u].ch[i] = sz++;
		build(node[u].ch[0],xl,xm,yl,ym);
		build(node[u].ch[1],xm + 1,xr,yl,ym);
		build(node[u].ch[2],xl,xm,ym + 1,yr);
		build(node[u].ch[3],xm + 1,xr,ym + 1,yr);
		node[u].maxv = max( max(node[node[u].ch[0]].maxv, node[node[u].ch[1]].maxv),
						max(node[node[u].ch[2]].maxv, node[node[u].ch[3]].maxv));
	}

	int query(int u,int xl,int xr,int yl,int yr) {
		if(xr < xl|| yr < yl) return -INF;
		if(qxl <= xl && qyl <= yl && qxr >= xr && qyr >= yr) {
			return node[u].maxv;
		}
		if(qxl > xr || qxr < xl || qyl > yr || qyr < yl) return -INF;
		int xm = (xl + xr) >> 1,ym = (yl + yr) >> 1;
		int ret = max(
			max(query(node[u].ch[0],xl,xm,yl,ym),	query(node[u].ch[1],xm + 1,xr,yl,ym)),
			max(query(node[u].ch[2],xl,xm,ym + 1,yr),query(node[u].ch[3],xm + 1,xr,ym + 1,yr))
		);
	}
};

segment_tree st;

int main() {
	//setfile();
	while(~scanf("%d%d",&N,&M)) {
		for(int i = 1;i <= N;i++) {
			for(int j = 1;j <= M;j++) {
				scanf("%d",&val[i][j]);
			}
		}
		st.init();
		st.build(0,1,N,1,M);
		scanf("%d",&Q);
		while(Q--) {
			scanf("%d%d%d%d",&st.qxl,&st.qyl,&st.qxr,&st.qyr);
			int ret = st.query(0,1,N,1,M);
			printf("%d ",ret);
			if(ret == val[st.qxl][st.qyl] || ret == val[st.qxl][st.qyr] ||
				ret == val[st.qxr][st.qyl] || ret == val[st.qxr][st.qyr])
				puts("yes");
			else puts("no");
		}
	}
	return 0;
}



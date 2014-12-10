#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1005;
bool cover[maxn];
int father[maxn],deep[maxn],n,T,s,k,*pdp[maxn];
vector<int> gr[maxn];

void make_root(int id) {
	int m = gr[id].size();
	for(int i = 0;i < m;i++) if(father[gr[id][i]] == 0) {
		father[gr[id][i]] = id;
		deep[gr[id][i]] = deep[id] + 1;
		make_root(gr[id][i]);
	}
}

void make_cover(int id,int dpt) {
	if(dpt > k) return;
	cover[id] = true;
	int m = gr[id].size();
	for(int i = 0;i < m;i++)  make_cover(gr[id][i],dpt + 1);
}

bool cmp(int *a,int *b) {
	return *(a) < *(b);
}

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&s,&k);
		memset(cover,false,sizeof(cover));
		memset(father,0,sizeof(father));
		for(int i = 1;i <= n;i++) {
			pdp[i] = &deep[i];
			gr[i].clear();
		}
		for(int i = 1;i < n;i++) {
			int a,b; scanf("%d%d",&a,&b);
			gr[a].push_back(b);
			gr[b].push_back(a);
		}
		int ans = 0;
		deep[s] = 0;
		father[s] = s;
		make_root(s);
		make_cover(s,0);
		sort(pdp + 1,pdp + n + 1,cmp);
		for(int i = n;i >= 1;i--) {
			int nowid = (int)(pdp[i] - &deep[0]);
			if(cover[nowid]) continue;
			for(int j = 0;j < k;j++) nowid = father[nowid];
			make_cover(nowid,0); ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

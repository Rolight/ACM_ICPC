#include <cstdio>
#include <map>

#define RANGE 350000
#define LL long long

using namespace std;

int N,M,times[15],count,ans,l;
char str[15][50];
bool ch[50];
map<LL,int> num;

void readin() {
	scanf("%d%d",&N,&M);
	for(int i = 0;i < M;i++) 
		scanf("%s%d",str[i],&times[i]);
	for(int i = 0;i < M;i++)
		for(int j = 0;j < N;j++)
			str[i][j] -= '0';
}

LL con(char *old) {
	LL term = 1,ans = 0;
	for(int i = N - 1;i >= 0;i--) {
		ans += term * old[i];
		term *= 2;
	}
	return ans;
}

void dfs(char *old,int k,int last) {
	if(k == 0) {
		LL t = con(old); 
		if((num.count(t) && num[t] == l - 1) || l == 1) num[t] = l;
		return;
	}
	for(int i = last + 1;i < N;i++) if(!ch[i]) {
		old[i] = !old[i];
		ch[i] = true;
		dfs(old,k - 1,i);
		ch[i] = false;
		old[i] = !old[i];
	}
}

void work() {
	LL ans = 0;
	for(int i = 0;i < N;i++) {
		l = i + 1;
		dfs(str[i],times[i],-1);
	}
	for(map<LL,int>::iterator iter = num.begin();
			iter != num.end();++iter) {
		if(iter->second == M) ans++;
	}
	printf("%d\n",ans);
}

int main() {
	freopen("in.txt","r",stdin);
	readin();
	work();
	return 0;
}

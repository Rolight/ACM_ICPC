#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef set<string> dict;
typedef int numlist[40];

int adjcount[40],n,k,adjnum,check[101];
string adj[40][101],nohave[101][41];
dict adjs[40];

int cmp(string a,string b)
{
	return a < b;
}

void strsort(string str[],int n)
{
	sort(str,str + n,cmp);
}

void readin()
{
	///freopen("nocow.in","r",stdin);
	///freopen("nocow.out","w",stdout);
	cin >> n >> k;
	getchar();
	char temp[1000];
	adjnum = 1;
	scanf("Farmer John has no %s",temp);
	adjs[1].insert(temp);
	adj[1][0] = temp;
	nohave[1][1] = temp;
	while(scanf("%s",temp),strcmp(temp,"cow.") != 0)
	{
	   	adjnum++;
		nohave[1][adjnum] = temp;
		adjs[adjnum].insert(temp);
		adj[adjnum][0] = temp;
	}
	getchar();
	for(int i = 1;i < n;i++)
	{
		int t = 1;
		scanf("Farmer John has no %s",temp);
		nohave[i + 1][1] = temp;
		if(adjs[1].count(temp) == 0) 
		{
			adjs[1].insert(temp);
			adj[1][adjs[1].size() - 1] = temp;
		}
		while(scanf("%s",temp),strcmp(temp,"cow.") != 0) 
		{
			nohave[i + 1][t + 1] = temp;
			if(adjs[++t].count(temp) == 0)
			{
				adjs[t].insert(temp);
				adj[t][adjs[t].size() - 1] = temp;
			}
		}
		getchar();
	}
	for(int i = 1;i <= adjnum;i++)
		strsort(adj[i],adjs[i].size());
}

void countk(int list[],int n,int now)
{
	if(now > adjnum) return;
	int t = 1;
	for(int i = now + 1;i <= adjnum;i++) t *= adjs[i].size();
	list[now] = (n % t == 0) ? n / t : n / t + 1;
	int k = n % t;
	if(k == 0) k = t;
	countk(list,k,now + 1);
}

int find(string a[],string b,int n)
{
	for(int i = 0;i < n;i++) 
		if(a[i] == b) return i + 1;
}

int judge(int l[],int k[])
{
	for(int i = 1;i <= adjnum;i++) if(l[i] != k[i]) return l[i] - k[i];
	return 0;	
}

void work()
{
	int ok = 1;
	numlist l;
	countk(l,k,1);
	while(ok)
	{
		ok = 0;
		numlist temp;
		for(int i = 1;i <= n;i++) if(!check[i])
		{
			for(int j = 1;j <= adjnum;j++) temp[j] = find(adj[j],nohave[i][j],adjs[j].size());
			int res = judge(temp,l);
			if(res <= 0) check[i] = 1;
			if(res <= 0)
			{
				k++;
				ok = 1;
			}
		}
		countk(l,k,1);
		printf("%d\n",k);
	}
	for(int i = 1;i <= adjnum;i++)
		printf("%s%c",adj[i][l[i] - 1].c_str(),(i == adjnum)?'\n':' ');
	puts("");
}

int main()
{
	readin();
	work();
	return 0;
}

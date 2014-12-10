#include <fstream>
#include <iostream>
#include <cstring>
#include <climits>

#define min(a,b) ((a<b)?a:b)

using namespace std;

const long long INF = 1000000000000000LL;

long long g[201][201];

int main() {
	int N,M,K,Q,a,b,v,count = 0,tot = 0;
	ifstream fin("vacation.in");
	ofstream fout("vacation.out");
	fin >> N >> M >> K >> Q;
	for(int i = 1;i <= N;i++)
		for(int j = 1;j <= N;j++)
			g[i][j] = INF;
	for(int i = 0;i < M;i++) {
		fin >> a >> b >> v;
		g[a][b] = v;
	}
	for(int i = 1;i <= N;i++) 
		for(int j = 1;j <= N;j++)
			for(int k = 1;k <= N;k++) 
				if(g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
	for(int i = 0;i < Q;i++) {
		long long ans = INF;
		fin >> a >> b;
		for(int j = 1;j <= K;j++) ans = min(ans,g[a][j] + g[j][b]);
		if(a <= K || b <= K) ans = min(ans,g[a][b]);
		if(ans < INF) {
			tot += ans; count++;
		}
	}
	fout << count << endl << tot << endl;
	return 0;
}

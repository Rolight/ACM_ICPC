#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char mat[105][105];
bool T[30];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int main()
{
	int n, m, ans = 0, k = 0;
	scanf("%d%d", &n, &m);
	char P[2];
	scanf("%s", P);
	//memset(mat, 0, sizeof(mat));
	for(int i = 1; i <= n; i++) {
		scanf("%s", mat[i]+1);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(mat[i][j] == P[0]) {
				for(int d = 0; d < 4; d++) {
					int nx = i + dx[d], ny = j + dy[d];
					if(mat[nx][ny] == '.'||!mat[nx][ny])	continue;
					else if(mat[nx][ny] == P[0])	continue;
					else
						T[mat[nx][ny] - 'A'] = true;
				}
			}
		}
	for(int i = 0; i < 30; i++)
		if(T[i])	ans++;
	printf("%d\n", ans);
	return 0;
}

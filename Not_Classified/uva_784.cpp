#include <cstdio>
#include <cstring>

#define SIZE 125

using namespace std;

char graph[SIZE][SIZE];

void getline(char *str)
{
	int j = 0;
	while(scanf("%c",&str[j]),str[j] != '\n') j++;
	str[j] = 0;
}

void FooldFill(int x,int y)
{
	if(graph[x][y] == 'X' || graph[x][y] == '#' 
		|| x - 1 < 0 || y - 1 < 0 || graph[x][y] == 0) return;
	graph[x][y] = '#';
	FooldFill(x + 1,y); FooldFill(x - 1,y);
	FooldFill(x,y + 1); FooldFill(x,y - 1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	getchar();
	for(int i = 0;i < n;i++)
	{
		int count = 0,j;
		char *pos = NULL;
		while(getline(graph[count]),graph[count][0] != '_') count++;
		for(j = 0;j < count;j++) 
		{
			pos = strchr(graph[j],'*');
			if(pos != NULL) break;
		}
		FooldFill(j,pos - graph[j]);
		for(j = 0;j <= count;j++) printf("%s\n",graph[j]);
	}
	return 0;
} 

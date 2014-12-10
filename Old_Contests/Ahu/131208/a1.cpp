#include<iostream>
#include<cstring>
using namespace std;
long long t[101][101];
int main()
{
   for(int i = 1;i <= 100;i++)
    for(int j = 1;j <= i;j++){
         if(i == j) t[i][j]=1;
         else if(j == 1) t[i][j] = i;
         else
           t[i][j] = t[i - 1][j]+t[i - 1][j - 1];
    }
    int n,m;     
    while(cin >> n >> m,n || m){
           cout << n << " things taken " << m 
			   <<" at a time is " << t[n][m] << " exactly." << endl;
    }
    return 0;
}


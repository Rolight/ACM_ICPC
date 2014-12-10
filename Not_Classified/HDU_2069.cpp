#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include<math.h>
using namespace std;
int a[]={1,5,10,25,50};
 
int dp[333][20][105];
int f[2222];
int dfs(int x,int val,int t)
{
    if(t>100) return 0 ;
    if(x<0) return 0 ;
    if(~dp[x][val][t]) return dp[x][val][t];
    if(x==0&&t>=0) return dp[x][val][t]=1;
    int ans=0;
    for(int i = val;i<5;i++){
        ans+=dfs(x-a[i],i,t+1);
    }
    return dp[x][val][t]= ans;
}
int main()
{
    int n;
    memset(dp,-1,sizeof(dp));
    for(int i =1;i<=250;i++) f[i]=dfs(i,0,0);
    f[0] = 1;
    while(cin>>n){
        cout<<f[n]<<endl;
    }
    return 0;
}

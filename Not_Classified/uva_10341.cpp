#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h> 
#include<algorithm>
#include<cmath>
#include<map>
#include<deque>
using namespace std;
const double e=2.718281828;
const double minn=10e-8;
double  p, q, r, s, t ,u;
double f(double x)
{
 //p*e-x + q*sin(x) + r*cos(x) + s*tan(x) + t*x2 + u 
 double rr=p*pow(e,-x)+q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
 return rr; 
}
int main()
{
 while(cin>>p>>q>>r>>s>>t>>u)
 {
  if(f(0.0)*f(1.0)>0){
   cout<<"No solution"<<endl;
   continue;
  }
  double low=0.0,up=1.1,mid;
  while(up-low>minn)
  {
   mid=(low+up)/2.0;
   if(f(low)*f(mid)>0)low=mid;
   else up=mid;
  }
  printf("%.4lf\n",up);
 }
 
}


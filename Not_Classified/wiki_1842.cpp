#include <iostream>
int f(int x){return (x>=0)?5:f(x+1)+f(x+2)+1;}
int main(){int x;std::cin>>x;std::cout<<f(x)<<"\n";return 0;}

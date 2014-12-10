    #include <stdio.h>  
    #include <algorithm>  
    using namespace std;  
    bool cmp(int a,int b)  
    {  
        return a>b;  
    }  
    int a[100001],b[100001];  
    int main()  
    {  
        int n,k;  
        scanf("%d%d",&n,&k);  
        for(int i=1;i<=n;i++)  
            scanf("%d",&a[i]);  
        for(int i=1;i<=n;i++)  
            scanf("%d",&b[i]);  
        sort(a+1,a+n+1);  
        sort(b+1,b+n+1,cmp);  
        int ans=1;  
        for(int i=1;i<=n;i++)  
            if(a[i]+b[ans]>=k)  
                ans++;  
        printf("1 %d",ans-1);  
        return 0;  
    }  

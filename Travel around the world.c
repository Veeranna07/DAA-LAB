#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int N,i,flag=0;
    long long C,*dp;
    int *a,*b,ans=0;
    scanf("%d%lld",&N,&C);
    a=(int*)malloc(N*sizeof(int));
    b=(int*)malloc(N*sizeof(int));
    dp=(long long*)malloc(2*N*sizeof(long long));
    for(i=0;i<N;i++)
        scanf("%d",a+i);
    for(i=0;i<N;i++)
        scanf("%d",b+i);
    for(i=0;i<2*N;i++)
        dp[i]=1;
    for(i=0;i<N;i++)
    {
        if(!i)
            dp[i]=0;
        else if(a[N-1-i]<=C)
            dp[i]=dp[i-1]-a[N-1-i]+b[N-1-i];
        else
            dp[i]=dp[i-1]-C+b[N-1-i];
        if(dp[i]<0)dp[i]=0;
        if(dp[i]+((a[N-1-i]>C)?C:a[N-1-i])>C)
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        for(i=0;i<N;i++)
        {
            if(a[N-1-i]<=C)
                dp[i+N]=dp[i-1+N]-a[N-1-i]+b[N-1-i];
            else dp[i+N]=dp[i-1+N]-C+b[N-1-i];
            if(dp[i+N]<0)dp[i+N]=0;
            if(dp[i+N]+((a[N-1-i]>C)?C:a[N-1-i])>C)
            {
                dp[i+N]=1;
                break;
            }
        }
    }

    for(i=0;i<N;i++)
    {
        if(dp[i+N]<=0)
        ans++;
    }
    printf("%d",ans);    
}

#include<cstdio>
#include<algorithm>
#include <iostream>
#include<cstring>
using namespace std;
#define N 2500
#define INF 0xfffffff
typedef long long ll;

ll dp[N][N][2];
ll n,V,X;
ll sum[N];
struct node
{
    ll x;
    ll v;
} a[N];
ll cmp(node b,node c)
{
    return b.x<c.x;
}
ll Delay(ll l,ll r)
{
    if(l>r)
        return 0;
    return sum[r]-sum[l-1];
}
void DP()
{
    ll res;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
            dp[i][j][0]=dp[i][j][1]=INF;
    }
    for(ll i=1; i<=n; i++)
    {
        if(a[i].x==X)
        {
            res=i;
            break;
        }
    }
    dp[res][res][0]=dp[res][res][1]=0;
    for(ll i=res; i>=1; i--)//i循环restaurant左边的
    {
        for(ll j=res; j<=n; j++)//j循环restaurant右边的
        {
            ll delay=Delay(1,i-1)+Delay(j+1,n);
            if(i==j)
                continue;
            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(a[i+1].x-a[i].x)*(delay+a[i].v));
            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(a[j].x-a[i].x)*(delay+a[i].v));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(a[j].x-a[i].x)*(delay+a[j].v));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(a[j].x-a[j-1].x)*(delay+a[j].v));
        }
    }
}
int main()
{
    freopen("data.in","r",stdin);
    while(scanf("%d%d%d",&n,&V,&X)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&a[i].x,&a[i].v);
        }
        a[n+1].x=X;
        a[n+1].v=0;
        n++;
        sort(a+1,a+n+1,cmp);
        memset(sum,0,sizeof(sum));
        for(int i=1; i<=n; i++)
            sum[i]=sum[i-1]+a[i].v;
        DP();
        printf("%d\n",min(dp[1][n][0],dp[1][n][1])/V);
    }
    return 0;
}

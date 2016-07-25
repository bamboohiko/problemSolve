#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int sum[1010],t,n;
int fig(int l,int r)
{
    if (r >= l) return sum[r-1] - sum[l-1];
    return sum[n] - sum[l-1] + sum[r-1];//fig(l,n+1)+fig(1,r);
}
int main()
{
    scanf("%d",&t);sum[0] = 0;
    for (int ca = 1;ca <= t; ca++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n; i++)
        {
            scanf("%d",&sum[i]);
            sum[i] += sum[i-1];
        }
        printf("Case #%d:",ca);
        for (int i = 1;i <= n; i++)
        {
            int ans = 2e9 + 7;
            for (int j = 1;j <= n; j++)
            {
                int k1 = fig(i,j),k2 = fig(j+1,i);
                //printf("%d %d %d %d\n",i,j,k1,k2);
                ans = min(ans,k1 + k2 + min(k1,k2));
            }
            printf(" %d",ans);
        }
        printf("\n");
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m,v[223];
vector<int>son[223];
int dp[223][223];

void dfs(int n,int m){   //树状dp  n为父节点，m为背包容量V。
    int i,j,k,V,len=son[n].size();
    dp[n][1]=v[n];
    for(int i=0;i<len;i++)  //对每一组背包进行遍历
    {
        if(m>1)
        {
            dfs(son[n][i],m-1); //对每个树状节点进行赋值
        }
        for(j=m-1;j>=1;j--) //体积由大到小遍历
        {
            V=j+1;  //父节点背包容量=子节点背包容量+1
            for(k=1;k<V;k++)  //对每组的所有元素选择进行遍历
            {
                dp[n][V]=max(dp[n][V],dp[n][V-k]+dp[son[n][i]][k]);
            }
        }
    }
}

int main()
{
    int i,j,k;
    while(~scanf("%d%d",&n,&m)&&(n||m))
    {
        memset(v,0,sizeof(v));
        memset(dp,0,sizeof(dp));
        for(i=0;i<=n;i++)
           son[i].clear();
        for(i=1;i<=n;i++)  //建立一个树
        {
            scanf("%d%d",&j,&v[i]);
            son[j].push_back(i);  //j的子节点是i
        }
        dfs(0,m+1);
        printf("%d\n",dp[0][m+1]);
    }
    return 0;
}

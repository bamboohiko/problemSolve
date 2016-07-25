#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m,v[223];
vector<int>son[223];
int dp[223][223];

void dfs(int n,int m){   //��״dp  nΪ���ڵ㣬mΪ��������V��
    int i,j,k,V,len=son[n].size();
    dp[n][1]=v[n];
    for(int i=0;i<len;i++)  //��ÿһ�鱳�����б���
    {
        if(m>1)
        {
            dfs(son[n][i],m-1); //��ÿ����״�ڵ���и�ֵ
        }
        for(j=m-1;j>=1;j--) //����ɴ�С����
        {
            V=j+1;  //���ڵ㱳������=�ӽڵ㱳������+1
            for(k=1;k<V;k++)  //��ÿ�������Ԫ��ѡ����б���
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
        for(i=1;i<=n;i++)  //����һ����
        {
            scanf("%d%d",&j,&v[i]);
            son[j].push_back(i);  //j���ӽڵ���i
        }
        dfs(0,m+1);
        printf("%d\n",dp[0][m+1]);
    }
    return 0;
}

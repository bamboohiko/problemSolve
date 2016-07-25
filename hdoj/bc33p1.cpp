#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
char dic[36] = {'0','1','2','3','4','5','6','7','8','9',
'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
'o','p','q','r','s','t','u','v','w','x','y','z'};
int a[110][210];
int char2num(char ch)
{
    if (ch >= '0' && ch <= '9') return ch-'0';
    return 10 + ch-'a';
}
int main()
{
    int n,b;
    char st[110];
    while (scanf("%d%d",&n,&b) != EOF)
    {
    	getchar();
        for (int i = 1;i <= n; i++)
        {
            gets(st);
            a[i][0] = strlen(st);
            int j = 0;
            for (int k = a[i][0]-1;k >= 0; k--)
                a[i][++j] = char2num(st[k]);
        }
        for (int i = 2;i <= n; i++)
        {
            int k = max(a[i-1][0],a[i][0]);
            for (int j = 1;j <= k; j++)
                a[i][j] = (a[i][j] + a[i-1][j])%b;
            a[i][0] = k;
        }
        int k = a[n][0];
        while (!a[n][k] && k > 1) k--;
        for (int i = k;i > 0; i--)
            printf("%c",dic[a[n][i]]);
        printf("\n");
    }    
    return 0;
}

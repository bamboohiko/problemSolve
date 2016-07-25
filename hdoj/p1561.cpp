#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;
struct Edge{
    int to,next;
};
Edge edge[210];
int head[210],cnt;
int f[210][210],a[210];
void build(int from,int to) {
    edge[++cnt].to = to;edge[cnt].next = head[from];head[from] = cnt;
}
void dfs(int s,int m) {
    for (int i = head[s];i ;i = edge[i].next) {
        int t = edge[i].to;
        dfs(t,m-1);
        for (int j = m;j >= 1; j--)
            for (int i = 1;i <= j; i++)
                f[s][j] = max(f[s][j],f[s][j-i]+f[t][i]);
    }
    for (int j = m;j >= 1; j--)
        f[s][j] = f[s][j-1] + a[s];
}
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        if (n == 0 && m == 0) break;
        memset(f,0,sizeof(f));
        memset(head,0,sizeof(head));cnt = 0;
        int from;
        for (int i = 1;i <= n; i++) {
            scanf("%d%d",&from,&a[i]);
            build(from,i);
        }
        dfs(0,m+1);
        printf("%d\n",f[0][m+1]);
    }
	return 0;
}


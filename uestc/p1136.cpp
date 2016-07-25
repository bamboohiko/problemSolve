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
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
struct Edge {
    int to,next;
};
Edge edge[210];
int head[210],cou = 0;
int f[210][210],v[210];
void build(int from,int to) {
    edge[++cou].to = to;edge[cou].next = head[from];head[from] = cou;
}
int dfs(int s,int m) {
    for (int i = head[s];i != -1; i = edge[i].next) {
        int t = edge[i].to;
        dfs(t,m-1);
        for (int k = m-1;k >= 0; k--)
            for (int j = k;j >= 1; j--)
                f[s][k] = max(f[s][k],f[s][k-j] + f[t][j]);
    }
    for (int i = m;i >= 1; i--) f[s][i] = f[s][i-1]+v[s];f[s][0] = 0;
    return f[s][m];
}
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        if (n == 0 && m == 0) break;
        int from,to;
        memset(head,-1,sizeof(head));cou = 0;
        for (int i = 1;i <= n; i++) {
            scanf("%d%d",&from,&v[i]);
            build(from,i);
        }
        memset(f,0,sizeof(f));
        printf("%d\n",dfs(0,m+1));
    }
	return 0;
}


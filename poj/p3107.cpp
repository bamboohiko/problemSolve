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
const int maxn = 5e4 + 10;
struct Edge{
    int to,next;
};
Edge edge[maxn << 1];
int head[maxn],cnt,ans;
int sz[maxn],f[maxn],n;
void build(int from,int to) {
    edge[++cnt].to = to;edge[cnt].next = head[from];head[from] = cnt;
    edge[++cnt].to = from;edge[cnt].next = head[to];head[to] = cnt;
}
void dfs(int s,int fa) {
    for (int i = head[s];i ;i = edge[i].next) {
        int t = edge[i].to;
        if (t == fa) continue;
        dfs(t,s);
        sz[s] += sz[t];
        f[s] = max(f[s],sz[t]);
    }
    sz[s]++;
    f[s] = max(f[s],n-sz[s]);
    ans = min(ans,f[s]);
}
int main() {
    while (scanf("%d",&n) != EOF) {
        memset(head,0,sizeof(head));cnt = 0;
        memset(f,0,sizeof(f));ans = n-1;
        memset(sz,0,sizeof(sz));
        int from,to;
        for (int i = 1;i < n; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        dfs(1,0);
        bool fr = true;
        for (int i = 1;i <= n;i++)
            if (f[i] == ans)
                if (fr) {printf("%d",i);fr = false;}
                else printf(" %d",i);
        printf("\n");
    }
	return 0;
}


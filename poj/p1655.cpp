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
const int maxn = 2e4 + 10;
struct Edge {
    int to,next;
};
Edge edge[maxn << 1];
int head[maxn],cnt,loc,n;
int sz[maxn],f[maxn];
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
    if (f[s] < f[loc] || (f[s] == f[loc] && s < loc)) loc = s;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        memset(head,0,sizeof(head));cnt = 0;
        memset(sz,0,sizeof(sz));
        memset(f,0,sizeof(f));
        loc = 0;f[loc] = n;
        int from,to;
        for (int i = 1;i < n; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        dfs(1,0);
        printf("%d %d\n",loc,f[loc]);
    }
	return 0;
}


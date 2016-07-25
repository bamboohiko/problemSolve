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
    int to,dis,next;
};
struct Len{
    int to,dis;
};
Edge edge[10010];
int cnt,head[10010];
Len f[10010][2];
void build(int from,int to,int dis) {
    edge[++cnt].to = to;edge[cnt].dis = dis;edge[cnt].next = head[from];head[from] = cnt;
}
void dfs1(int s,int fa) {
    for (int i = head[s] ;i ;i = edge[i].next) {
        int t = edge[i].to,dis = edge[i].dis;
        dfs1(t,s);
        if (f[t][0].dis + dis > f[s][0].dis) {
            f[s][1].dis = f[s][0].dis;f[s][1] = f[s][0];
            f[s][0].dis = f[t][0].dis+dis;f[s][0].to = t;
        } else if (f[t][0].dis + dis > f[s][1].dis) {
            f[s][1].dis = f[t][0].dis+dis;f[s][1].to = t;
        }
    }
}
void dfs2(int s,int fa) {
    for (int i = head[s];i ;i = edge[i].next) {
        int t = edge[i].to,dis = edge[i].dis;
        if (t == f[s][0].to) {
            if (f[s][1].dis + dis > f[t][0].dis) {
                f[t][1].dis = f[t][0].dis;f[t][1].to = f[t][0].to;
                f[t][0].dis = f[s][1].dis + dis;f[t][0].to = s;
            } else if (f[s][1].dis + dis > f[t][1].dis) {
                f[t][1].dis = f[s][1].dis + dis;f[t][1].to = s;
            }
        } else {
            if (f[s][0].dis + dis > f[t][0].dis) {
                f[t][1].dis = f[t][0].dis;f[t][1].to = f[t][0].to;
                f[t][0].dis = f[s][0].dis + dis;f[t][0].to = s;
            } else if (f[s][0].dis + dis > f[t][1].dis) {
                f[t][1].dis = f[s][0].dis + dis;f[t][1].to = s;
            }
        }
        dfs2(t,s);
    }
}
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        cnt = 0;
        memset(head,0,sizeof(head));
        memset(f,0,sizeof(f));
        int from,dis;
        for (int i = 2;i <= n; i++) {
            scanf("%d%d",&from,&dis);
            build(from,i,dis);
        }
        dfs1(1,0);
        dfs2(1,0);
        for (int i = 1;i <= n; i++)
            printf("%d\n",f[i][0].dis);
    }
	return 0;
}


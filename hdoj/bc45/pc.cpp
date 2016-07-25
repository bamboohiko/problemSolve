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
const int N = 50010;

int n,q;
int tim;

int num[N],siz[N],top[N],son[N];
int dep[N],tid[N],rank[N],fa[N];
int head[N],to[2*N],next[2*N],edge;

void addedge(int u,int v)
{
    to[edge]=v,next[edge]=head[u],head[u]=edge++;
    to[edge]=u,next[edge]=head[v],head[v]=edge++;
}
//树链剖分部分
void dfs1(int u,int father,int d) {
    dep[u]=d;
    fa[u]=father;
    siz[u]=1;
    for(int i=head[u]; ~i; i=next[i]) {
        int v=to[i];
        if(v!=father) {
            dfs1(v,u,d+1);
            siz[u]+=siz[v];
            if(son[u]==-1||siz[v]>siz[son[u]])
                son[u]=v;
        }
    }
}

void dfs2(int u,int tp) {
    top[u]=tp;
    tid[u]=++tim;
    rank[tid[u]]=u;
    if(son[u]==-1) return;
    dfs2(son[u],tp);
    for(int i=head[u]; ~i; i=next[i]) {
        int v=to[i];
        if(v!=son[u]&&v!=fa[u])
            dfs2(v,v);
    }
}

//线段树部分
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

int sum[4*N];

void PushUP(int rt) {
    sum[rt] = sum[rt<<1]^sum[rt<<1|1];
}

void Build(int l,int r,int rt) {
    if(l==r) {
        sum[rt]=num[rank[l]];
        return;
    }
    int mid=(l+r)>>1;
    Build(lson);
    Build(rson);
    PushUP(rt);
}

void Update(int x,int v,int l,int r,int rt) {
    if(l == r) {
        sum[rt] ^= v;
        return;
    }
    int mid = (l+r)>>1;
    if(x <= mid) Update(x,v,lson);
    else Update(x,v,rson);
}
int Query(int x,int y,int l,int r,int rt) {
    if(l == r) return sum[rt];
    int mid = (l+r)>>1,ans = 0;
    if (x <= mid) ans ^= Query(x,y,lson);
    if (y > mid) ans ^= Query(x,y,rson);
    return ans;
}

int ser(int x,int y) {
    int ans = 0;
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x,y);
        ans ^= Query(tid[top[x]],tid[x],1,n,1);
        x = fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans ^= Query(tid[x],tid[y],1,n,1);
    if (ans) return 1;
    else return -1;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        memset(head,-1,sizeof(head));
        memset(son,-1,sizeof(son));
        tim=0;
        edge=0;
        scanf("%d%d",&n,&q);
        int from,to,opt;
        for(int i=1; i < n; i++) {
            scanf("%d%d",&from,&to);
            addedge(from,to);
        }
        for(int i=1; i<=n; i++)
            scanf("%d",&num[i]);
        dfs1(1,0,0);
        dfs2(1,1);
        Build(1,n,1);
        while(q--) {
            scanf("%d%d%d",&opt,&from,&to);
            if(opt == 1)
                printf("%d\n",ser(from,to));
            else
                Update(tid[from],to,1,n,1);
        }
    }
    return 0;
}

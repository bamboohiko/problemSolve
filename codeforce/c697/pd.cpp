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
struct Edge{
    int to,next;
};
Edge edge[100100];
int head[100100],cou = 0,f[100100];
double  t[100100];
void build(int u,int v) {
    edge[++cou].to = v;edge[cou].next = head[u];head[u] =cou;
}
int dfs_fir(int u) {
    f[u] = 1;
    for (int i = head[u];i != 0;i = edge[i].next) {
        int v = edge[i].to;
        f[u] += dfs_fir(v);
    }
    return f[u];
}
int dfs(int u) {
    t[u] += 1;
    //cout << u << " " << t[u]<< endl;
    for (int i = head[u];i != 0;i = edge[i].next) {
        int v = edge[i].to;
        t[v] = t[u] + (f[u]-1-f[v])/2.0;
        dfs(v);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 2;i <= n; i++) {
        scanf("%d",&f[i]);
        build(f[i],i);
    }
    dfs_fir(1);
    dfs(1);
    for (int i = 1;i < n; i++) printf("%lf ",t[i]);
    printf("%lf\n",t[n]);
	return 0;
}

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
    int from,to,next,cost;
};
Edge V[1001000],edge[201000];
int f[100100],head[100100],ecou = 0;
int n,m;
double ans = 0;
stack<int> S;
bool cmp(Edge a,Edge b) {
    return a.cost < b.cost;
}
void build(int from,int to,int cost) {
    edge[++ecou].to = to;edge[ecou].cost = cost;
    edge[ecou].next = head[from];head[from] = ecou;
    edge[++ecou].to = from;edge[ecou].cost = cost;
    edge[ecou].next = head[to];head[to] = ecou;
}
int find(int k) {
    while (f[k] != k) {
        S.push(k);
        k = f[k];
    }
    while (!S.empty()) {
        int p = S.top();S.pop();
        f[p] = k;
    }
    return k;
}
int dfs(int fa,int u) {
    int num = 1;
    for (int i = head[u];i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) continue;
        int sav = dfs(u,v);
        num += sav;
        ans += sav*(n-sav)*edge[i].cost;
    }
    return num;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(head,0,sizeof(head));
        ecou = 0;ans = 0;
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n; i++) f[i] = i;
        for (int i = 1;i <= m; i++)
            scanf("%d%d%d",&V[i].from,&V[i].to,&V[i].cost);
        sort(V+1,V+m+1,cmp);
        int cnt = 0,sum = 0;
        for (int i = 1;i <= m; i++) {
            int a = find(V[i].from),b = find(V[i].to);
            if (a != b) {
                cnt++;
                sum += V[i].cost;
                f[a] = b;
                build(V[i].from,V[i].to,V[i].cost);
                if (cnt == n-1) break;
            }
        }
        dfs(0,1);
        double len = ans/(n*(n-1)/2);
        printf("%d %.2lf\n",sum,len);
    }
	return 0;
}

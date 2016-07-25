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
const int inf = 1e9 + 7;
int f[100100];
struct Edge {
    int from,to,dist;
};
bool cmp(Edge a,Edge b) {
    return a.dist < b.dist;
}
int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}
Edge edge[100100];
int cost[100100];
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        long long ans = 0;
        for (int i = 1;i <= n; i++) {
            f[i] = i;
            scanf("%d",&cost[i]);
            ans += cost[i];
        }
        for (int i = 0;i < m; i++)
            scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].dist);
        sort(edge,edge+m,cmp);
        int cou = 1;
        for (int i = 0;i < m && cou < n; i++) {
            int k1 = find(edge[i].from),k2 = find(edge[i].to),k;
            if (cost[k1] < cost[k2]) k = k2;
            else k = k1;
            if (k1 != k2 && cost[k] > edge[i].dist) {
                if (cost[k1] > cost[k2]) f[k] = k2;
                else f[k2] = k1;
                cou++;
                ans += edge[i].dist - cost[k];
            }
        }
        printf("%lld\n",ans);
    }
	return 0;
}

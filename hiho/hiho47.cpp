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
    int p,next;
};
Edge edge[1000100];
int G[100100],d[100100],esum;
void build(int from,int to) {
    esum++;edge[esum].p = to;edge[esum].next = G[from];G[from] = esum;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        esum = 0;
        memset(G,0,sizeof(G));
        memset(d,0,sizeof(G));
        int n,m;
        scanf("%d%d",&n,&m);
        int from,to;
        for (int i = 0;i < m; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
            d[to]++;
        }
        queue<int> Q;
        for (int i = 1;i <= n; i++)
            if (!d[i]) Q.push(i);
        int cou = 0;
        while (!Q.empty()) {
            int u = Q.front();Q.pop();
            for (int i = G[u]; i; i = edge[i].next) {
                int v = edge[i].p;
                if (!(--d[v])) Q.push(v);
            }
            cou++;
        }
        if (cou == n) printf("Correct\n");
        else printf("Wrong\n");
    }
    return 0;
}

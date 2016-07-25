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
int G[1010][1010],d[1010],cou,n;
bool vis[1010];
bool dfs(int k,int h) {
    //cout << k << ":"<< h <<endl;
    if (h == n) return true;
    for (int i = 1;i <= G[k][0]; i++) {
        int p = G[k][i];
        if (!vis[p]) {
            vis[p] = true;
            if (dfs(p,h+1)) return true;
            //else return false;
            vis[p] = false;
        }
    }
    return false;
}
int main() {
    while (scanf("%d",&n) != EOF) {
        memset(d,0,sizeof(d));
        memset(G,0,sizeof(G));
        int from,to,cou = 0,st = 1;
        for (int i = 1;i <= n; i++) {
            scanf("%d%d",&from,&to);
            if (from == to) continue;
            d[from]++;d[to]++;
            G[from][++G[from][0]] = to;
            G[to][++G[to][0]] = from;
        }
        for (int i = 2;i <= n; i++)
            if (d[i] < d[st]) st = i;
        memset(vis,0,sizeof(vis));
        queue<int> Q;
        Q.push(1);vis[1] = true;
        int sum = 0;
        while (!Q.empty()) {
            int s = Q.front();Q.pop();sum++;
            for (int i = 1;i <= G[s][0]; i++) {
                int t = G[s][i];
                if (!vis[t]) {
                    Q.push(t);
                    vis[t] = true;
                }
            }
        }
        //cout << sum << endl;
        memset(vis,0,sizeof(vis));
        if (sum != n) printf("NO\n");
        else if (dfs(st,1)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

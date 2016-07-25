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
typedef long long LL;
struct edge {
    LL from,to,dis;
};
struct node {
    LL p,dis;
    bool operator <(const node& rhs) const {
        return dis > rhs.dis;
    }
};
vector<edge> G;
LL bfs(int m) {
    priority_queue<node> Q;
    Q.push((node){1,0});
    LL i = 0;
    while (!Q.empty()) {
        node s = Q.top();Q.pop();
        if (s.p >= m) return s.dis;
        while (i < G.size()) {
            if (G[i].from > s.p) break;
            if (G[i].from <= s.p && G[i].to > s.p)
                Q.push((node){G[i].to,s.dis + G[i].dis});
            i++;
        }
    }
    return -1;
}
bool cmp(edge a,edge b) {
    return a.from < b.from;
}
int main()
{
    int t,turn = 0;
    scanf("%d",&t);
    while (turn++ < t) {
        LL n,m;
        scanf("%I64d%I64d",&n,&m);
        G.clear();
        LL from,to,dist;
        for (int i = 0;i < n; i++) {
            scanf("%I64d%I64d%I64d",&to,&from,&dist);
            if (from >= to) continue;
            G.push_back((edge){from,to,dist});
        }
        sort(G.begin(),G.end(),cmp);
        printf("Case #%d: %I64d\n",turn,bfs(m));
    }
	return 0;
}

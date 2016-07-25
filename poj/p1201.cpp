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
const int maxn = 1e5 + 100;
struct Edge{
    int to,next,dist;
};
Edge edge[maxn*4];
vector<Edge> sav;
set<int> num;
map<int,int> dic;
bool vis[maxn];
int head[maxn],dis[maxn],cou = 0;
queue<int> Q;
void build(int from,int to,int dist) {
    edge[++cou].to = to;edge[cou].dist = dist;
    edge[cou].next = head[from];head[from] = cou;
}
int spfa(int s,int t) {
    memset(vis,false,sizeof(vis));
    memset(dis,INF,sizeof(dis));dis[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();Q.pop();
        if (vis[u]) continue;
        //cout << u << endl;
        vis[u] = true;
        for (int i = head[u];i != -1;i = edge[i].next) {
            int v = edge[i].to;
            if (!vis[v] && dis[u] + edge[i].dist < dis[v]) {
                dis[v] = dis[u] + edge[i].dist;
                Q.push(v);
            }
        }
        vis[u] = false;
    }
    //for (int i = s;i >= t; i--) cout << dis[i]  << endl;
    return -dis[t];
}
int main() {
    int n;
    scanf("%d",&n);
    memset(head,-1,sizeof(head));cou = 0;
    Edge e;
    for (int i = 1;i <= n; i++) {
        scanf("%d%d%d",&e.to,&e.next,&e.dist);e.to--;
        num.insert(e.to);num.insert(e.next);sav.push_back(e);
    }
    int m = 0;
    for (set<int>::iterator i = num.begin();i != num.end(); i++) {
        dic[(*i)] = ++m;
        if (m > 1) {build(m,m-1,0);build(m-1,m,1);}
    }
    for (int i = 0;i < sav.size(); i++)
        build(dic[sav[i].next],dic[sav[i].to],-sav[i].dist);
    printf("%d\n",spfa(m,1));
	return 0;
}


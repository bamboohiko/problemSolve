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
    int to,dis,next;
};
struct point{
    int p,dis;
    bool operator <(const point &rhs) const{
        return dis < rhs.dis;
    }
};
Edge edge[200100];
int head[5010],cou = 0,d1[5010],d2[5010];
priority_queue<point> Q;
void build(int from,int to,int dis) {
    edge[++cou].to = to;edge[cou].dis = dis;edge[cou].next = head[from];head[from] = cou;
}
void dijk() {
    Q.push((point){1,0});
    while (!Q.empty()) {
        point s = Q.top();Q.pop();
        if (d2[s.p] < s.dis) continue;
        for (int i = head[s.p];i ;i = edge[i].next) {
            int t = edge[i].to;
            int sav = s.dis + edge[i].dis;
            if (d1[t] > sav) {
                swap(d1[t],sav);
                Q.push((point){t,d1[t]});
            }
            if (d2[t] > sav && d1[t] < sav) {
                d2[t] = sav;
                Q.push((point){t,d2[t]});
            }
        }
    }
}
int main() {
    int n,m;
    int from,to,dis;
    scanf("%d%d",&n,&m);
    memset(d1,INF,sizeof(d1));d1[1] = 0;
    memset(d2,INF,sizeof(d2));
    for (int i = 1;i <= m; i++) {
        scanf("%d%d%d",&from,&to,&dis);
        build(from,to,dis);
        build(to,from,dis);
    }
    dijk();
    //for (int i = 1;i <= n; i++) cout << d1[i] << " " << d2[i] << endl;
    printf("%d\n",d2[n]);
	return 0;
}


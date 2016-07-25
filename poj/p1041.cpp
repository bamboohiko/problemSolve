//欧拉回路
//判断点的读书是否满足回路存在条件（均为偶数）后dfs
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
    int to,num,next;
};
vector<int> ans;
Edge edge[4010];
int d[50],head[50],cou = 0;
bool vis[4010];
bool cmp(Edge a,Edge b) {
    return a.num > b.num;
}
void build(int from,int to,int num) {
    edge[++cou].to = to;edge[cou].num = num;
    edge[cou].next = head[from];head[from] = cou;
    edge[++cou].to = from;edge[cou].num = num;
    edge[cou].next = head[to];head[to] = cou;
}
void dfs(int u) {
    for (int i = head[u];i ;i = edge[i].next) {
        Edge e = edge[i];
        if (vis[e.num]) continue;
        vis[e.num] = true;
        dfs(e.to);
        ans.push_back(e.num);
    }
}
int main() {
    int n = 44;
    int from,to,num;
    while (1) {
        ans.clear();
        memset(d,0,sizeof(d));
        memset(head,0,sizeof(head));cou = 0;
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&from,&to);
        if (from == 0 && to == 0) break;
        while (1) {
            if (from == 0 && to == 0) break;
            scanf("%d",&num);
            build(from,to,num);
            d[from]++;d[to]++;
            scanf("%d%d",&from,&to);
        }
        bool pass = true;
        for (int i = 1;i <= n; i++)
            if (d[i]&1) {
                pass = false;
                break;
            }
        if (pass) {
            dfs(1);
            for (int i = ans.size()-1;i >= 1; i--) printf("%d ",ans[i]);
            printf("%d\n",ans[0]);
        } else puts("Round trip does not exist.");
    }
	return 0;
}

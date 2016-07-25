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
const int maxn = 110;
struct Edge{
    int to,num,next;
};
int head[110],cou;
Edge edge[220];
bool vis[110];
void build(int from,int to,int num) {
    edge[++cou].to = to;edge[cou].next = head[from];edge[cou].num = num;head[from] = cou;
    edge[++cou].to = from;edge[cou].next = head[to];edge[cou].num = num;head[to] = cou;
}
int bfs(int s,int k1,int k2) {
    int ans = 0;
    memset(vis,0,sizeof(vis));
    queue<int> Q;
    Q.push(s);vis[s] = true;
    while (!Q.empty()) {
        int s = Q.front();Q.pop();
        for (int i = head[s];i ;i = edge[i].next) {
            int t = edge[i].to;
            if (edge[i].num == k1 || edge[i].num == k2 || vis[t]) continue;
            Q.push(t);
            vis[t] = true;
        }
        ans++;
    }
    return ans;
}
int main() {
    int t,n;
    int from,to;
    scanf("%d",&t);
    while (t--) {
        memset(head,0,sizeof(head));
        int m = 0;cou = 0;
        scanf("%d",&n);
        for (int i = 0; i <= n; i++) {
            scanf("%d%d",&from,&to);
            build(from,to,++m);
        }
        int ans = 0;
        for (int i = 0;i <= m; i++)
            for (int j = i+1;j <= m; j++) {
                if (bfs(1,i,j) == n) ans++;
                //cout << i << " " << j << endl;
            }
        printf("%d\n",ans);
    }
	return 0;
}


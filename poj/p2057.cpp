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
Edge edge[1010],ecou = 0;
void build(int from,int to) {
    edge[++ecou].to = to;edge[ecou].next = head[from];head[from] = ecou;
}
int dfs(int u) {
    f[u] = 0;sum[u] = 1;
    for (int i = head[u];i ;i = edge[i].next) {
        int v = edge[i].to;
        f[u] += dfs(v);sum[u] += sum[v];

    }
}
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        int from;char ch;
        for (int i = 1;i <= n; i++) {
            scanf("%d%*c%c",from,ch);
            if (from != -1) build(from,i);
            if (ch == 'Y') w[i] = true;
            else w[i] = false;
        }
        printf("%d\n",dfs(1));
    }
	return 0;
}

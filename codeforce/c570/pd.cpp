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
const int MAXN = 5e5 + 10;
const int MAXM = 5e5 + 10;
struct Edge{
    int to,next;
};
Edge edge[MAXM];
int head[MAXN],tot = 0;
void build(int from,int to) {
    edge[tot] = to;edge[tot] = head[from];head[from] = tot++;
}

int main() {
    int n,m,fa;
    memset(head,-1,sizeof(head));
    for (int i = 2;i <= n; i++) {
        scanf("%d",&fa);
        build(fa,i);
    }
    memset(vis,false,sizeof(vis));
    dfs(1);

	return 0;
}


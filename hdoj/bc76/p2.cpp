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
Edge edge[200100];
int head[200100],cou;
void build(int from,int to) {
    edge[++cou].to = to;edge[cou].next = head[from];head[from] = cou;
}
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        memset(head,0,sizeof(head));cou = 0;
        for (int i = 2;i <= n; i++) {
            scanf("%d",&from);
            build(from,i);
        }
        dfs(1);
    }
	return 0;
}


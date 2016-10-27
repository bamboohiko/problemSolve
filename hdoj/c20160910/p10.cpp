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
Edge edge[100100];
int head[100100],loc[100100],tree[100100];
bool root[100100];
int n,ecou;
LL ans = 0,k,a[100100];
void build(int u,int v) {
    edge[++ecou].to = v;edge[ecou].next = head[u];head[u] = ecou;
}
bool cmp(int u,int v) {
    return a[u] < a[v];
}
void ins(int k,int add) {
    for (int i = k;i <= n; i += i&(-i))
        tree[i] += add;
}
int sum(int k) {
    int ans = 0;
    for (int i = k;i > 0;i -= i&(-i))
        ans += tree[i];
    return ans;
}
int biser(LL k) {
    int l = 0,r = n+1;
    while (l+1 < r) {
        int mid = (l + r) >> 1;
        if (a[mid] <= k) l = mid;
        else r = mid;
    }
    return l;
}
void dfs(int u) {
    int num;
    if (a[u]) num = biser(k/a[u]);
    else num = n;
    ans += sum(num);
    //int sav = sum(num);
    //ans += sav;
    //cout << (k/a[u]) << " " << num << " " << sav << endl;
    for (int i = head[u];i ;i = edge[i].next) {
        int v = edge[i].to;
        ins(loc[u],1);
        dfs(v);
        ins(loc[u],-1);
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%I64d",&n,&k);
        memset(head,0,sizeof(head));
        memset(root,0,sizeof(root));
        memset(tree,0,sizeof(tree));
        ecou = 0;
        for (int i = 1;i <= n; i++) {
            scanf("%I64d",&a[i]);
            loc[i] = i;
        }
        sort(loc+1,loc+n+1,cmp);
        ans = 0;
        int u,v;
        for (int i = 1;i < n; i++) {
            scanf("%d%d",&u,&v);
            build(u,v);
            root[v] = true;
        }
        for (int i = 1;i <= n; i++)
            if (!root[i]) {
                dfs(i);
                break;
            }
        printf("%I64d\n",ans);
    }
	return 0;
}

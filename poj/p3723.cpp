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
    int from,to,dis;
};
Edge G[50100];
int f[20100];
stack<int> S;
bool cmp(Edge a,Edge b) {
    return a.dis > b.dis;
}
int find(int k) {
    while (f[k] != k) {
        S.push(k);
        k = f[k];
    }
    while (!S.empty()) {
        int p = S.top();S.pop();
        f[p] = k;
    }
    return k;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m,r;
        int from,to,dis;
        scanf("%d%d%d",&n,&m,&r);
        for (int i = 0;i < n+m; i++) f[i] = i;
        for (int i = 0;i < r; i++) {
            scanf("%d%d%d",&G[i].from,&G[i].to,&G[i].dis);
            G[i].to += n;
        }
        sort(G,G+r,cmp);
        int ans = (n+m)*10000;
        for (int i = 0;i < r; i++) {
            int a = find(G[i].from),b = find(G[i].to);
            //cout << a << " " << b << endl;
            if (a != b) {
                f[b] = a;
                ans -= G[i].dis;
            }
        }
        printf("%d\n",ans);
     }
	return 0;
}


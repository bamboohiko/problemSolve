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
const int maxn = 20000 + 100;
const int maxm = 100000 + 100;
struct Edge{
    int from,to,dist;
};
struct Qes{
    int d,loc;
};
int f[maxn],num[maxn],sav[5010];
Edge edge[maxm];
Qes qes[5010];
bool cmp(Edge a,Edge b) {
    return a.dist < b.dist;
}
bool cmp2(Qes a,Qes b) {
    return a.d < b.d;
}
int find(int k) {
    stack<int> S;
    while (f[k] != k) {
        S.push(k);
        k = f[k];
    }
    while (!S.empty()) {
        int t = S.top();S.pop();
        f[t] = k;
    }
    return k;
}
int fig(int k) {
    return k*(k-1);
}
int main() {
    int t;
    int n,m,q;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d",&n,&m,&q);
        for (int i = 1;i <= n; i++) {
            f[i] = i;
            num[i] = 1;
        }
        for (int i = 0;i < m; i++)
            scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].dist);
        sort(edge,edge+m,cmp);
        for (int i = 0;i < q; i++) {
            scanf("%d",&qes[i].d);
            qes[i].loc = i;
        }
        sort(qes,qes+q,cmp2);
        int j = 0,ans = 0;
        for (int i = 0;i < q; i++) {
            while (j < m && edge[j].dist <= qes[i].d) {
                int a = find(edge[j].from);
                int b = find(edge[j].to);
                if (a != b) {
                    f[b] = a;
                    ans = ans - fig(num[a]) - fig(num[b]) + fig(num[a] + num[b]);
                    num[a] += num[b];
                }
                j++;
            }
            sav[qes[i].loc] = ans;
        }
        for (int i = 0;i < q; i++)
            printf("%d\n",sav[i]);
    }
	return 0;
}


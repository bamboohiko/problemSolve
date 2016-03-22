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
const int maxn = 1e5;
int f[maxn + 100];
bool vis[maxn + 100];
stack<int> S;
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
    int a,b;
    for ( ; ; ) {
        for (int i = 1;i < maxn; i++) f[i] = i;
        memset(vis,false,sizeof(vis));
        int ok = 1,coun = 0,coum = 0;
        scanf("%d%d",&a,&b);
        if ((a == -1) && (b == -1)) break;
        do {
            if (a == 0 && b == 0) break;
            if (!vis[a]) {vis[a] = true;coun++;}
            if (!vis[b]) {vis[b] = true;coun++;}
            coum++;
            a = find(a),b = find(b);
            if (a != b) f[a] = b;
            else ok = 0;
            scanf("%d%d",&a,&b);
        } while (a && b);
        if (coum && coun != coum + 1) ok = 0;
        if (ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

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
const int maxn = 1e5 + 10;
int f[maxn], sum[maxn];
stack<int> S;
int find(int k) {
    while (f[k] != k) {
        S.push(k);
        k = f[k];
    }
    while (!S.empty()) {
        int p = S.top();S.pop();
        sum[p] += sum[f[p]];
        f[p] = k;
    }
    return k;
}
int main() {
    //freopen("data1.in","r",stdin);
    //freopen("data1.out","w",stdout);
    int n,m;
    int x,y,a,b,c;
    while (scanf("%d%d",&n,&m) != EOF) {
        int ans = 0;
        memset(sum,0,sizeof(sum));
        for (int i = 0;i <= n; i++) f[i] = i;
        for (int i = 1;i <= m; i++) {
            scanf("%d%d%d",&a,&b,&c);
            int x = find(a-1),y = find(b);
            if (x == y && sum[a-1] + c != sum[b]) ans++;
            if (x > y) {f[y] = x;sum[y] = sum[a-1] + c - sum[b];}
            if (y > x) {f[x] = y;sum[x] = sum[b] - c - sum[a-1];}
        }
        printf("%d\n",ans);
    }
	return 0;
}

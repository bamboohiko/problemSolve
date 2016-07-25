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
const int maxn = 1e5 + 100;
int f[maxn],sum[maxn];
stack<int> S;
int find(int k) {
    while (f[k] != k) {
        S.push(k);
        k = f[k];
    }
    int p;
    while (!S.empty()) {
        p = S.top();S.pop();
        f[p] = k;
    }
    return k;
}
int main() {
    int t,n;
    int x,y,v;
    scanf("%d",&t);
    while (t--) {
        memset(sum,0,sizeof(sum));
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) f[i] = i;
        for (int i = 1;i < n; i++) {
            scanf("%d%d%d",&x,&y,&v);
            x = find(x);y = find(y);
            if (!v) f[x] = y;
        }
        for (int i = 1;i <= n; i++) sum[find(i)]++;
        int ans = 0;
        for (int i = 1;i <= n; i++) ans ^= sum[find(i)];
        printf("%d\n",ans);
     }
	return 0;
}

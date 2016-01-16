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
int f[1010];
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
    int t,n,m,a,b;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n; i++) f[i] = i;
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&a,&b);
            a = find(a),b = find(b);
            f[a] = b;
        }
        int ans = 0;
        for (int i = 1;i <= n; i++) {
            if (f[i] == i) ans++;
        }
        printf("%d\n",ans);
    }
	return 0;
}


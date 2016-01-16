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
const int maxn = 3e4 + 10;
int f[maxn];
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
    int n,m,s,a,b;
    while (scanf("%d%d",&n,&m) != EOF) {
        if (n == 0 && m == 0) break;
        for (int i = 0;i < n; i++) f[i] = i;
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&s,&a);
            for (int j = 1;j < s; j++) {
                scanf("%d",&b);
                int fa = find(a),fb = find(b);
                if (fa < fb) f[fb] = fa;
                else f[fa] = fb;
            }
        }
        int ans = 1;
        for (int i = 1;i < n; i++)
            if (find(i) == 0) ans++;
        printf("%d\n",ans);
    }
	return 0;
}


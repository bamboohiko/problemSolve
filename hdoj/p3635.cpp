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
const int maxn = 1e4 + 100;
int f[maxn],dis[maxn],num[maxn];
stack<int> S;
int find(int k) {
    while (f[k] != k) {
        S.push(k);
        k = f[k];
    }
    while (!S.empty()) {
        int p = S.top();S.pop();
        dis[p] += dis[f[p]];f[p] = k;
    }
    return k;
}
int main() {
    int n,m,t;
    int a,b;
    char ch;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        printf("Case %d:\n",ca);
        scanf("%d%d%*c",&n,&m);
        for (int i = 1;i <= n; i++) {f[i] = i;dis[i] = 0;num[i] = 1;}
        for (int i = 1;i <= m; i++) {
            ch = getchar();
            if (ch == 'T') {
                scanf("%d%d",&a,&b);
                a = find(a);b = find(b);
                if (a != b) {f[a] = b;num[b] += num[a];dis[a]++;}
            } else {
                scanf("%d",&a);
                b = find(a);
                printf("%d %d %d\n",b,num[b],dis[a]);
            }
            getchar();
        }
    }
	return 0;
}


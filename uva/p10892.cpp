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
const int maxn = 44722;
int prime[maxn+10],a[maxn],f[maxn][35],cnt = 0;
bool vis[maxn+10];
void init() {
    memset(vis,0,sizeof(vis));
    for (int i = 2;i <= maxn; i++)
        if (!vis[i]) {
            prime[cnt++] = i;
            for (int j = i+i;j <= maxn; j+=i) vis[j] = true;
        }
}
int main() {
    init();
    int n,m,ca;
    while (scanf("%d",&n) != EOF && n) {
        memset(a,0,sizeof(a));
        ca = n;m = 0;
        for (int i = 0;i < cnt; i++) {
            m++;
            while (n%prime[i] == 0) {n /= prime[i];a[m]++;}
            if (a[m] == 0) m--;
            if (n == 1) break;
        }
        if (n > 1) a[++m] = 1;
        long long ans = 1;
        for (int i = 1;i <= m; i++) {
            ans *= (a[i] << 1|1);
        }
        printf("%d %lld\n",ca,(ans+1) >> 1);
    }
	return 0;
}

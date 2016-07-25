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
const int maxn = 2e6;
bool prime[maxn],vis[1010];
int a[1010],cou[1010];
int main() {
    for (int i = 2;i <= maxn; i++)
        if (!prime[i])
            for (int j = i+i;j <= maxn; j += i) prime[j] = true;
    int n,sum = 0;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    for (int i = 1;i <= n; i++)
        for (int j = 1;j <= n; j++)
            if (i != j && prime[a[i]+a[j]]) {cou[i]++;sum++;}
    int ans = n;
    while (true) {
        if (!sum) break;
        int m = 0;
        for (int i = 1;i <= n; i++)
            if (!vis[i] && cou[i] > cou[m]) m = i;
        ans--;sum -= cou[m]*2;vis[m] = true;
        for (int i = 1;i <= n; i++)
            if (!vis[i] && prime[a[m]+a[i]]) cou[i]--;
    }
    printf("%d\n",ans);
    bool fir = true;
    for (int i = 1;i <= n; i++)
        if (!vis[i]) {
            if (fir) {printf("%d",a[i]);fir = false;}
            else printf(" %d",a[i]);
        }
    printf("\n");
	return 0;
}


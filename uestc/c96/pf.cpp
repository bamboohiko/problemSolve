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
int f[maxn];
int main() {
    memset(f,INF,sizeof(f));
    int n,m = 15,a,k;
    for (int i = 1;i <= m; i++) scanf("%d",&f[1<<(i-1)]);
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a);
        int sum = 0,k,sav;
        while (a--) {
            scanf("%d",&k);
            sum += 1<<(k-1);
        }
        scanf("%d",&sav);
        f[sum] = min(sav,f[sum]);
    }
    for (int i = 1;i <= (1<<m)-1; i++)
        for (int j = i;j ; j = (j-1)&i)
            f[i] = min(f[i],f[j]+f[i^j]);
    printf("%d\n",f[(1<<m)-1]);
	return 0;
}

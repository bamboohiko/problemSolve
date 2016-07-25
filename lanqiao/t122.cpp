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
const LL mod = 100000007;
LL f[10100];
int main() {
    int n,s,a,b;
    scanf("%d%d%d%d",&n,&s,&a,&b);
    int m = n*(n-1)/2;
    f[0] = 1;
    for (int i = 1;i < n; i++)
        for (int j = m;j >= i; j--)
            f[j] = (f[j] + f[j-i])%mod;
    //for (int i = 1;i <= m; i++) cout << f[i] << " ";cout << endl;
    LL ans = 0;
    for (int i = 0;i <= m; i++)
        if ((s+m*b-i*(a+b))%n == 0) ans = (ans + f[i])%mod;
    printf("%lld\n",ans);
	return 0;
}




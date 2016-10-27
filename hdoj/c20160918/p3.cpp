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
const LL mod = 1e9 + 7;
LL inv[100100];
void init() {
    int maxn = 100000;
    inv[1] = 1;
    for (int i = 2; i <= maxn; i++)
        inv[i] = inv[mod%i]*(mod-mod/i)%mod;
}
int main() {
    init();
    int t;
    scanf("%d",&t);
    int m,n,k;
    while (t--) {
        scanf("%d%d%d",&n,&m,&k);
        if (m == 1) printf("%d\n",n);
        else if (n-m-m*k < 0) printf("%d\n",0);
        else {
            LL ans = n;
            int a = m + n-m-m*k-1,b = n-m-m*k;
            if (b < a-b) b = a-b;
            //cout << a << " " << b << endl;
            for (int i = b+1;i <= a; i++) ans = ans*i%mod;
            for (int i = 2;i <= a-b; i++) ans = ans*inv[i]%mod;
            ans = ans*inv[m]%mod;
            printf("%I64d\n",ans);
        }
    }
	return 0;
}

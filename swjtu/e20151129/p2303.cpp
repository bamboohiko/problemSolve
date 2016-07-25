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
const LL mod = 1000000007;
int f[110][100];
void add(int sum,int a,int b) {
    for (int i = 1;i <= f[a][0] || i < f[b][0]; i++) {
        int sav = f[a][i] + f[b][i] + f[sum][i];
        f[sum][i+1] = sav>>1;f[sum][i] = sav&1;
    }
    f[sum][0] = f[a][0];
    if (f[sum][f[sum][0]+1]) f[sum][0]++;
}
LL pow2(int b) {
    LL ans = 1,a = 2;
    while (b) {
        if (b&1) ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}
int main() {
    f[1][0] = 1;f[1][1] = 1;
    f[2][0] = 1;f[2][1] = 1;
    for (int i = 3;i <= 100; i++) {
        add(i,i-1,i-2);
    }
    /*
    for (int i = 1;i <= 100; i++) {
        for (int j = 1;j <= f[i][0]; j++) printf("%d",f[i][j]);
        printf("\n");
    }
    */
    int n;
    while (scanf("%d",&n) != EOF) {
        printf("%lld\n",(pow2(f[n][0])+mod-1)%mod);
    }
	return 0;
}

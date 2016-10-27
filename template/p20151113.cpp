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
LL f[100];
LL mul[20];
void init() {
    mul[0] = 1;
    for (int i = 1;i <= 10; i++) mul[i] = mul[i-1]*i;
}
LL fig(int k,int v,int p) {
    LL ans = 1;
    ans = mul[k]/mul[p]/mul[k-p*v];
    for (int i = 1;i <= p; i++) ans /= mul[v];
    return ans;
}
int main() {
    init();
    int n;
    while (scanf("%d",&n) != EOF) {
        memset(f,0,sizeof(f));
        f[0] = 1;
        for (int i = 1;i <= n; i++)
            for (int k = n; k >= i; k--)
                for (int j = 1;j*i <= k; j++)
                    f[k] = f[k] + f[k-j*i]*fig(k,i,j);
        printf("%d\n",f[n]);
    }
	return 0;
}

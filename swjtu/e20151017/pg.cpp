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
typedef long long LL;
LL fig(LL x,int i) {
    LL t = (x + 1)/(1 << i);
    LL ans = t/2*(1 << i);
    if (t%2) ans += (x+1 - (t << i));
    //printf("%d %d %d\n",x,i,ans);
    return ans;
}
int main() {
    int t;
    scanf("%d",&t);
    LL a,b,c,d,mod;
    while (t--) {
        scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&mod);
        LL ans = 0;
        for (int i = 0;i < 31; i++) {
            int k1 = fig(b,i) - fig(a-1,i);
            int k2 = fig(d,i) - fig(c-1,i);
            //printf("%d %d\n",k1,k2);
            ans = (ans + (k1*(d-c+1-k2) + k2*(b-a+1-k1))%mod*(1 << i)%mod)%mod;
        }
        printf("%lld\n",ans);
    }
	return 0;
}


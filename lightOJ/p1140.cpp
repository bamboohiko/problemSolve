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
LL fig(LL k) {
    if (k < 0) return 0;
    LL ans = 0,i = 1;
    while (k > i) {
        LL a = k/(i*10),b = k%(i*10);
        if (b >= i) ans += a*i;
        else ans += (a-1)*i + b+1;
        i *= 10;
    }
    return ans + 1;
}
int main() {
    int t;
    scanf("%d",&t);
    LL l,r;
    for (int ca = 1;ca <= t; ca++) {
        scanf("%lld%lld",&l,&r);
        printf("Case %d: %lld\n",ca, fig(r)-fig(l-1));
    }
	return 0;
}


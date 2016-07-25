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
    LL ans = 0,p = 1;
    while (k > p) {
        LL m = p*10;
        LL l = k/m,r = k%m;
        ans += (l-1)*p + min(p,r+1);
        p *= 10;
    }
    return ans+1;
}
int main() {
    LL a,b;
    while (scanf("%lld%lld",&a,&b) != EOF) {
        if (a == -1 && b == -1) break;
        printf("%lld\n",fig(b)-fig(a-1));
    }
	return 0;
}


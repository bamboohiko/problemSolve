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
const int maxn = 1e6 + 100;
long long n,seed;
LL x,y;
LL maxl,minl,maxr,minr;
long long rand(long long l, long long r) {
    static long long mo=1e9+7, g=78125;
    return l+((seed*=g)%=mo)%(r-l+1);
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        cin >> n >> seed;
        maxl = maxr = -3e9;
        minl = minr = 3e9;
        for (int i = 0; i < n; i++) {
            x = rand(-1000000000, 1000000000);
            y = rand(-1000000000, 1000000000);
            maxl = max(maxl,x+y);
            minl = min(minl,x+y);
            maxr = max(maxr,x-y);
            minr = min(minr,x-y);
        }
        printf("%d\n",max(maxl-minl,maxr-minr));
    }
    return 0;
}


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
int main() {
    int t;
    LL n,k;
    scanf("%d",&t);
    while (t--) {
        scanf("%I64d%I64d",&n,&k);
        LL ans = 1;
        if (n < (k+1)*k/2) {
            ans = -1;
        } else if (n < (k+3)*k/2) {
            LL inc = n - (k+1)*k/2;
            for (int i = k;i >= 1; i--) {
                if (i + inc > k) ans = (ans*(i+1))%mod;
                else ans = (ans*i)%mod;
            }
        } else {
            LL inc = n - (k+1)*k/2;
            LL x = inc/k,y = inc%k;
            for (int i = k;i >= 1; i--) {
                if (i + y > k) ans = (ans*(i+x+1))%mod;
                else ans = (ans*(i+x))%mod;
            }
        }
        printf("%I64d\n",ans);
    }
	return 0;
}


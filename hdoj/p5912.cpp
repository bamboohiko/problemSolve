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
LL a[20],b[20];
LL gcd(LL a,LL b) {
    while (b) {
        LL t = a;a = b;b = t%b;
    }
    return a;
}
int main() {
    int t,n,ca = 0;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%I64d",&a[i]);
        for (int i = 1;i <= n; i++) scanf("%I64d",&b[i]);
        LL p = b[n],q = a[n];
        for (int i = n-1;i >= 1; i--) {
            LL p1 = p,q1 = q;
            p = q1*b[i];q = a[i]*q1 + p1;
            LL d = gcd(p,q);
            p /= d;q /= d;
        }
        LL d = gcd(p,q);
        p /= d;q /= d;
        printf("Case #%d: %I64d %I64d\n",++ca,p,q);
    }
	return 0;
}

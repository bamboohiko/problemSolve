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
LL a[100100];
LL exgcd(LL a,LL b,LL &x,LL &y) {
    if (a == 0 && b == 0) return -1;
    if (b == 0) {x = 1,y = 0;return a;}
    LL d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
LL inv(LL a,LL n) {
    LL x,y;
    LL d = exgcd(a,n,x,y);
    if (d == 1) return (x%n + n)%n;
    else return -1;
}
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        printf("Case #%d:\n",ca);
        int n,x,y;LL m,num = 1;
        scanf("%d%lld",&n,&m);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&x);
            if (x == 1) {
                scanf("%d",&a[i]);
                num = num*a[i]%m;
            } else {
                scanf("%d",&y);
                int k = inv(a[y],m);
                if (k > 0) num = num*inv(a[y],m)%m;
                else num = num/(a[y]%m);
            }
            printf("%lld\n",num);
        }
    }
	return 0;
}


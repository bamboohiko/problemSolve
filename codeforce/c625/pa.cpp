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
int main() {
    LL n;
    LL a,b,c;
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
    if (a <= b-c) printf("%I64d\n",n/a);
    else {
        LL ans = 0;
        if (n >= b) {ans = (n-b)/(b-c);n -= ans*(b-c);}
        while (n >= b) {n -= b-c;ans++;}
        if (a < b) {
            ans += n/a;n -= n/a*a;
        } else {
            ans += n/b;n -= n/b*b;
        }
        printf("%I64d\n",ans);
    }
	return 0;
}


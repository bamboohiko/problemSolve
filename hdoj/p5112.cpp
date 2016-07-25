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
const int maxn = 1e6 + 10;
int a[maxn];
int main() {
    int t,n;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        int p = 1,ans = 0,k;
        scanf("%d",&n);
        scanf("%d",&a[p]);
        for (int i = 2;i <= n; i++) {
            scanf("%d",&k);
            while (p > 0 && k < a[p]) {p--;ans++;}
            a[++p] = k;
        }
        printf("Case #%d: %d\n",ca ,ans);
    }
	return 0;
}


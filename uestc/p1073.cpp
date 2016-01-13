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
const int maxn = 1e5 + 100;
int n,m;
LL a[maxn],t[maxn];
void add(int k,int val) {
    for (int i = k;i <= n; i += i&(-i)) t[i] += val;
}
LL query(int k) {
    LL ans = 0;
    for (int i = k;i > 0; i -= i&(-i)) ans += t[i];
    return ans;
}
int main() {
    int l,r,k;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        add(i,a[i]);
    }
    scanf("%d",&m);
    for (int i = 1;i <= m; i++) {
        scanf("%d%d%d",&k,&l,&r);
        if (k == 1) {add(l,r-a[l]);a[l] = r;}
        if (k == 2) printf("%lld\n",query(r)-query(l-1));
    }
	return 0;
}

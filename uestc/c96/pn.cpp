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
const LL mod = 1000000009;
set<int> S;
map<int,int> D;
int a[maxn];
LL t[maxn*4],f[maxn];
LL query(int l,int r,int k,int x,int y) {
    if (x <= l && r <= y) return t[k];
    int mid = (l + r) >> 1;LL s1 = 0,s2 = 0;
    if (x <= mid) s1 = query(l,mid,k<<1,x,y);
    if (y > mid) s2 = query(mid+1,r,k<<1|1,x,y);
    return (s1 + s2)%mod;
}
void updata(int l,int r,int k,int x,LL val) {
    if (l == r) {
        t[k] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) updata(l,mid,k<<1,x,val);
    else updata(mid+1,r,k<<1|1,x,val);
    t[k] = (t[k<<1] + t[k<<1|1])%mod;
}
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        S.insert(a[i]);S.insert(a[i]-k);S.insert(a[i]+k);
    }
    int m = 0;
    for (set<int>::iterator i = S.begin();i != S.end(); i++) D[*i] = ++m;
    LL sum = 0;
    for (int i = 1;i <= n; i++) {
        f[i] = query(1,m,1,D[a[i]-k],D[a[i]+k]);
        updata(1,m,1,D[a[i]],f[i]+1);
        sum = (sum + f[i])%mod;
    }
    printf("%lld\n",sum);
	return 0;
}

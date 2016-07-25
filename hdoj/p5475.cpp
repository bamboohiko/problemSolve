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
const int maxn = 1e5 + 10;
typedef long long LL;
LL n,m,tree[4*maxn];
void build(int l,int r,int k) {
    if (l == r) {
        tree[k] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,k+k);
    build(mid+1,r,k+k+1);
    tree[k] = tree[k+k]*tree[k+k+1]%m;
}
void mul(int l,int r,int k,int loc,LL val) {
    if (l == r && l == loc) {
        tree[k] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (loc <= mid) mul(l,mid,k+k,loc,val);
    else mul(mid+1,r,k+k+1,loc,val);
    tree[k] = tree[k+k]*tree[k+k+1]%m;
    //cout << l << " " << r  << " " << tree[k] << endl;
}
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        printf("Case #%d:\n",ca);
        scanf("%d%lld",&n,&m);
        build(1,n,1);
        long long x,y,ans;
        for (int i = 1;i <= n; i++) {
            scanf("%lld%lld",&x,&y);
            if (x == 1) mul(1,n,1,i,y);
            else mul(1,n,1,(int)y,1);
            printf("%lld\n",tree[1]);
        }
    }
	return 0;
}


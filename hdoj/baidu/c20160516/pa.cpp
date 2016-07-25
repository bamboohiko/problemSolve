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
const int mod = 9973;
char st[100100];
int t[maxn*4];
void build(int l,int r,int k) {
    if (l == r) {
        t[k] = st[l] - 28;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,k<<1);
    build(mid+1,r,k<<1|1);
    t[k] = t[k<<1]*t[k<<1|1]%mod;
}
int query(int l,int r,int k,int x,int y) {
    if (x <= l && r <= y) {
        return t[k];
    }
    int mid = (l + r) >> 1,a1 = 1,a2 = 1;
    if (x <= mid) a1 = query(l,mid,k<<1,x,y);
    if (y > mid) a2 = query(mid+1,r,k<<1|1,x,y);
    return a1*a2%mod;
}
int main() {
    int q;
    while (scanf("%d",&q) != EOF) {
        st[0] = ' ';
        scanf("%s",st+1);
        int n = strlen(st)-1;
        //cout << n << endl;
        build(1,n,1);
        int x,y;
        while (q--) {
            scanf("%d%d",&x,&y);
            printf("%d\n",query(1,n,1,x,y));
        }
    }
	return 0;
}

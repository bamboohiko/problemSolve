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
map<int,int> mp;
int updata(int k,int pos,int val) {
    int
}
int main() {
    int n,q;
    scanf("%d",&n);
    int tot = 0;
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    T[n+1] = 1;
    for (int i = n;i >= 1; i--) {
        if (!mp.count(a[i])) T[i] = updata(T[i+1],i,1);
        else {
            int tmp = updata(T[i+1],mp[a[i]],-1);
            T[i] = updata(tmp,i,1);
        }
        mp[a[i]] = i;
    }
    scanf("%d",&q);
    int l,r;
    while (q--) {
        scanf("%d%d",&l,&r);
        printf("%d\n",query(T[l],r));
    }
	return 0;
}

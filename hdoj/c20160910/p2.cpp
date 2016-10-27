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
int a[100100],st[100100][20];
int main() {
    int t;
    int n,q;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            //a[i] = rand()+1;
            st[i][0] = a[i];
        }
        for (int j = 1;(1 << j) <= n; j++)
            for (int i = 1;i + (1<<j)-1 <= n; i++)
                st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        int l,r;
        scanf("%d",&q);
        while (q--) {
            scanf("%d%d",&l,&r);
            int ans = a[l++];
            while (l <= r) {
                int k = (int)(log(r-l+1.0) / log(2.0));
                if (min(st[l][k], st[r-(1<<k)+1][k]) > ans) break;
                int u = l,v = r;
                while (k >= 0) {
                    //cout << u << " " << v << endl;
                    if (st[u][k] <= ans) v = u + (1<<k)-1;
                    else u = v - (1<<k)+1;
                    k--;
                }
                //cout << u << " " << v << endl;
                //cout << ans <<  " "  << a[u] << endl;
                ans %= a[u];
                l = u+1;
            }
            printf("%d\n",ans);
        }
    }
	return 0;
}

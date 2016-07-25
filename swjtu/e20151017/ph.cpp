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
string a[10010],b[10010];
int tree[10010],n,m;
char st[30];
int query(int k) {
    int ans = 0;
    for ( ;k > 0;k -= k&(-k)) ans += tree[k];
    return ans;
}
void updata(int k,int d) {
    for ( ;k <= m;k += k&(-k)) tree[k] += d;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(tree,0,sizeof(tree));
        scanf("%d%*c",&n);
        for (int i = 0;i < n; i++) {
            scanf("%s",st);
            a[i] = b[i] = st;
            reverse(b[i].begin(),b[i].end());
        }
        sort(a,a+n);
        sort(b,b+n);
        m = unique(b,b+n) - b;
        int ans = 0;
        for (int i = 0;i < n; i++) {
            reverse(a[i].begin(),a[i].end());
            int k = lower_bound(b,b+m,a[i]) - b + 1;
            //cout << a[i] << " " << k << endl;
            ans += query(m) - query(k);
            updata(k,1);
        }
        printf("%d\n",ans);
    }
	return 0;
}


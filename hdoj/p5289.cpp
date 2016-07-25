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
const int inf = 1e9 + 7;
int tmax[2*maxn][20],tmin[2*maxn][20],a[maxn];
int n,k;
void build() {
    int m = log2(n) + 1;
    for (int i = 1;i <= n; i++) {
        tmax[i][0] = tmin[i][0] = a[i];
    }
    for (int j = 1;j <= m; j++)
        for (int i = 1;i <= n; i++) {
            tmax[i][j] = max(tmax[i][j-1],tmax[i+(1<<(j-1))][j-1]);
            tmin[i][j] = min(tmin[i][j-1],tmin[i+(1<<(j-1))][j-1]);
        }
}
int query(int x,int y) {
    int j = log2(y-x+1);
    //printf("%d %d %d %d\n",x,y,max(tmax[x][j],tmax[y-(1<<j)+1][j]),min(tmin[x][j],tmin[y-(1<<j)+1][j]));
    return max(tmax[x][j],tmax[y-(1<<j)+1][j]) - min(tmin[x][j],tmin[y-(1<<j)+1][j]);
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&k);
        for (int i = 1;i <= n; i++)  scanf("%d",&a[i]);
        build();
        long long ans = 1;int tmp = 1;
        for (int i = 2;i <= n; i++) {
            while (tmp <= i && query(tmp,i) >= k) tmp++;
            //cout << tmp << endl;
            ans += i-tmp + 1;
        }
        printf("%lld\n",ans);
    }
	return 0;
}

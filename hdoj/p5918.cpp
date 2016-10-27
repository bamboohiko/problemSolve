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
const int maxn = 1e6 + 10;
int a[maxn],b[maxn],nxt[maxn];
int main() {
    int t,n,m,p,ca = 0;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d",&n,&m,&p);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        for (int i = 1;i <= m; i++) scanf("%d",&b[i]);b[m+1] = 0;
        memset(nxt,0,sizeof(nxt));
        nxt[0] = -1;nxt[1] = 0;
        for (int i = 2;i <= m; i++) {
            int j = nxt[i-1];
            while (j >= 0 && b[j+1] != b[i]) j = nxt[j];
            nxt[i] = j+1;
        }
        int ans = 0;
        for (int s = 1;s <= p; s++) {
            int j = 0;
            for (int i = s;i <= n; i += p) {
                while (j >= 0 && b[j+1] != a[i]) j = nxt[j];
                j++;
                if (j == m) ans++;
            }
        }
        printf("Case #%d: %d\n",++ca,ans);
    }
	return 0;
}
